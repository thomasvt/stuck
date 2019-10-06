#include <GameState.h>
#include <Gamebuino-Meta.h>
#include <Game.h>
#include <Levels.h>

const SaveDefault save_defaults[] = {
	{ 0, SAVETYPE_BLOB, {.ptr = &Game::state}, sizeof(GameState) },
	{ 1, SAVETYPE_BLOB, {.ptr = &Game::state}, sizeof(GameState) },
	{ 2, SAVETYPE_BLOB, {.ptr = &Game::state}, sizeof(GameState) },
	{ 3, SAVETYPE_BLOB, {.ptr = &Game::state}, sizeof(GameState) }
};

GameState::GameState()
{
	gb.save.config(save_defaults, 4);
	inventory = Inventory();
	health = max_health;
	spawn_point = levels::newgame_spawnpoint;
}

void GameState::add_health(const int health)
{
	this->health += health;
	if (this->health > max_health)
		this->health = max_health;
}

void GameState::set_enemy_state(int i, bool is_killed)
{
	const auto level = get_current_level_id();
	auto new_value = (enemies[level] & ~(1 << i));
	if (is_killed)
		new_value |= 1 << i;
	enemies[level] = new_value;
}

void GameState::set_collectible_state(int i, bool is_looted)
{
	const auto level = get_current_level_id();
	const auto byte_index = i >> 3;
	const auto bit_index = i & 0b111;
	auto new_value = (pickups[level][byte_index] & ~(1 << bit_index));
	if (is_looted)
		new_value |= 1 << (i & 0b111);
	pickups[level][byte_index] = new_value;
}

void GameState::set_door_state(int i, bool is_open)
{
	const auto level = get_current_level_id();
	auto new_value = (doors[level] & ~(1 << i));
	if (is_open)
		new_value |= 1 << i;
	doors[level] = new_value;
}

bool GameState::is_enemy_dead(int i)
{
	const auto level = get_current_level_id();
	return enemies[level] & (1 << i);
}

bool GameState::is_collectible_looted(int i)
{
	const auto level = get_current_level_id();
	const auto byte_index = i >> 3;
	const auto bit_index = i & 0b111;
	return pickups[level][byte_index] & (1 << bit_index);
}

bool GameState::is_door_open(int i)
{
	const auto level = get_current_level_id();
	return doors[level] & (1 << i);
}

void GameState::store_current_area_state()
{
	for (auto i = 0; i < Game::scene.enemy_count; i++)
	{
		const auto enemy = Game::scene.enemies[i];
		set_enemy_state(i, enemy.state == actors::EnemyState::die);
	}
	for (auto i = 0; i < Game::scene.door_count; i++)
	{
		const auto door = Game::scene.doors[i];
		set_door_state(i, door.is_open());
	}
	const auto& level = levels::levels[Game::state.get_current_level_id()];
	const auto level_grid_size = level.get_size();
	auto pickup_index = 0;
	for (auto i = 0; i < level_grid_size.x * level_grid_size.y; i++)
	{
		const auto tile = level.terrain_data[i];
		if (tile >= level_pickup && tile < level_pickup + pickup_type_count)
		{
			for (auto j = 0; j < Game::scene.pickup_count; j++) // find gem Actor to see if it's picked up or not
			{
				const auto gem = Game::scene.pickups[j];
				const auto gem_location_i = gem.location_grid_.y * level_grid_size.x + gem.location_grid_.x;
				if (gem_location_i == i)
				{
					set_collectible_state(pickup_index++, gem.is_looted());
					break;
				}
			}
		}
		else if (tile == level_potion || tile == level_coin)
		{
			set_collectible_state(pickup_index++, Game::scene.tile_grid.terrain[i] == 0);
		}
	}
}

void GameState::save(const int save_slot)
{
	gb.save.set(save_slot, this, sizeof(GameState));
}

void GameState::load(const int save_slot)
{
	gb.save.get(save_slot, *this);
}

int GameState::get_current_level_id() const
{
	return spawn_point >> 3;
}

void GameState::set_trigger(const int trigger_id)
{
	triggers[trigger_id] = true;
}

bool GameState::get_trigger_value(const uint8_t trigger_id)
{
	return triggers[trigger_id];
}

void GameState::reset(const int save_slot)
{
	// we reuse the actual game's gamestate variable for defaulting a saveslot to the new-game state because GameState is a large struct and we don't want to spend so much ram on just a "default" value instance of it.
	// this is ok, because Reset is never used during a game, always from the Saveslot screen, where no game is active.
	Game::state = GameState();
	gb.save.set(save_slot, &Game::state, sizeof(GameState));
}
