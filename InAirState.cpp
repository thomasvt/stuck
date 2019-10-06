#include <InAirState.h>
#include <Hero.h>
#include "HeroAnimations.h"

namespace actors
{
	namespace  hero
	{
		void InAirState::update(Hero& hero)
		{
			if (hero.rigid_body.is_on_floor())
				hero.fsm_.change_state(HeroFsm::hero_state::on_floor);
			if (hero.rigid_body.is_on_ladder() && !hero.rigid_body.is_going_up())
				hero.fsm_.change_state(HeroFsm::hero_state::on_ladder);

			const auto throttle8_x = hero.get_throttle8_x();
			hero.rigid_body.set_velocity8_x(throttle8_x); // no inertia, classic feel

			// bit dirty. can only do this because these animations are only 1 frame.
			hero.animation_player_.set_animation(hero.rigid_body.is_going_up() ? &animations::hero::jump : &animations::hero::fall);
		}

		void InAirState::on_enter(Hero& hero)
		{
			hero.rigid_body.is_gravity_enabled = true;
		}

		void InAirState::on_exit(Hero& hero)
		{
		}
	}
}
