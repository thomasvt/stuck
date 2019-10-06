#include "CoinCounter.h"
#include <Camera.h>
#include <Rectangle.h>
#include <Renderer.h>
#include "Texts.h"

namespace actors
{
	namespace ui
	{
		constexpr int label_x = 80 + text::char_width * 2; // note: the score is right-aligned at this x!
		constexpr int label_y = 118;

		Rectangle CoinCounter::measure(const Camera& camera) const
		{
			const auto digit_count_pow = value > 9 ? 1 : 0;
			return { label_x - (text::char_width << digit_count_pow) + 1, label_y, label_x, label_y + text::font_spritesheet_height - 1 };
		}

		void CoinCounter::render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y,
			uint16_t* slice_buffer) const
		{
			const auto char_count = value > 9 ? 2 : 1;

			if (char_count == 1)
			{	// render 1 digit coincount
				for (auto y = part.top; y <= part.bottom; y++)
				{
					auto slice_cursor = anchor_x + part.left + ((anchor_y + y) * slice_width);
					for (auto x = part.left; x <= part.right; x++)
					{
						const auto x_in_char = x % text::char_width; // x inside current char of string on screen

						const auto glyph_index = value; // index of cipher-glyph in font spritesheet
						const auto pixel_value = text::score_font[y * text::font_spritesheet_width + glyph_index * text::char_width + x_in_char];
						if (pixel_value != 0)
						{
							slice_buffer[slice_cursor] = pixel_value;
						}
						slice_cursor++;
					}
				}
			}
			else
			{	// render 2 digit coincount
				int chars[] = { value / 10, value % 10 };
				for (auto y = part.top; y <= part.bottom; y++)
				{
					auto slice_cursor = anchor_x + part.left + ((anchor_y + y) * slice_width);
					for (auto x = part.left; x <= part.right; x++)
					{
						const auto char_index = x / text::char_width; // index in string on screen
						const auto x_in_char = x % text::char_width; // x inside current char of string on screen

						const auto glyph_index = chars[char_index]; // index of cipher-glyph in font spritesheet
						const auto pixel_value = text::score_font[y * text::font_spritesheet_width + glyph_index * text::char_width + x_in_char];
						if (pixel_value != 0)
						{
							slice_buffer[slice_cursor] = pixel_value;
						}
						slice_cursor++;
					}
				}
			}
		}

	}
}
