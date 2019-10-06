#include <Gamebuino-Meta.h>
#include "Renderer.h"
#include <Gamebuino_Meta_extension.h>
#include "Rectangle.h"
#include <PogoScene.h>

uint16_t Renderer::buffer1_[screen_height * slice_width] {};
uint16_t Renderer::buffer2_[screen_height * slice_width] {};
constexpr int slicecount = screen_width / slice_width;

void Renderer::delete_framework_backbuffer()
{
	gb.display.init(0, 0, ColorMode::rgb565);
}

void Renderer::render(Scene& scene, bool clear_screen) {
	wait_for_all_draws(); // ensure previous frame' bufferswap

	for (uint8_t slice_index = 0; slice_index < slicecount; slice_index++) {
		const auto buffer = (slice_index & 0b1) == 0 ? buffer1_ : buffer2_;

		if (clear_screen) 
			clear_buffer(buffer); // enable if you dont fill the screen completely with assets and you want a black background to prevent trailing

		const auto slice_left = slice_index * slice_width;
		const auto slice_bounds = Rectangle(slice_left, 0, slice_left + slice_width - 1, screen_height - 1);

		scene.render_slice(buffer, slice_bounds);

		if (slice_index != 0)
			wait_for_previous_draw();
		custom_draw_buffer(slice_index * slice_width, buffer);
	}
	wait_for_previous_draw();
}

inline void Renderer::clear_buffer(uint16_t* buffer)
{
	for (auto i = 0; i < slice_width * screen_height; i++) // faster than memset, oddly enough
	{
		//if (i % slice_width == 0) // show debug line at slice borders
		//	buffer[i] = 0xFF00;
		//else
		buffer[i] = 0;
	}
}

void Renderer::custom_draw_buffer(const uint8_t x, uint16_t* buffer) {
	gb.tft.setAddrWindow(x, 0, x + slice_width - 1, screen_height - 1);
	SPI.beginTransaction(Gamebuino_Meta::tft_spi_settings);
	gb.tft.dataMode();
	gb.tft.sendBuffer(buffer, slice_width * screen_height);
}

void Renderer::wait_for_previous_draw() {
	Gamebuino_Meta::wait_for_desc_available(3); // todo research how to access display class enough to also do parallel SPI streaming
	SPI.endTransaction();
}

void Renderer::wait_for_all_draws() {
	Gamebuino_Meta::wait_for_desc_available(3);
	gb.tft.idleMode();
	SPI.endTransaction();
}


