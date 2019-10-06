#pragma once
#include <Gamebuino-Meta.h>

struct Level;
class InputProcessor;
struct Vector8;
struct VectorI;

// game sees values inside [30, 64) as physical obstacles

constexpr auto level_pressure_plates_offset = 64;

constexpr auto level_secret_wall = 3;
constexpr auto level_ladder = 4;
constexpr auto level_spikes = 5;
constexpr auto level_door = 6; // + 7, 8 & 9 (four colors of door, each with different gem to open it)
constexpr auto level_pickup = 10; // + 11, 12 & 13 (four colors of gem)
constexpr auto pickup_type_count = 7;
constexpr auto level_potion = 17;
constexpr auto level_coin = 18;
constexpr auto level_goblin = 19;
constexpr auto level_imp = 20;
constexpr auto level_boss = 21; // reserved
constexpr auto level_catapult = 23;

constexpr auto level_pillar = 27; // walk-through pillar in front of hero
constexpr auto level_stair_add = 28; // a stairs-block that appears when a trigger is true
constexpr auto level_stair_remove = 29; // a stairs-block that disappears when a trigger is true

constexpr auto level_wall = 30;
constexpr auto level_wall_grass = 31;
constexpr auto level_woodwall_junction = 32;
constexpr auto level_woodwall_h = 33;
constexpr auto level_woodwall_v = 34;

constexpr auto level_flamethrowers_offset = 240; // vertical flame thrower offset


class LevelLoader
{
	static bool must_jump_level_;
public:
	static bool is_no_stone_wall(const uint8_t* source_terrain, const Vector8& size, int y, int x);
	static uint8_t get_trigger_id_at(const Level& level, VectorI location_grid);
	static void load_terrain_tiles(const Level& level, const Vector8& size);
	static void load(const Level& level, const int spawn_id, InputProcessor& input_processor);
	static void load_level(uint8_t spawn_id, InputProcessor& input_processor);
	// checks if the next level must be loaded and loads it. Returns true if a new level was loaded.
	static void load_next_level_if_needed(InputProcessor& input_processor);
	// configures the game so it will load the requested level next frame.
	static void trigger_level_switch(uint8_t next_spawn_point);
};

