#pragma once
#include "EnemyDefinition.h"
#include <Gamebuino-Meta.h>

struct VectorI;

namespace actors {

	constexpr uint8_t imp_health = 3;

	enum class EnemyState : char;
	class Enemy;

	class ImpDefinition : public EnemyDefinition
	{
	public:
		static ImpDefinition instance;

		void initialize(Enemy& enemy) const override;
		void patrol_init(Enemy& enemy) const;
		void die_init(Enemy& enemy) const;
		void attack_init(Enemy& enemy) const;
		void switch_state(Enemy& enemy, EnemyState state) const;
		void patrol_update(Enemy& enemy) const;
		void attack_update(Enemy& enemy) const;
		void update(Enemy& enemy) const override;
		void die(Enemy& enemy, const bool silent = false) const override;
		bool is_tile_walkable(const VectorI& location) const;
		void look_at_hero(Enemy& enemy) const;
	};

}
