#include "GoblinDefinition.h"
#include <GoblinAnimations.h>
#include <Enemy.h>
#include "CollisionDetector.h"
#include <TileGrid.h>
#include <Game.h>
#include <Vector.h>
#include <hero.h>

namespace actors
{
	const Gamebuino_Meta::Sound_FX die_sound[] = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,-6,6,60,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,-6,6,63,20},
	};

	constexpr int distance_from_edge = 6;
	constexpr int attack_distance = 25;
	constexpr int chase_distance_x = 5 << tile_size_pow2;
	constexpr int chase_distance_y = 1 << tile_size_pow2;
	constexpr int attack_damage = 10;

	GoblinDefinition GoblinDefinition::instance = GoblinDefinition();

	void GoblinDefinition::initialize(Enemy& enemy) const
	{
		SerialUSB.println("init");
		enemy.set_health(goblin_health);
		switch_state(enemy, EnemyState::patrol);
	}

	// patrol state -------------

	void GoblinDefinition::patrol_init(Enemy& enemy) const
	{
		SerialUSB.println("patrol init");
		enemy.animation_player.set_animation(&animations::goblin::walk);
		enemy.set_update_interval(2);
		enemy.timer = random(100) + 100;
	}

	void GoblinDefinition::patrol_update(Enemy& enemy) const
	{
		// check for player in reach
		if (Game::scene.hero.is_detectable())
		{
			const auto distance = enemy.location.to_vector_i().get_distance(Game::scene.hero.get_location());
			const auto manhattan_distance = distance.x + distance.y;
			if (distance.x <= chase_distance_x && distance.y <= chase_distance_y)
			{
				switch_state(enemy, EnemyState::chase);
				return;
			}
			if (manhattan_distance <= attack_distance)
			{
				switch_state(enemy, EnemyState::attack);
				return;
			}
		}

		enemy.timer--;
		if (enemy.animation_player.animation_ptr == &animations::goblin::idle)
		{
			if (enemy.timer == 0)
			{
				if (random(2) == 0)
					enemy.animation_player.set_flip(!enemy.animation_player.get_flip());
				enemy.animation_player.set_animation(&animations::goblin::walk);
				enemy.timer = random(100) + 100;
			}
		}
		else
		{
			if (enemy.timer == 0)
			{
				enemy.animation_player.set_animation(&animations::goblin::idle);
				enemy.timer = random(35) + 20;
			}
			else
			{
				// patrol movement:
				if (enemy.animation_player.get_flip()) // moving left
				{
					enemy.location.x--;

					// check if we need to turn
					const auto next_tile_location = VectorI(enemy.location.x - distance_from_edge, enemy.location.y);
					if (!is_tile_walkable(next_tile_location)) // run out of floor?
						enemy.animation_player.set_flip(false);
				}
				else // moving right
				{
					enemy.location.x++;

					// check if we need to turn
					const auto next_tile_location = VectorI(enemy.location.x + distance_from_edge, enemy.location.y);
					if (!is_tile_walkable(next_tile_location)) // run out of floor?
						enemy.animation_player.set_flip(true);
				}
			}
		}
	}

	// attack state -------------

	void GoblinDefinition::attack_init(Enemy& enemy) const
	{
		enemy.animation_player.set_animation(&animations::goblin::attack);
		enemy.set_update_interval(1);
		enemy.timer = 0;
	}

	void GoblinDefinition::attack_update(Enemy& enemy) const
	{
		if (Game::scene.hero.is_dead())
		{
			switch_state(enemy, EnemyState::patrol);
			return;
		}
		look_at_hero(enemy);
		enemy.timer++;
		if (enemy.animation_player.animation_ptr == &animations::goblin::attack)
		{
			const auto animation_end_time = animations::goblin::attack.get_animation_duration();
			const auto mid_animation_time = animation_end_time >> 1;

			if (enemy.timer == mid_animation_time) // hit hero halfway the attack animation
			{
				const auto distance = enemy.location.to_vector_i().get_distance(Game::scene.hero.get_location());
				const auto manhattan_distance = distance.x + distance.y;
				if (manhattan_distance <= attack_distance) // hero can have escaped melee range while goblin swings
				{
					Game::scene.hero.hit(attack_damage);
				}
			}
			else if (enemy.timer == animation_end_time) // wait for end of attack animation
			{
				enemy.timer = 0;
				enemy.animation_player.set_animation(&animations::goblin::idle);
			}
		}
		else if (enemy.animation_player.animation_ptr == &animations::goblin::idle)
		{
			if (enemy.timer == 25)
			{
				enemy.timer = 0;
				enemy.animation_player.set_animation(&animations::goblin::attack);

				// change state? we only do this at the end of a attack+pause, so this doesnt get interrupted, as it is physically more correct that the attack move has to finish.
				const auto distance = enemy.location.to_vector_i().get_distance(Game::scene.hero.get_location());
				const auto manhattan_distance = distance.x + distance.y;
				if (manhattan_distance > attack_distance)
				{
					switch_state(enemy, EnemyState::chase);
					return;
				}
			}
		}
	}

	// chase state ------------

	void GoblinDefinition::chase_init(Enemy& enemy) const
	{
		enemy.animation_player.set_animation(&animations::goblin::walk);
		enemy.set_update_interval(1); // double speed of walk state
	}

	void GoblinDefinition::chase_update(Enemy& enemy) const
	{
		if (Game::scene.hero.is_dead())
		{
			switch_state(enemy, EnemyState::patrol);
			return;
		}

		// change state?
		const auto distance = enemy.location.to_vector_i().get_distance(Game::scene.hero.get_location());
		const auto manhattan_distance = distance.x + distance.y;
		if (distance.x > chase_distance_x || distance.y > chase_distance_y)
		{
			switch_state(enemy, EnemyState::patrol);
			return;
		}
		if (manhattan_distance <= attack_distance)
		{
			switch_state(enemy, EnemyState::attack);
			return;
		}

		look_at_hero(enemy);

		// chase movement:
		if (enemy.animation_player.get_flip()) // moving left
		{
			const auto next_tile_location = VectorI(enemy.location.x - distance_from_edge, enemy.location.y);
			if (is_tile_walkable(next_tile_location))
			{
				enemy.animation_player.set_animation(&animations::goblin::walk);
				enemy.location.x--;
			}
			else
			{
				enemy.animation_player.set_animation(&animations::goblin::idle);
			}
		}
		else // moving right
		{
			const auto next_tile_location = VectorI(enemy.location.x + distance_from_edge, enemy.location.y);
			if (is_tile_walkable(next_tile_location))
			{
				enemy.animation_player.set_animation(&animations::goblin::walk);
				enemy.location.x++;
			}
			else
			{
				enemy.animation_player.set_animation(&animations::goblin::idle);
			}
		}
	}


	// Die state

	void GoblinDefinition::die_init(Enemy& enemy)
	{
		enemy.animation_player.set_animation(&animations::goblin::die);
	}

	// FSM

	void GoblinDefinition::switch_state(Enemy& enemy, EnemyState state) const
	{
		if (state == enemy.state)
			return;
		enemy.set_state(state);
		switch (state)
		{
		case EnemyState::patrol:
			patrol_init(enemy);
			break;
		case EnemyState::attack:
			attack_init(enemy);
			break;
		case EnemyState::chase:
			chase_init(enemy);
			break;
		case EnemyState::die:
			die_init(enemy);
			break;
		}
	}

	void GoblinDefinition::update(Enemy& enemy) const
	{
		switch (enemy.state)
		{
		case EnemyState::patrol:
			patrol_update(enemy);
			break;
		case EnemyState::attack:
			attack_update(enemy);
			break;
		case EnemyState::chase:
			chase_update(enemy);
			break;
		case EnemyState::die:
			// do nothing
			break;
		}
	}

	void GoblinDefinition::die(Enemy& enemy, const bool silent) const
	{
		if (!silent)
			gb.sound.fx(die_sound);
		switch_state(enemy, EnemyState::die);
		if (silent)
			enemy.animation_player.to_last_frame();
	}

	// utility members

	inline bool GoblinDefinition::is_tile_walkable(const VectorI& location)
	{
		const auto ground = VectorI(location.x, location.y + tile_size);
		return !CollisionDetector::is_spikes(TileGrid::to_grid_coords(location)) && !CollisionDetector::is_obstacle(location) && !CollisionDetector::is_obstacle(VectorI(location.x, location.y-tile_size)) && CollisionDetector::is_obstacle(ground);
	}

	inline void GoblinDefinition::look_at_hero(Enemy& enemy)
	{
		enemy.animation_player.set_flip(Game::scene.hero.get_location().x < enemy.location.x);
	}
}
