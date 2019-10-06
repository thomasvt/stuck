#pragma once
#include <Vector.h>
#include <Gamebuino-Meta.h>

struct Rectangle;
class Camera;

namespace actors {

	// an actor showing a sprite
	class Billboard
	{
	public:
		const uint16_t* sprite_ptr = nullptr;
		Vector8 location = Vector8();

		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
	};

}
