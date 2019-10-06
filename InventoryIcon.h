#pragma once
#include <Gamebuino-Meta.h>

struct Rectangle;
class Camera;

namespace actors {

	class InventoryIcon 
	{
		uint8_t type_ = 0;
	public:
		InventoryIcon() = default;
		explicit InventoryIcon(uint8_t type) : type_(type) { }
		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y, uint16_t* slice_buffer) const;
	};

}
