#include "HeroFsm.h"
#include <Debug.h>
#include <Gamebuino-Meta.h>

namespace actors
{
	namespace hero
	{
		const char no_state_msg[] PROGMEM = "No current state to update().";

		void HeroFsm::change_state(const hero_state state)
		{
			if (state == current_state_)
				return;

			if (current_state_ptr_ != nullptr)
				current_state_ptr_->on_exit(*hero_ptr_);

			current_state_ = state;
			switch (state)
			{
				case hero_state::on_floor:
					current_state_ptr_ = &on_floor_state_;
					break;
				case hero_state::in_air:
					current_state_ptr_ = &in_air_state_;
					break;
				case hero_state::on_ladder:
					current_state_ptr_ = &on_ladder_state_;
					break;
				case hero_state::teleporting_out:
					current_state_ptr_ = &teleport_state_;
					break;
				case hero_state::teleporting_in:
					current_state_ptr_ = &spawn_state_;
					break;
				case hero_state::shooting:
					current_state_ptr_ = &shooting_state;
					break;
			}
			
			current_state_ptr_->on_enter(*hero_ptr_);
		}

		void HeroFsm::update() const
		{
			if (current_state_ptr_ == nullptr)
			{
				Debug::throw_fatal(no_state_msg);
				return;
			}
			current_state_ptr_->update(*hero_ptr_);
		}

		HeroFsm::hero_state HeroFsm::get_state() const
		{
			return current_state_;
		}
	}
}
