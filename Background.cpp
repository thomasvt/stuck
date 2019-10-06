#include "Background.h"
#include <Camera.h>
#include <Renderer.h>
#include "BackgroundSprite.h"
#include <Game.h>

constexpr auto bg_sprite_size_pow2 = 6;
constexpr auto bg_modulo_mask = (1 << bg_sprite_size_pow2) - 1;

Rectangle Background::measure(const Camera& camera) const
{
	const auto location_screen = camera.to_screen(VectorI());
	return {location_screen.x >> 1, location_screen.y >> 3, Game::scene.size.x - 1, Game::scene.size.y - 1}; // >> 1 causes background to scroll slower than camera = depth effect
}

void Background::render(const uint8_t& layer, const Rectangle& part, const int anchor_x, const int anchor_y, uint16_t* const slice_buffer) const
{
	auto slice_cursor_ptr = slice_buffer + anchor_x + part.left + ((part.top + anchor_y) * slice_width);
	const auto distance_to_next_row = slice_width - (part.right - part.left + 1);
	for (auto y = part.top; y <= part.bottom; y++)
	{
		const auto sprite_cursor_row_ptr = background_sprite + ((y & bg_modulo_mask) << bg_sprite_size_pow2);
		for (auto x = part.left; x <= part.right; x++)
		{
			*slice_cursor_ptr = *(sprite_cursor_row_ptr + (x & bg_modulo_mask)); // = same as % sprite_size. To get repeating sprite
			slice_cursor_ptr++;
		}
		slice_cursor_ptr += distance_to_next_row; // = slice stride - part width
	}
}
