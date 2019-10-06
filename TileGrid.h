#pragma once
#include <Gamebuino-Meta.h>

struct Vector8;
struct VectorI;
class Camera;
struct Rectangle;

constexpr int tile_size_pow2 = 4; // tile size in bitshift count
constexpr int tile_size = 1 << tile_size_pow2; // 16
constexpr int half_tile_size = tile_size >> 1;

namespace actors {
	// a 2D grid of tiles representing the main environment in your game, bases on tilesheet for graphics (walls, ladders etc)
	class TileGrid
	{
	public:
		void initialize(const Vector8& size, uint8_t* terrain_ptr);
		bool is_coin(const VectorI& location_grid) const;
		bool is_potion(const VectorI& location_grid) const;
		void remove_pickup(const VectorI& location_grid) const;
		// returns >-1 if the location is an unpressed pressure plate, returns its triggerid
		int get_pressure_plate_id(const VectorI& location_grid) const;
		void press_plate(const VectorI& location_grid) const;
		const uint16_t** tile_sprites_data = nullptr;
		uint8_t* terrain = nullptr;
		int width = 0;
		int height = 0;

		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int x, const int y, uint16_t* const slice_buffer) const;
		void render_tile(const uint16_t* tile_sprite_data, const Rectangle& sprite_part, const int& sprite_x, const int& sprite_y, uint16_t* slice_buffer) const;
		static VectorI to_grid_coords(const VectorI& location);
	};

}