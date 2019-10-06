#include "Sprite.h"
#include <renderer.h>

constexpr uint16_t flash_color = 0xFFFF;

Rectangle Sprite::get_cropped_sprite_bounds(const uint16_t* data, int anchor_x, int anchor_y, const bool flip_horizontally)
{
	int x;
	if (data[anchor_in_center_idx])
	{
		// move anchor to upleft by half size so the sprite is rendered centered around its anchor
		anchor_x -= data[width_idx] >> 1; 
		anchor_y -= data[height_idx] >> 1;
	}
	if (flip_horizontally)
	{
		x = anchor_x + data[width_idx] - data[cropped_offset_x_idx] - data[cropped_width_idx];
	}
	else
	{
		x = anchor_x + data[cropped_offset_x_idx];
	}
	const auto y = anchor_y + data[cropped_offset_y_idx];
	
	return {x, y, x + data[cropped_width_idx] - 1, y + data[cropped_height_idx] - 1};
}

// sprite_part: the rectangular area of the cropped sprite that is requested to be drawn
// sprite_x: the X offset within the slice_buffer to the topleft of the cropped sprite
// sprite_y: the Y offset within the slice_buffer to the topleft of the cropped sprite
//            --------------------
//            | slice            |
//            |                  |
//            |                  |  - the S-point = (sprite_x, sprite_y)
//            |                  |  - P and the asterisk filled area is the part of the sprite requested to be drawn, relative to S
//        S---P-----             |  
//        |   |****|             |
//        |   |****| <- sprite   |
//        |   |****|             |
//        ----------             |
//            |                  |
//            |                  |
//            |                  |
//            |                  |
//            --------------------
void Sprite::render_cropped_sprite_part(const uint16_t* data, const Rectangle& sprite_part, const int& sprite_x, const int& sprite_y, uint16_t* slice_buffer, const uint8_t flags)
{
	const auto part_x = sprite_x + sprite_part.left; // x offset of sprite_part in slice
	const auto cursor_y = sprite_y + sprite_part.top;
	auto slice_cursor = slice_buffer + (cursor_y * slice_width) + part_x; // pointer into slice where current horizontal stripe of pixels must begin
	
	const auto part_width = sprite_part.right - sprite_part.left + 1;

	if (flags & 0b1)
	{
		const auto sprite_part_mirror = Rectangle(data[cropped_width_idx] - 1 - sprite_part.right, sprite_part.top, data[cropped_width_idx] - 1 - sprite_part.left, sprite_part.bottom);
		const auto right = part_width - 1;
		auto sprite_cursor = data + 7 + sprite_part_mirror.left + sprite_part_mirror.top * data[cropped_width_idx]; // pointer into actor sprite where current horizontal stripe of pixels sits
		if (flags & 0b10) // color all pixels red, we repeat the entire loop to prevent IF-ing inside hottest code
		{
			for (auto y = sprite_part_mirror.top; y <= sprite_part_mirror.bottom; y++)
			{
				for (auto x = 0; x < part_width; x++)
				{
					const auto value = *(sprite_cursor + x);
					if (value > 0)
						* (slice_cursor + right - x) = flash_color; // <- for flipping: target pixel is mirrored horizontally
				}
				slice_cursor += slice_width;
				sprite_cursor += data[cropped_width_idx];
			}
		}
		else
		{
			for (auto y = sprite_part_mirror.top; y <= sprite_part_mirror.bottom; y++)
			{
				for (auto x = 0; x < part_width; x++)
				{
					const auto value = *(sprite_cursor + x);
					if (value > 0)
						* (slice_cursor + right - x) = value; // <- for flipping: target pixel is mirrored horizontally
				}
				slice_cursor += slice_width;
				sprite_cursor += data[cropped_width_idx];
			}
		}
	}
	else
	{
		auto sprite_cursor = data + 7 + sprite_part.left + sprite_part.top * data[cropped_width_idx]; // pointer into actor sprite where current horizontal stripe of pixels sits
		const auto slice_next_row_increment = slice_width - part_width;
		const auto sprite_next_row_increment = data[cropped_width_idx] - part_width;
		if (flags & 0b10) // color all pixels red, we repeat the entire loop to prevent IF-ing inside hottest code
		{
			for (auto y = sprite_part.top; y <= sprite_part.bottom; y++)
			{
				for (auto x = 0; x < part_width; x++)
				{
					const auto value = *sprite_cursor;
					if (value > 0) // using 0 as transparent is a lot faster than checking != on a specific color
						* slice_cursor = flash_color;
					sprite_cursor++;
					slice_cursor++;
				}
				slice_cursor += slice_next_row_increment;
				sprite_cursor += sprite_next_row_increment;
			}
		}
		else
		{
			for (auto y = sprite_part.top; y <= sprite_part.bottom; y++)
			{
				for (auto x = 0; x < part_width; x++)
				{
					const auto value = *sprite_cursor;
					if (value > 0) // using 0 as transparent is a lot faster than checking != on a specific color
						* slice_cursor = value;
					sprite_cursor++;
					slice_cursor++;
				}
				slice_cursor += slice_next_row_increment;
				sprite_cursor += sprite_next_row_increment;
			}
		}
	}
}
