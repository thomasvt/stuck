#pragma once
#include <Gamebuino-Meta.h>

class Camera;
struct Rectangle;

namespace actors {
	namespace hero {

		class Crosshair
		{
		public:
			Rectangle measure(const Camera& camera) const;
			void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const ;
		};

	}
}
