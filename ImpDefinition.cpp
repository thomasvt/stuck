#include "ImpDefinition.h"
#include <Enemy.h>
#include "ImpAnimations.h"
#include <TileGrid.h>
#include <Game.h>
#include "CollisionDetector.h"
#include <Vector.h>

namespace actors
{
	constexpr int attack_distance_x = 8 << tile_size_pow2;
	constexpr int attack_distance_y = 3 << tile_size_pow2;
	constexpr int distance_from_edge = 6;

	const Gamebuino_Meta::Sound_FX die_sound[] = {
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,1,0,6,0,48,5},
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,255,-2,0,16,39},
	};

	ImpDefinition ImpDefinition::instance = ImpDefinition();

	void ImpDefinition::initialize(Enemy& enemy) const
	{
		enemy.set_health(imp_health);
		switch_state(enemy, EnemyState::patrol);
	}

	// Patrol -----------

	void ImpDefinition::patrol_init(Enemy& enemy) const
	{
		enemy.animation_player.set_animation(&animations::imp::walk);
		enemy.set_update_interval(3);
		enemy.timer = random(50) + 100;
	}


	void ImpDefinition::patrol_update(Enemy& enemy) const
	{
		if (Game::scene.hero.is_detectable())
		{
			// check for player within attack range
			const auto distance = enemy.location.to_vector_i().get_distance(Game::scene.hero.get_location());
			const auto manhattan_distance = distance.x + distance.y;
			if (distance.x <= attack_distance_x && distance.y <= attack_distance_y)
			{
				switch_state(enemy, EnemyState::attack);
				return;
			}
		}

		enemy.timer--;
		if (enemy.animation_player.animation_ptr == &animations::imp::idle)
		{
			if (enemy.timer == 0)
			{
				if (random(2) == 0)
					enemy.animation_player.set_flip(!enemy.animation_player.get_flip());
				enemy.animation_player.set_animation(&animations::imp::walk);
				enemy.timer = random(100) + 100;
			}
		}
		else
		{
			if (enemy.timer == 0)
			{
				enemy.animation_player.set_animation(&animations::imp::idle);
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

	// Attack -----------

	void ImpDefinition::attack_init(Enemy& enemy) const
	{
		enemy.animation_player.set_animation(&animations::imp::attack);
		enemy.set_update_interval(1);
		enemy.timer = 0;
	}

	void ImpDefinition::attack_update(Enemy& enemy) const
	{
		if (Game::scene.hero.is_dead())
		{
			switch_state(enemy, EnemyState::patrol);
			return;
		}
		look_at_hero(enemy);
		enemy.timer++;

		if (enemy.animation_player.animation_ptr == &animations::imp::attack)
		{
			const auto animation_end_time = animations::imp::attack.get_animation_duration();
			const auto mid_animation_time = animation_end_time >> 1;
			
			if (enemy.timer == mid_animation_time) 
			{
				// launch fireball halfway animation
				Game::scene.shoot_fireball(enemy.location, enemy.animation_player.get_flip() ? direction::left : direction::right);
			}
			else if (enemy.timer == animation_end_time)
			{
				enemy.timer = 0;
				enemy.animation_player.set_animation(&animations::imp::idle);
			}
		}
		else if (enemy.animation_player.animation_ptr == &animations::imp::idle)
		{
			if (enemy.timer == 50)
			{
				enemy.timer = 0;
				enemy.animation_player.set_animation(&animations::imp::attack);

				// change state? we only do this at the end of a attack+pause, so this doesnt get interrupted, as it is physically more correct that the attack gesture has to finish.
				const auto distance = enemy.location.to_vector_i().get_distance(Game::scene.hero.get_location());
				const auto manhattan_distance = distance.x + distance.y;
				if (distance.x > attack_distance_x || distance.y > attack_distance_y)
				{
					switch_state(enemy, EnemyState::patrol);
					return;
				}
			}
		}
	}

	// Die --------------

	void ImpDefinition::die_init(Enemy& enemy) const
	{
		enemy.animation_player.set_animation(&animations::imp::die);
	}

	// FSM

	void ImpDefinition::switch_state(Enemy& enemy, EnemyState state) const
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
		case EnemyState::die:
			die_init(enemy);
			break;
		}
	}


	void ImpDefinition::update(Enemy& enemy) const
	{
		switch (enemy.state)
		{
		case EnemyState::patrol:
			patrol_update(enemy);
			break;
		case EnemyState::attack:
			attack_update(enemy);
			break;
		case EnemyState::die:
			// do nothing
			break;
		}
	}

	void ImpDefinition::die(Enemy& enemy, const bool silent) const
	{
		if (!silent)
			gb.sound.fx(die_sound);
		switch_state(enemy, EnemyState::die);
		if (silent)
			enemy.animation_player.to_last_frame();
	}

	inline bool ImpDefinition::is_tile_walkable(const VectorI& location) const
	{
		const auto ground = VectorI(location.x, location.y + tile_size);
		return !CollisionDetector::is_spikes(TileGrid::to_grid_coords(location)) && !CollisionDetector::is_obstacle(VectorI(location.x, location.y - tile_size)) && !CollisionDetector::is_obstacle(location) && CollisionDetector::is_obstacle(ground);
	}

	inline void ImpDefinition::look_at_hero(Enemy& enemy) const
	{
		enemy.animation_player.set_flip(Game::scene.hero.get_location().x < enemy.location.x);
	}
}
