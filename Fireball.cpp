#include "Fireball.h"
#include <Rectangle.h>
#include "FireBallAnimation.h"
#include <Camera.h>
#include "CollisionDetector.h"
#include <Game.h>

namespace actors
{
	constexpr uint8_t fireball_speed = 4;
	constexpr uint8_t fireball_damage = 20;

	const Gamebuino_Meta::Sound_FX hit_wall_sound[] PROGMEM = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,0,636,2},
	};

	AnimationPlayer Fireball::animation_player_ = AnimationPlayer();

	Fireball::Fireball()
	{
		animation_player_.set_animation(&animations::fireball_right);
		location_ = Vector16();
		direction_ = direction::left;
	}

	Fireball::Fireball(const Vector16& location, const direction direction) : location_(location), direction_(direction)
	{
	}

	void Fireball::update()
	{
		// hit wall?
		const auto locationi = location_.to_vector_i();
		if (CollisionDetector::is_obstacle(locationi))
		{
			const auto distance = Game::scene.camera.location.to_vector_i().get_manhattan_distance(VectorI(location_.x, location_.y));
			if (distance < 170)
			{
				gb.sound.fx(hit_wall_sound); // silent if too far from camera
			}
			Game::scene.destroy_fireball(this);
			return;
		}

		const auto hero_distance = Game::scene.hero.get_location().get_distance(locationi);
		if (hero_distance.x <= 10 && hero_distance.y <= 13)
		{
			Game::scene.hero.hit(fireball_damage);
			Game::scene.destroy_fireball(this);
			return;
		}

		switch (direction_)
		{
		case direction::up:
			location_.y -= fireball_speed;
			break;
		case direction::left:
			location_.x -= fireball_speed;
			break;
		case direction::right:
			location_.x += fireball_speed;
			break;
		}
	}

	Rectangle Fireball::measure(const Camera& camera) const
	{
		const auto position_screen = camera.to_screen(location_.to_vector_i());
		switch (direction_)
		{
		case direction::up:
			animation_player_.set_animation(&animations::fireball_up, false);
			animation_player_.set_flip(false);
			break;
		case direction::left:
			animation_player_.set_animation(&animations::fireball_right, false);
			animation_player_.set_flip(true);
			break;
		case direction::right:
			animation_player_.set_animation(&animations::fireball_right, false);
			animation_player_.set_flip(false);
			break;
		}
		
		return animation_player_.get_cropped_sprite_bounds(position_screen.x, position_screen.y);
	}

	void Fireball::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		animation_player_.render(part, x, y, slice_buffer);
	}
}
