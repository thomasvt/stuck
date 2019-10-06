#include "SpawnState.h"
#include <HeroFsm.h>
#include <Hero.h>
#include "HeroAnimations.h"
#include "Time.h"

const Gamebuino_Meta::Sound_FX teleport_sound[] = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,18,0,56,21},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,168,-4,0,56,30},
};

void actors::hero::SpawnState::on_enter(Hero& hero)
{
	start_frame_ = gametime::framecount;
	hero.animation_player_.set_animation(nullptr);
	hero.rigid_body.is_gravity_enabled = false;
	hero.set_throttle(Hero::direction::none);
	hero.rigid_body.set_velocity8_x(0);
	hero.rigid_body.set_velocity8_y(0);
}

void actors::hero::SpawnState::on_exit(Hero& hero)
{
	hero.rigid_body.is_gravity_enabled = true;
}

void actors::hero::SpawnState::update(Hero& hero)
{
	const auto frame = gametime::framecount - start_frame_;
	if (frame == 15)
	{
		gb.sound.fx(teleport_sound);
		hero.animation_player_.set_animation(&animations::hero::spawn);
	}
	else if (frame == 15 + animations::hero::spawn.get_animation_duration())
	{
		hero.fsm_.change_state(HeroFsm::hero_state::on_floor);
	}
}
