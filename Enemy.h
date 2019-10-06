#pragma once
#include <vector.h>
#include <Rectangle.h>
#include "EnemyDefinition.h"
#include <AnimationPlayer.h>

class Sprite;
class Camera;
struct Rectangle;

namespace actors {

	enum class EnemyState : char
	{
		none, // if patrol is 0-value, the init code for patrol will not execute at game start (because current state (0) == new state (0) -> dont execute state switch code )
		patrol,
		chase,
		attack,
		die
	};

	class Enemy
	{
	public:
		const EnemyDefinition* enemy_definition_ptr_ = nullptr;
		AnimationPlayer animation_player = AnimationPlayer();
		Vector16 location = Vector16();
		uint8_t settings_ = 0; // bit layout: (??ii?hhh: (i)nterval, (h)ealth)
		EnemyState state = EnemyState::none;
		uint8_t timer = 0;


		void update();
		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
		void set_definition(const EnemyDefinition* definition);
		void set_already_dead();
		void hit(int hitpoints);

		int get_health() const
		{
			return settings_ & 0b111;
		}

		void set_health(const int health)
		{
			settings_ = (settings_ & 0b11111000) | (health & 0b111);
		}

		int get_update_interval() const
		{
			return (settings_ & 0b110000) >> 4;
		}

		void set_update_interval(const int interval)
		{
			settings_ = (settings_ & 0b11001111) | ((interval & 0b11) << 4);
		}

		void set_state(const EnemyState state)
		{
			this->state = state;
		}
	};

}
