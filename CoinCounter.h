#pragma once
#include <Gamebuino-Meta.h>

struct Rectangle;
class Camera;

namespace actors
{
	namespace ui
	{

		class CoinCounter
		{
		public:
			uint8_t value = 0;
			Rectangle measure(const Camera& camera) const;
			void render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y, uint16_t* slice_buffer) const;
		};

	}
}
