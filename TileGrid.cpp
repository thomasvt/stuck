#include "TileGrid.h"
#include <Camera.h>
#include <Vector.h>
#include <Rectangle.h>
#include <Renderer.h>
#include "Levels.h"
#include <Game.h>
#include <GameState.h>

namespace actors {

	void TileGrid::initialize(const Vector8& size, uint8_t* terrain_ptr)
	{
		this->terrain = terrain_ptr;
		this->width = size.x;
		this->height = size.y;
	}

	bool TileGrid::is_coin(const VectorI& location_grid) const
	{
		return terrain[location_grid.y * width + location_grid.x] == 6;
	}

	bool TileGrid::is_potion(const VectorI& location_grid) const
	{
		return terrain[location_grid.y * width + location_grid.x] == 3;
	}

	void TileGrid::remove_pickup(const VectorI& location_grid) const
	{
		terrain[location_grid.y * width + location_grid.x] = 0;
	}

	int TileGrid::get_pressure_plate_id(const VectorI& location_grid) const
	{
		const auto result = location_grid.y >= 0 && location_grid.y < height
			&& location_grid.x >= 0 && location_grid.x < width
			&& terrain[location_grid.y * width + location_grid.x] == 4; // == unpressed pressure plate
		if (result)
			return levels::levels[Game::state.get_current_level_id()].get_pressure_plate_trigger_id(location_grid);
		return -1; // no plate pressed
	}

	void TileGrid::press_plate(const VectorI& location_grid) const
	{
		terrain[location_grid.y * width + location_grid.x] = 5;
	}

	Rectangle TileGrid::measure(const Camera& camera) const
	{
		const auto screen_location = camera.to_screen(VectorI());
		return {
			screen_location.x,
			screen_location.y,
			screen_location.x + (width << tile_size_pow2) - 1,
			screen_location.y + (height << tile_size_pow2) - 1
		};
	}

	void TileGrid::render(const uint8_t& layer, const Rectangle& part, int x, const int y, uint16_t* const slice_buffer) const
	{
		// find which tiles of the grid we need to render in the requested part
		const auto visible_tiles = Rectangle(part.left >> tile_size_pow2, part.top >> tile_size_pow2, part.right >> tile_size_pow2, part.bottom >> tile_size_pow2);

		// loop over these tiles and draw the part that is visible inside the requested part:
		const auto first_left = visible_tiles.left << tile_size_pow2;
		const auto first_right = ((visible_tiles.left + 1) << tile_size_pow2) - 1;
		auto current_tile_bounds = Rectangle(first_left, visible_tiles.top << tile_size_pow2, first_right, ((visible_tiles.top + 1) << tile_size_pow2) - 1);
		for (auto tile_y = visible_tiles.top; tile_y <= visible_tiles.bottom; tile_y++)
		{
			for (auto tile_x = visible_tiles.left; tile_x <= visible_tiles.right; tile_x++) // this is at most 2 tiles wide, because we render per screen-slice
			{
				const auto tile_index = terrain[tile_y * width + tile_x];
				if (tile_index > 0 && ((layer == 0 && tile_index == 1) || (layer == 1 && tile_index != 1))) // not open space tile?
				{
					const auto& tile = tile_sprites_data[tile_index];
					auto tile_part = part.intersect(current_tile_bounds);
					// normalize tile_part (by removing all full repetitions of the sprite before it on X and Y axis, so we end up with the tile_part of the single sprite:
					tile_part.left -= current_tile_bounds.left;
					tile_part.right -= current_tile_bounds.left;
					tile_part.top -= current_tile_bounds.top;
					tile_part.bottom -= current_tile_bounds.top;

					render_tile(*(tile_sprites_data + tile_index), tile_part, current_tile_bounds.left - part.left, current_tile_bounds.top - part.top, slice_buffer);
				}

				current_tile_bounds.left += tile_size;
				current_tile_bounds.right += tile_size;
			}

			// go to beginning of next row of tiles inside this slice
			current_tile_bounds.top += tile_size;
			current_tile_bounds.bottom += tile_size;
			current_tile_bounds.left = first_left;
			current_tile_bounds.right = first_right;
		}
	}

	inline void TileGrid::render_tile(const uint16_t* tile_sprite_data, const Rectangle& sprite_part, const int& sprite_x, const int& sprite_y, uint16_t* slice_buffer) const
	{
		const auto part_x = sprite_x + sprite_part.left; // x offset of sprite_part in slice
		const auto cursor_y = sprite_y + sprite_part.top;
		auto slice_cursor = slice_buffer + (cursor_y * slice_width) + part_x; // pointer into slice where current horizontal stripe of pixels must begin

		const auto part_width = sprite_part.right - sprite_part.left + 1;
		auto sprite_cursor = tile_sprite_data + sprite_part.left + (sprite_part.top << tile_size_pow2); // pointer into sprite where current horizontal stripe of pixels sits
		const auto slice_next_row_increment = slice_width - part_width;
		const auto sprite_next_row_increment = tile_size - part_width;
		for (auto y = sprite_part.top; y <= sprite_part.bottom; y++)
		{
			for (auto x = 0; x < part_width; x++)
			{
				const auto value = *sprite_cursor;
				if (value)* slice_cursor = value;
				sprite_cursor++;
				slice_cursor++;
			}
			slice_cursor += slice_next_row_increment;
			sprite_cursor += sprite_next_row_increment;
		}
	}


	VectorI TileGrid::to_grid_coords(const VectorI& location)
	{
		return { location.x >> tile_size_pow2, location.y >> tile_size_pow2 };
	}

}
