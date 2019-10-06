#pragma once
#include <Sprite.h>
#include "RigidBody.h"
#include "AnimationPlayer.h"
#include "HeroFsm.h"

class Camera;
struct Rectangle;

namespace actors
{
	namespace hero
	{
		// when changing, retest getting into a tunnel of 1 height when falling, jumping up diagonally at a ceiling corner
		static int rigid_body_x[4] = { -6, -4, 4, 6 };
		static int rigid_body_y[4] = { -10, -9, 9, 13 };
		constexpr int speed8 = 30;
		constexpr int jump_impulse8 = 37; // test if these jumps still work: single jump over 2 block, double jump over 4 block
		constexpr int catapult_impulse8 = 90;

		class Hero
		{
		public:
			enum class direction { none, up, right, down, left };
		private:
			enum class aim_state : uint8_t { ready, aiming, releasing_arrow, arrow_gone };
			AnimationPlayer animation_player_ = AnimationPlayer();
			// physics
			byte air_jumps_remaining_ = 0;
			HeroFsm fsm_ = HeroFsm(this);
			direction throttle_ = direction::none;
			uint8_t state_data_; // byte for state to store some data
			aim_state aim_state_ = aim_state::ready;
			uint8_t aim_angle_ = 14; // horizontal aim
			direction aim_throttle_ = direction::none;

			int get_throttle8_x() const;
			void check_spikes_death();

			friend class OnFloorState;
			friend class InAirState;
			friend class OnLadderState;
			friend class TeleportState;
			friend class SpawnState;
			friend class ShootingState;

			friend class Crosshair;
		public:
			RigidBody rigid_body = { rigid_body_x, rigid_body_y }; // todo This is copying values = double memory

			void initialize(VectorI location);
			bool is_detectable() const;
			void catapult();
			static void heal(int hitpoints);
			void check_pickup() const;
			void update();
			HeroFsm::hero_state get_state() const;
			Rectangle measure(const Camera& camera) const;
			void render(const uint8_t& layer, const Rectangle& part, int anchor_x, const int anchor_y, uint16_t* const slice_buffer) const;

			// domain:
			void die();
			bool is_dead() const;
			void hit(int hitpoints);
			bool can_jump();
			void jump();
			void teleport(uint8_t target_id);
			void set_throttle(direction throttle);
			void draw_arrow();
			bool is_on_floor() const;
			void release_arrow();
			void set_aim_throttle(const direction direction);
			VectorI get_location() const;
			VectorI get_aim_velocity(const bool crosshair) const;
			void reset_air_jumps();
		};

	}
}