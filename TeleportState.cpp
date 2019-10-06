#include "TeleportState.h"
#include <Hero.h>
#include <Game.h>
#include "HeroAnimations.h"
#include "Time.h"

namespace actors
{
	namespace hero
	{
		const Gamebuino_Meta::Sound_FX teleport_sound[] = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,18,0,56,21},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,168,-4,0,56,30},
		};

		void TeleportState::update(Hero& hero)
		{
			const auto frame = gametime::framecount - start_frame_;
			if (frame >= 30) // give player a second to see what is going on
			{
				Game::progress_to_spawn_point(hero.state_data_); // state_data is a generic data slot for context specific data. Here, it contains the spawnpoint info, set by the Portal.
			}
		}

		void TeleportState::on_enter(Hero& hero)
		{
			start_frame_ = gametime::framecount;
			gb.sound.fx(teleport_sound);
			hero.animation_player_.set_animation(&animations::hero::teleport);
			hero.rigid_body.is_gravity_enabled = false;
			hero.set_throttle(Hero::direction::none);
			hero.rigid_body.set_velocity8_x(0);
			hero.rigid_body.set_velocity8_y(0);
		}

		void TeleportState::on_exit(Hero& hero)
		{
			hero.rigid_body.is_gravity_enabled = true;
		}
	}
}
