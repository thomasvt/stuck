#include "Door.h"
#include "DoorSprites.h"
#include <Camera.h>
#include <Game.h>
#include <Inventory.h>
#include "Sounds.h"

namespace actors {
	
	constexpr uint8_t closed = 50;
	constexpr uint8_t max_visual_offset = 32;

	// open_distance is number of pixels of vertical offset to enable sliding the door open. But all open_distance > 32 are coerced to 32. This way we build in a delay timer upon opening the door with a key. 
	// We animate from 48 down to 0 but only as of 32 it starts to visually open.

	Door::Door() = default;

	Door::Door(const Vector16 location, const uint8_t color)
	{
		this->location = location;
		color_ = color;
		open_distance = closed; // fully closed
	}

	void Door::update()
	{
		if (open_distance == closed)
		{
			const auto hero_location = Game::scene.hero.get_location();
			if (Game::state.inventory.has_pickup(color_) && hero_location.x > location.x - 16 && hero_location.x < location.x + 32 && hero_location.y > location.y + 32 && hero_location.y <= location.y + 64)
			{
				Game::state.inventory.remove_pickup(color_);
				open();
				gb.sound.fx(sounds::click);
			}
		}
		else if (open_distance < closed && open_distance > 0) // delay between entering gem and sliding of door
		{
			if (open_distance == max_visual_offset)
			{
				gb.sound.fx(sounds::quake);
				Game::scene.camera.quake(32);
			}
			open_distance--;
		}
	}

	Rectangle Door::measure(const Camera& camera) const
	{
		if (open_distance == 0)
			return { 0,0,-1,-1 };
		const auto location_screen = camera.to_screen(VectorI(location.x, location.y + (open_distance > max_visual_offset ? max_visual_offset : open_distance)));
		if (open_distance == closed)
			return Sprite::get_cropped_sprite_bounds(sprites::doors_closed[color_], location_screen.x, location_screen.y);
		return Sprite::get_cropped_sprite_bounds(sprites::doors_open[color_], location_screen.x, location_screen.y);
	}

	void Door::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		if (open_distance == closed)
		{
			Sprite::render_cropped_sprite_part(sprites::doors_closed[color_], part, x, y, slice_buffer);
		}
		else
		{
			Sprite::render_cropped_sprite_part(sprites::doors_open[color_], part, x, y, slice_buffer);
		}
	}

	void Door::open(bool instant)
	{
		open_distance = instant ? 0 : closed-1;
	}

	bool Door::is_open() const
	{
		return open_distance == 0;
	}

	Rectangle Door::get_bounding_box() const
	{
		const auto visual_offset = (open_distance > max_visual_offset ? max_visual_offset : open_distance);
		return { location.x, location.y + visual_offset, location.x + 15, location.y + visual_offset + 31 };
	}
}
