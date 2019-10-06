#include <OnFloorState.h>
#include <Hero.h>
#include "HeroAnimations.h"
#include <Game.h>
#include "Time.h"

namespace actors
{
	namespace hero
	{
		const Gamebuino_Meta::Sound_FX step_sounds[] PROGMEM = {
			{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,48,0,-110,208,1},
			{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,48,0,-110,190,1},
			{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,48,0,-110,220,1},
			{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,48,0,-110,170,1},
		};

		void OnFloorState::update(Hero& hero)
		{
			if (hero.rigid_body.is_on_ladder() && hero.throttle_ == Hero::direction::up)
				hero.fsm_.change_state(HeroFsm::hero_state::on_ladder); // step on ladder ascending from where we stand
			if (!hero.rigid_body.is_on_floor())
			{
				// step off floor-side horizontally:
				hero.fsm_.change_state(hero.rigid_body.is_on_ladder()
					? HeroFsm::hero_state::on_ladder  // start using ladder if there is one
					: HeroFsm::hero_state::in_air);
			}

			const auto throttle8_x = hero.get_throttle8_x();
			if (throttle8_x != 0 && gametime::framecount % 7 == 0 && !gb.sound.is_fx_playing())
				gb.sound.fx(step_sounds[gametime::framecount & 0b11]); // step sounds

			hero.rigid_body.set_velocity8_x(throttle8_x); // no inertia, classic feel

			// update animation
			hero.animation_player_.set_animation(throttle8_x == 0 ? &animations::hero::idle : &animations::hero::run);
		}

		void OnFloorState::on_enter(Hero& hero)
		{
			if (!gb.sound.is_fx_playing())
				gb.sound.fx(step_sounds[0]); // land sound
			hero.rigid_body.is_gravity_enabled = true;
			hero.reset_air_jumps();
		}

		void OnFloorState::on_exit(Hero& hero)
		{
		}
	}
}
