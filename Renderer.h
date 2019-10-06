#pragma once

#include <Vector.h>

class Scene;
constexpr int screen_width = 160;
constexpr int screen_height = 128;
const VectorI screen_center = { screen_width / 2, screen_height / 2 };
constexpr int slice_width = 10;
constexpr uint8_t layer_count = 2;

// Renders to the actual screen from a double buffer sliced into parts to save memory. 
// GameObjects must provide boundingbox for per slice frustum culling, and will be called to draw each of their parts in the screen-slices they are visible in.
class Renderer {
	static uint16_t buffer1_[screen_height * slice_width];
	static uint16_t buffer2_[screen_height * slice_width];

	static void custom_draw_buffer(uint8_t x, uint16_t* buffer);
	static void wait_for_previous_draw();
	static void wait_for_all_draws();
public:
	static void delete_framework_backbuffer();
	static void render(Scene& scene, bool clear_screen);
	static void clear_buffer(uint16_t* buffer);
};
