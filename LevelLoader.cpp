#include "LevelLoader.h"
#include <CollisionDetector.h>
#include <Level.h>
#include <Levels.h>
#include <InputProcessor.h>
#include <Debug.h>
// actors
#include "Hero.h"
#include <TileGrid.h>
// sprites
#include "TileSprites.h"
#include "Game.h"
#include "LevelLabel.h"
#include "GoblinDefinition.h"
#include <PortalParticles.h>
#include "ImpDefinition.h"


constexpr auto max_level_size = 2000; // max tiles in level, x and y of level is free to choose as long x * y <= 2000

bool LevelLoader::must_jump_level_ = false;

uint8_t terrain[max_level_size] = { 0 }; // todo move to ... ?

bool LevelLoader::is_no_stone_wall(const uint8_t* const source_terrain, const Vector8& size, const int y, const int x)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return false;
	const auto value = source_terrain[y * size.x + x];
	return value != level_wall && value != level_secret_wall && value != level_wall_grass;
}

uint8_t LevelLoader::get_trigger_id_at(const Level& level, VectorI location_grid)
{
	for (auto i = 0; i < level.get_trigger_area_count(); i++)
	{
		const auto area = level.get_trigger_area_rectangle(i);
		if (area.contains(location_grid))
			return level.get_trigger_area_trigger_id(i);
	}
	return 255;
}

void LevelLoader::load_terrain_tiles(const Level& level, const Vector8& size)
{
	Game::scene.coin_counter.value = 0;
	const auto source_terrain = level.terrain_data;
	uint8_t trigger_id;
	bool trigger_is_set;
	auto enemy_index = 0;
	auto collectible_index = 0;
	auto door_index = 0;
	// translate the simplified level definition into the more complex runtime tiles and actors. (the numbers of level definition tiles and runtime tiles are different, and are mapped here)
	for (auto y = 0; y < size.y; y++)
	{
		for (auto x = 0; x < size.x; x++)
		{
			const auto i = y * size.x + x;
			terrain[i] = 0;

			switch (source_terrain[i])
			{
			case 0: // open space
				break;
			case level_secret_wall: // secret wall (passable), threat just like normal wall because load_terrain_tiles() sets graphical tiles only.
			case level_wall: // wall. translate into specific wall sprite
			case level_wall_grass:
			{
				// we use a bitmask of 4 bit to find the right tile depending on the 4 directions of a tile that can be an edge (1) or not (0)		
				const auto up = is_no_stone_wall(source_terrain, size, y - 1, x);
				const auto down = is_no_stone_wall(source_terrain, size, y + 1, x);
				const auto left = is_no_stone_wall(source_terrain, size, y, x - 1);
				const auto right = is_no_stone_wall(source_terrain, size, y, x + 1);

				const auto tile_index = (up | right << 1 | down << 2 | left << 3); // index within wall segment of tiles
				const auto is_grass_tile = ((source_terrain[i] == level_wall_grass) && up);

				terrain[i] = is_grass_tile
					? 16 + (tile_index >> 1) // grass: also divide bit-result by 2 because we omitted the odd tileindexes (save ram) because they have no bit0 == 1 == edge on top == no grass.
					: 25 + tile_index;

				if (y > 0 && up && source_terrain[i - size.x] == 0) // don't replace ladders or other deliberate items
				{
					if (is_grass_tile)
					{
						// add grasswall vegetation
						const auto veg_value = random(10);
						if (veg_value < 3)
							terrain[i - size.x] = veg_value + 7;
					}
					else
					{
						// add wall vegetation
						const auto value = random(30);
						if (value < 6)
							terrain[i - size.x] = value + 10;
					}
				}
				break;
			}
			case level_door: case level_door+1: case level_door+2: case level_door+3:
				Game::scene.add_door(Vector16(x << tile_size_pow2, (y << tile_size_pow2) - 32), source_terrain[i] - level_door, Game::state.is_door_open(door_index++));
				break;
			case level_goblin:

				Game::scene.add_enemy(Vector16((x << tile_size_pow2) + 8, (y << tile_size_pow2) + 7), actors::GoblinDefinition::instance, Game::state.is_enemy_dead(enemy_index++));
				break;
			case level_imp: 
				Game::scene.add_enemy(Vector16((x << tile_size_pow2) + 8, (y << tile_size_pow2) + 7), actors::ImpDefinition::instance, Game::state.is_enemy_dead(enemy_index++));
				break;
			case level_pickup: case level_pickup + 1: case level_pickup + 2: case level_pickup + 3: case level_pickup + 4: case level_pickup + 5: case level_pickup + 6:
			{
				const auto gem_type = Game::state.is_collectible_looted(collectible_index++) ? 255 : source_terrain[i] - level_pickup;
				Game::scene.add_pickup(Vector8(x, y), gem_type);
				break;
			}
			case level_spikes:
				terrain[i] = 24;
				break;
			case level_ladder:
				terrain[i] = 1;
				break;
			case level_potion:
				terrain[i] = Game::state.is_collectible_looted(collectible_index++) ? 0 : 3;
				break;
			case level_coin:
				if (Game::state.is_collectible_looted(collectible_index++))
				{
					terrain[i] = 0;
				}
				else
				{
					Game::scene.coin_counter.value++;
					terrain[i] = 6;
				}
				break;
			case level_woodwall_junction: case level_woodwall_h: case level_woodwall_v:
				terrain[i] = 41 + source_terrain[i] - level_woodwall_junction;
				break;
			
			case level_stair_add: // a block that only shows up when its associated trigger is set, this is altered dynamically while playing within a level by TriggerController.
				trigger_id = get_trigger_id_at(level, VectorI(x, y));
				trigger_is_set = trigger_id == 255 || Game::state.get_trigger_value(trigger_id);
				terrain[i] = trigger_is_set ? 44 : 0;
				break;
			case level_stair_remove: // a block that is removed when its associated trigger is set
				trigger_id = get_trigger_id_at(level, VectorI(x, y));
				trigger_is_set = trigger_id != 255 && Game::state.get_trigger_value(trigger_id);
				terrain[i] = trigger_is_set ? 0 : 44;
				break;
			case level_pillar:
				terrain[i] = 45;
				break;
			case level_catapult:
				Game::scene.add_catapult(Vector8(x, y));
				break;
			default:
				if (source_terrain[i] >= level_flamethrowers_offset)
				{
					Game::scene.add_flamethrower(Vector8(x, y), (source_terrain[i] - level_flamethrowers_offset) << 4);
				}
				else if (source_terrain[i] >= level_pressure_plates_offset)
				{
					trigger_is_set = Game::state.get_trigger_value(source_terrain[i] - level_pressure_plates_offset);
					terrain[i] = trigger_is_set ? 5 : 4;
				}
				else
				{
					// all other tiles are 1-to-1 mappings with offset of 20
					terrain[i] = source_terrain[i] - 20;
				}
				break;
			}
		}
	}
}

