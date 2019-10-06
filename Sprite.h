#pragma once

#include <Gamebuino-Meta.h>
#include <rectangle.h>

constexpr uint8_t flip = 1;
constexpr uint8_t hurt = 2;

// the indexes of sprite properties inside the data array.
constexpr int width_idx = 0;
constexpr int height_idx = 1;
constexpr int cropped_offset_x_idx = 2;
constexpr int cropped_offset_y_idx = 3;
constexpr int cropped_width_idx = 4;
constexpr int cropped_height_idx = 5;
constexpr int anchor_in_center_idx = 6;

// A single graphical asset supporting transparency. A sprite has an original width and height (from the original file) but also an internal, cropped rectangle omitting the transparent pixels around the art. 
// This cropped rectangle is used by the rendering framework to optimize performance.
class Sprite
{
public:
	// called by the rendering framework to know the size of the cropped area of the sprite
	static Rectangle get_cropped_sprite_bounds(const uint16_t* data, int anchor_x, int anchor_y, bool flip_horizontally = false);
	// called by the rendering framework (flags: bit 0: flip horizontally, bit 1: render all non transparent pixels as red
	static void render_cropped_sprite_part(const uint16_t* data, const Rectangle& sprite_part, const int& sprite_x, const int& sprite_y, uint16_t* slice_buffer, uint8_t flags = 0);
};