#pragma once
#include <EnemyDefinition.h>
#include <Vector.h>

namespace actors {

	constexpr uint8_t goblin_health = 4;

	enum class EnemyState : char;
	class Enemy;

	class GoblinDefinition : public EnemyDefinition
	{
		void patrol_init(Enemy& enemy) const;
		void patrol_update(Enemy& enemy) const;
		void attack_init(Enemy& enemy) const;
		void attack_update(Enemy& enemy) const;
		void chase_init(Enemy& enemy) const;
		void chase_update(Enemy& enemy) const;
		static void die_init(Enemy& enemy);

		static inline bool is_tile_walkable(const VectorI& location);
		static inline void look_at_hero(Enemy& enemy);
		
		void switch_state(Enemy& enemy, EnemyState state) const;
	public:
		static GoblinDefinition instance;
		explicit GoblinDefinition() = default;

		void initialize(Enemy& enemy) const override;
		void update(Enemy& enemy) const override;
		// no_die_animation is for the LevelLoader that must be able to spawn corpses.
		void die(Enemy& enemy, const bool silent = false) const override;
	};

}
