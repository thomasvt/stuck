#include "HealthBar.h"
#include <Renderer.h>
#include <Rectangle.h>
#include <Game.h>
#include <GameState.h>
#include <Gamebuino-Meta.h>

namespace actors
{
	namespace ui
	{
		constexpr  uint16_t color_0 = 0x7F0;
		constexpr  uint16_t color_25 = 0xEB;
		constexpr  uint16_t color_50 = 0x87FF;
		constexpr  uint16_t color_75 = 0xE96D;

		Rectangle HealthBar::measure(const Camera& camera) const
		{
			return { 4, screen_height - 7, 55, screen_height - 5 };
		}

		inline uint16_t HealthBar::get_health_color(const uint8_t health)
		{
			if (health > 75)
				return color_75;
			if (health > 50)
				return color_50;
			if (health > 25)
				return color_25;
			return color_0;
		}

		void HealthBar::render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y, uint16_t* slice_buffer) const
		{
			const auto health = Game::state.health;
			const auto color = get_health_color(health);
			const auto value = health >> 1;
			auto slice_cursor = slice_buffer + ((anchor_y + part.top) * slice_width) + (anchor_x + part.left);
			auto current_value = part.left;
			
			for (auto x = part.left; x <= part.right; x++)
			{
				auto cursor = slice_cursor;
				*cursor = color;
				if (current_value <= value || x == 51)
				{
					cursor += slice_width;
					*cursor = color;
					cursor += slice_width;
					*cursor = color;
				}
				else
					cursor += slice_width << 1;
				cursor += slice_width;
				*cursor = color;

				current_value++;
				slice_cursor++;
			}
		}
	}
}

