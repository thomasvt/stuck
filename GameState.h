#pragma once
#include "Inventory.h"
#include "Levels.h"

constexpr int max_health = 100;

// the entire state of progress of a player's game. This structure is what is persisted in saveslots so a player can continue where he left off.
class GameState
{
public:
	// creates a 'new-game' GameState
	GameState();

	Inventory inventory;
	uint8_t health;
	uint8_t spawn_point; // == checkpoint for saving the game and respawning upon reload of a game or death.
	bool triggers[levels::trigger_count] = {};
	uint16_t enemies[levels::level_count] = {}; // tracks which enemies have been killed
	uint8_t doors[levels::level_count] = {}; // tracks which doors have been opened
	uint8_t pickups[levels::level_count][8] = {}; // tracks which pickups have been taken
	int air_jump_count = 0;
	bool arrow_climb_enabled = false;

	void add_health(int health);
	void set_enemy_state(int i, bool is_killed);
	void set_collectible_state(int i, bool is_looted);
	void set_door_state(int i, bool is_open);
	// queries the stored world state for an Enemy being alive or not.
	bool is_enemy_dead(int i);
	bool is_collectible_looted(int i);
	bool is_door_open(int i);
	
	// grabs the current world state from PogoScene and stores a representation in GameState, so the world state can be persisted and restored.
	void store_current_area_state();

	void save(int save_slot);
	void load(int save_slot);
	int get_current_level_id() const;
	void set_trigger(const int trigger_id);
	bool get_trigger_value(const uint8_t trigger_id);
	static void reset(int save_slot);
};

