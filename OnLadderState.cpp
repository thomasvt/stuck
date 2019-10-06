#include "OnLadderState.h"
#include <Hero.h>
#include "TileGrid.h"
#include "HeroAnimations.h"
#include <Game.h>

namespace actors
{
	namespace hero
	{
		constexpr int ladder_speed8 = 16;

		void OnLadderState::update(Hero& hero)
		{
			if (hero.rigid_body.is_on_floor() && hero.throttle_ == Hero::direction::down)
				hero.fsm_.change_state(HeroFsm::hero_state::on_floor);
			if (!hero.rigid_body.is_on_ladder())
				hero.fsm_.change_state(HeroFsm::hero_state::in_air);

			auto velocity8_y = 0;
			if (hero.throttle_ == Hero::direction::up)
				velocity8_y = -ladder_speed8;
			else if (hero.throttle_ == Hero::direction::down)
				velocity8_y = ladder_speed8;
			hero.rigid_body.set_velocity8_y(velocity8_y);

			if (velocity8_y == 0)
			{
				// allow horizontal strifing on ladder when not ascending/descending
				const auto throttle8_x = hero.get_throttle8_x();
				hero.rigid_body.set_velocity8_x(throttle8_x);
				hero.animation_player_.set_animation(throttle8_x == 0 ? &animations::hero::climb_idle : &animations::hero::run);
			}
			else
			{
				// move hero towards center of ladder while climbing
				const auto offset_x = (hero.rigid_body.location.x % tile_size) - 1;
				if (offset_x < half_tile_size)
					hero.rigid_body.set_location(VectorI(hero.rigid_body.location.x + 1, hero.rigid_body.location.y));
				else if (offset_x > half_tile_size)
					hero.rigid_body.set_location(VectorI(hero.rigid_body.location.x - 1, hero.rigid_body.location.y));

				hero.animation_player_.set_animation(&animations::hero::climb);
			}
		}

		void OnLadderState::on_enter(Hero& hero)
		{
			hero.rigid_body.is_gravity_enabled = false;
			hero.rigid_body.set_velocity8_y(0);
			hero.reset_air_jumps();
		}

		void OnLadderState::on_exit(Hero& hero)
		{
		}
	}
}
