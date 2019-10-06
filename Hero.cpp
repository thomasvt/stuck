#include <Camera.h>
#include "HeroAnimations.h"
#include "Hero.h"
#include "Physics.h"
#include <Game.h>
#include "CollisionDetector.h"
#include <GameState.h>

namespace actors
{
	namespace hero
	{
		constexpr int potion_hitpoints = 50;

		const Gamebuino_Meta::Sound_FX hit_sound[] PROGMEM = { {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,-6,6,25,11} };

		const Gamebuino_Meta::Sound_FX die_sound[] PROGMEM = {
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,-3,45,13,12},
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,46,28,12},
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,45,50,15},
		};

		const Gamebuino_Meta::Sound_FX heal_sound[] PROGMEM = {
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,-19,0,50,5},
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,254,-14,0,25,8},
		};

		const Gamebuino_Meta::Sound_FX coin_sound[] PROGMEM = {
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,50,2},
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,20,2},
			{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,0,50,2},
		};

		Vector8 aim_velocities[] { // used for both up and down aiming
			Vector8(7, 0), // horizontal
			Vector8(7, 1),
			Vector8(7, 1),
			Vector8(6, 2),
			Vector8(6, 3),
			Vector8(6, 3),
			Vector8(6, 4),
			Vector8(5, 4),
			Vector8(5, 5),
			Vector8(5, 6),
			Vector8(4, 6),
			Vector8(4, 6),
			Vector8(3, 6),
			Vector8(2, 6),
			Vector8(1, 7),
			Vector8(1, 7), // vertical
		};

		Vector8 crosshair_locations[]{ // used for both up and down aiming
			Vector8(20, 0), // horizontal
			Vector8(20, 2),
			Vector8(20, 4),
			Vector8(19, 6),
			Vector8(18, 8),
			Vector8(17, 10),
			Vector8(16, 11),
			Vector8(15, 13),
			Vector8(14, 14),
			Vector8(13, 15),
			Vector8(11, 16),
			Vector8(10, 17),
			Vector8(8, 18),
			Vector8(6, 19),
			Vector8(4, 20),
			Vector8(2, 20), // vertical
		};

		void Hero::initialize(const VectorI location)
		{
			this->rigid_body.set_location(location);
			fsm_.change_state(HeroFsm::hero_state::teleporting_in);
			reset_air_jumps(); // ensure the correct amount is loaded from persisted gamestate.
		}

		bool Hero::is_detectable() const
		{
			const auto state = get_state();
			return animation_player_.animation_ptr != &animations::hero::dead && state != HeroFsm::hero_state::teleporting_in && state != HeroFsm::hero_state::teleporting_out;
		}

		void Hero::catapult()
		{
			rigid_body.set_velocity8_y(-catapult_impulse8);
			reset_air_jumps();
		}

		void Hero::heal(const int hitpoints)
		{
			Game::state.add_health(hitpoints);
		}

		void Hero::check_pickup() const
		{
			const auto location_grid = TileGrid::to_grid_coords(rigid_body.location);
			if (Game::scene.tile_grid.is_coin(location_grid))
			{
				Game::scene.spawn_sparkles(VectorI((location_grid.x << tile_size_pow2) + 8, (location_grid.y << tile_size_pow2) + 8));
				Game::scene.tile_grid.remove_pickup(location_grid);
				gb.sound.fx(coin_sound);
				Game::scene.coin_counter.value--;
			}
			else if (Game::scene.tile_grid.is_potion(location_grid) && Game::state.health < max_health)
			{
				Game::scene.spawn_sparkles(VectorI((location_grid.x << tile_size_pow2) + 8, (location_grid.y << tile_size_pow2) + 8));
				heal(potion_hitpoints);
				Game::scene.tile_grid.remove_pickup(location_grid);
				gb.sound.fx(heal_sound);
			}
		}

		void Hero::check_spikes_death()
		{
			if (cheat)
				return;
			// we subtract 8 from y because spikes are only half tile height, only die when actually touching spike graphics
			const auto left_grid = VectorI(rigid_body.particles_bottom[0].location.x >> tile_size_pow2, (rigid_body.particles_bottom[0].location.y - 8) >> tile_size_pow2);
			const auto right_grid = VectorI(rigid_body.particles_bottom[1].location.x >> tile_size_pow2, (rigid_body.particles_bottom[1].location.y - 8) >> tile_size_pow2);
			if (CollisionDetector::is_spikes(left_grid) || CollisionDetector::is_spikes(right_grid))
				die();
		}

		bool Hero::is_dead() const
		{
			return animation_player_.animation_ptr == &animations::hero::dead;
		}

		void Hero::update()
		{
			Physics::update(rigid_body);
			check_spikes_death();
			check_pickup();

			if (!is_dead())
			{
				animation_player_.set_flash(false);
				fsm_.update();
			}
		}

		HeroFsm::hero_state Hero::get_state() const
		{
			return fsm_.get_state();
		}

		void Hero::render(const uint8_t& layer, const Rectangle& part, const int anchor_x, const int anchor_y, uint16_t* const slice_buffer) const
		{
			animation_player_.render(part, anchor_x, anchor_y, slice_buffer);
		}

		void Hero::die()
		{
			if (is_dead())
				return;
			rigid_body.is_gravity_enabled = true; // ensure player\s tomb falls when killed during non gravity state (ladder, teleport)
			Game::state.health = 0;
			gb.sound.fx(die_sound);
			animation_player_.set_animation(&animations::hero::dead);
			animation_player_.set_flip(false); // prevent to be mirrored.
			animation_player_.set_flash(false); // prevent staying rendered as flashing color.
			rigid_body.set_velocity8_x(0);
			rigid_body.set_velocity8_y(-jump_impulse8);
			Game::scene.show_message();
		}

		void Hero::hit(int hitpoints)
		{
			if (cheat)
				return;
			if (is_dead() && get_state() != HeroFsm::hero_state::teleporting_in && get_state() != HeroFsm::hero_state::teleporting_out)
				return;

			animation_player_.set_flash(true);
			gb.sound.fx(hit_sound);
			Game::state.health -= hitpoints;
			if (Game::state.health > 100) // "negative" uint :)
				Game::state.health = 0;
			if (Game::state.health == 0)
				die();
		}

		int Hero::get_throttle8_x() const
		{
			if (throttle_ == direction::left)
				return -speed8;
			if (throttle_ == direction::right)
				return speed8;
			return 0;
		}

		bool Hero::can_jump()
		{
			if (is_dead())
				return false;

			if (rigid_body.is_on_floor() || rigid_body.is_on_ladder()) {
				return true;
			}
			if (air_jumps_remaining_ > 0 || cheat)
			{
				air_jumps_remaining_--;
				return true;
			}
			return false;
		}

		void Hero::jump()
		{
			if (can_jump())
			{
				fsm_.change_state(HeroFsm::hero_state::in_air);
				rigid_body.set_velocity8_y(-jump_impulse8);
			}
		}

		void Hero::teleport(uint8_t target_id)
		{
			if (is_dead())
				return;

			state_data_ = target_id;
			fsm_.change_state(HeroFsm::hero_state::teleporting_out);
		}

		void Hero::set_throttle(direction throttle)
		{
			if (is_dead())
				return;

			// we prevent running into the wall, not justs to make her stop running, but also because collisiondetector has a hard time fixing the physically incorrect forced movement of the character by quite some pixel-distance.
			// (eg. Hero could get stuck when falling along a wall with 1 cell hole in it. The throttle by player would make hero try enter the too small hole, but physics correction would keep pushing hero up as if the bottom hole wall was a floor. 
			// This made her float against the hole, while shaking)
			if (throttle == direction::left && (CollisionDetector::is_obstacle(VectorI(rigid_body.particles_left[0].location.x - 1, rigid_body.particles_left[0].location.y)) 
				|| CollisionDetector::is_obstacle(VectorI(rigid_body.particles_left[1].location.x - 1, rigid_body.particles_left[1].location.y))))
			{
				throttle = direction::none;
			}
			else if (throttle == direction::right && (CollisionDetector::is_obstacle(VectorI(rigid_body.particles_right[0].location.x + 1, rigid_body.particles_right[0].location.y))
				|| CollisionDetector::is_obstacle(VectorI(rigid_body.particles_right[1].location.x + 1, rigid_body.particles_right[1].location.y))))
			{
				throttle = direction::none;
			}
			else if (throttle == direction::left || throttle == direction::right)
			{
				aim_angle_ = 14; // when walking around: reset shooting angle to horizontal -> keep last used angle between shots while standing still.
				if (throttle == direction::left && !animation_player_.get_flip())
				{
					animation_player_.set_flip(true);
					throttle = direction::none; // consume this frame to allow turning around with little or no movement
				}
				else if (throttle == direction::right && animation_player_.get_flip())
				{
					animation_player_.set_flip(false);
					throttle = direction::none;
				}
			}
			this->throttle_ = throttle;
		}

		void Hero::draw_arrow()
		{
			if (is_dead() || fsm_.get_state() != HeroFsm::hero_state::on_floor || aim_state_ != aim_state::ready)
				return;

			aim_state_ = aim_state::aiming;
			fsm_.change_state(HeroFsm::hero_state::shooting);
		}

		bool Hero::is_on_floor() const
		{
			return rigid_body.is_on_floor();
		}

		void Hero::release_arrow()
		{
			if (aim_state_ != aim_state::aiming)
				return;

			aim_state_ = aim_state::releasing_arrow; // signals the shootingstate to release the arrow and end shooting state after animation is done
		}

		void Hero::set_aim_throttle(const direction direction)
		{
			if (aim_state_ != aim_state::aiming)
				return;

			aim_throttle_ = direction;
		}

		VectorI Hero::get_location() const
		{
			return rigid_body.location;
		}

		VectorI Hero::get_aim_velocity(const bool crosshair) const
		{
			const auto is_aiming_down = aim_angle_ < 14;
			const auto velocity_index = is_aiming_down ? 14 - aim_angle_ : aim_angle_ - 14;
			const auto velocity = crosshair ? crosshair_locations[velocity_index] : aim_velocities[velocity_index];
			return { animation_player_.get_flip() ? -velocity.x : velocity.x, (is_aiming_down ? velocity.y : -velocity.y) - 1 }; // -1 compensates the gravity arc a bit
		}

		void Hero::reset_air_jumps()
		{
			air_jumps_remaining_ = Game::state.air_jump_count;
		}

		Rectangle Hero::measure(const Camera& camera) const
		{
			const auto location_screen = camera.to_screen(rigid_body.location);
			return animation_player_.get_cropped_sprite_bounds(location_screen.x, location_screen.y);
		}
	}
}
