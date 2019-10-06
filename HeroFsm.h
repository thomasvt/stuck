#pragma once
#include "HeroState.h"
#include "OnFloorState.h"
#include "InAirState.h"
#include "OnLadderState.h"
#include "TeleportState.h"
#include "SpawnState.h"
#include "ShootingState.h"

namespace actors
{
	namespace  hero
	{
		class Hero;

		class HeroFsm
		{
		public:
			enum class hero_state { none, on_floor, in_air, on_ladder, teleporting_out, teleporting_in, shooting };
		private:
			Hero* hero_ptr_ = nullptr;
			OnFloorState on_floor_state_ = OnFloorState();
			InAirState in_air_state_ = InAirState();
			OnLadderState on_ladder_state_ = OnLadderState();
			TeleportState teleport_state_ = TeleportState();
			SpawnState spawn_state_ = SpawnState();
			ShootingState shooting_state = ShootingState();
			hero_state current_state_ = hero_state::none;
			HeroState* current_state_ptr_ = nullptr;
		public:
			explicit HeroFsm(Hero* hero_ptr) { hero_ptr_ = hero_ptr; }
			// activates the new state unless we are already in that state.
			void change_state(hero_state state);
			void update() const;
			hero_state get_state() const;
		};
	}
}
