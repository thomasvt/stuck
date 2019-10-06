#include "ShootingState.h"
#include "HeroAnimations.h"
#include <Hero.h>
#include <Vector.h>
#include <HeroFsm.h>
#include <Game.h>

namespace actors
{
	namespace hero {

		constexpr int max_aim_angle = 14;
		constexpr int min_shot_duration = 20; // frames

		void ShootingState::update(Hero& hero)
		{
			hero.state_data_++;
			if (hero.state_data_ == 255)
				hero.state_data_ = 254;

			if (hero.aim_state_ == Hero::aim_state::aiming)
			{
				if (hero.aim_throttle_ == Hero::direction::up && hero.aim_angle_ < (max_aim_angle << 1))
					hero.aim_angle_++;
				else if (hero.aim_throttle_ == Hero::direction::down && hero.aim_angle_ > 0)
					hero.aim_angle_--;
				return;
			}

			if (hero.aim_state_ == Hero::aim_state::releasing_arrow && hero.state_data_ >= animations::hero::spawn_arrow_time) // not natural to shoot before animation "shoots", but the arrow needs to depart quickly for better hero-control feel
			{
				const auto location = VectorI(hero.rigid_body.location.x, hero.rigid_body.location.y + 2);
				Game::scene.shoot_arrow(location, hero.get_aim_velocity(false));
				hero.aim_state_ = Hero::aim_state::arrow_gone;
			}
			if (hero.state_data_ >= min_shot_duration)
			{
				const auto next_state = hero.rigid_body.is_on_floor()
					? HeroFsm::hero_state::on_floor :
					hero.rigid_body.is_on_ladder() ? HeroFsm::hero_state::on_ladder : HeroFsm::hero_state::in_air;
				hero.fsm_.change_state(next_state);
				hero.aim_state_ = Hero::aim_state::ready; // only after min_shot_duration we are ready for another shot
			}
		}

		void ShootingState::on_enter(Hero& hero)
		{
			hero.set_throttle(Hero::direction::none);
			if (hero.rigid_body.is_on_floor() || hero.rigid_body.is_on_ladder()) // stop to shoot, in air, keep last x inertia, stopping midair would be unnatural
			{
				hero.rigid_body.set_velocity8_x(0);
				hero.rigid_body.set_velocity8_y(0);
			}
			hero.state_data_ = 0;
			hero.animation_player_.set_animation(&animations::hero::shoot);
		}

		void ShootingState::on_exit(Hero& hero)
		{
			hero.aim_state_ = Hero::aim_state::ready;
		}
	}
}
