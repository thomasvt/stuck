#include "InventoryIcon.h"
#include <Renderer.h>
#include "GemSprites.h"
#include <Sprite.h>
#include <Game.h>
#include <Camera.h>

namespace actors {

	Rectangle InventoryIcon::measure(const Camera& camera) const
	{
		if (!Game::state.inventory.has_pickup(type_))
			return { 0, 0, -1, -1 };
		const auto offset_x = screen_width - 32 - 4 + (type_ << 3);
		return { offset_x, screen_height - 8, offset_x + 6, screen_height - 2 };
	}

	void InventoryIcon::render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y,
		uint16_t* slice_buffer) const
	{
		Sprite::render_cropped_sprite_part(sprites::gem_icons[type_], part, anchor_x, anchor_y, slice_buffer);
	}
}
