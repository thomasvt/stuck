#pragma once
#include <Gamebuino-Meta.h>

class Camera;
struct Rectangle;

namespace actors
{
	namespace ui
	{
		class HealthBar
		{
			static uint16_t get_health_color(uint8_t health);
		public:
			Rectangle measure(const Camera& camera) const;
			void render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y, uint16_t* slice_buffer) const;
		};
	}
}