const char level_out_of_bounds_msg[] PROGMEM = "level number out of bounds";

void LevelLoader::load(const Level& level, const int spawn_id, InputProcessor& input_processor)
{
	randomSeed(1); // ensure random content is always the same in a reloaded level.

	const auto size = level.get_size();
	if (size.x * size.y > max_level_size)
		Debug::throw_fatal(level_out_of_bounds_msg);

	actors::PortalParticles::initialize(); // set particles to random state
	Game::scene.initialize(VectorI(size.x << tile_size_pow2, size.y << tile_size_pow2));

	load_terrain_tiles(level, size);
	Game::scene.tile_grid.initialize(size, terrain);
	Game::scene.tile_grid.tile_sprites_data = tile_sprites;

	for (auto i = 0; i < level.get_portal_count(); i++)
	{
		const auto portal_info = level.get_portal_info(i);

		Game::scene.add_portal(Vector8(portal_info.location.x, portal_info.location.y), portal_info.target_level_id, portal_info.target_spawn_id);
	}

	const auto spawnpoint = level.get_spawnpoint(spawn_id);

	const auto hero_location = VectorI((spawnpoint.x << tile_size_pow2) + tile_size / 2, (spawnpoint.y << tile_size_pow2) + tile_size / 2 - 5);
	Game::scene.hero.initialize(hero_location);

	Game::scene.level_label.start_zone_label_sequence(level.name_sprite);

	CollisionDetector::set_level(&level);

	input_processor.set_controlled_hero(&Game::scene.hero); // todo remove?
}

void LevelLoader::load_level(const uint8_t spawn_id, InputProcessor& input_processor)
{
	const auto current_level = spawn_id >> 3;
	must_jump_level_ = false;
	load(levels::levels[current_level], spawn_id & 0b111, input_processor);
}

void LevelLoader::load_next_level_if_needed(InputProcessor& input_processor)
{
	if (must_jump_level_)
	{
		load_level(Game::state.spawn_point, input_processor);
	}
}

void LevelLoader::trigger_level_switch(const uint8_t next_spawn_point)
{
	must_jump_level_ = true;
	Game::state.spawn_point = next_spawn_point;
}
