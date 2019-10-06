#include "TriggerController.h"
#include "Levels.h"
#include <Gamebuino-Meta.h>
#include <Game.h>
#include <TileGrid.h>
#include <Level.h>
#include <Hero.h>
#include <GameState.h>
#include "Sounds.h"



void TriggerController::apply_trigger_changes(const int trigger_id)
{
	const auto level = levels::levels[Game::state.get_current_level_id()];
	// loop over all trigger-areas in this level, if the trigger_id matches, apply the changes
	for (auto i = 0; i < level.get_trigger_area_count(); i++)
	{
		if (level.get_trigger_area_trigger_id(i) == trigger_id)
		{
			const auto area = level.get_trigger_area_rectangle(i);
			const auto level_size = level.get_size();
			area.log();
			for (auto y = area.top; y <= area.bottom; y++)
				for (auto x = area.left; x <= area.right; x++)
				{
					const auto cell_offset = y * level_size.x + x;
					if (level.terrain_data[cell_offset] == level_stair_add)
						Game::scene.tile_grid.terrain[cell_offset] = 44; // place stairs block
					else if (level.terrain_data[cell_offset] == level_stair_remove)
						Game::scene.tile_grid.terrain[cell_offset] = 0; // remove stairs block
				}
		}
	}
}

void TriggerController::update()
{
	if (!Game::scene.hero.is_on_floor())
		return;

	const auto location = Game::scene.hero.get_location();
	const auto location_grid = actors::TileGrid::to_grid_coords(VectorI(location.x, location.y + 4));
	const auto trigger_id = Game::scene.tile_grid.get_pressure_plate_id(location_grid);
	if (trigger_id >= 0)
	{
		gb.sound.fx(sounds::click_quake);
		Game::scene.tile_grid.press_plate(location_grid);
		Game::state.set_trigger(trigger_id);
		Game::scene.camera.quake(30);
		apply_trigger_changes(trigger_id);
	}
}
