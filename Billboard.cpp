#include "billboard.h"
#include <Sprite.h>
#include <Camera.h>

namespace actors
{
	Rectangle Billboard::measure(const Camera& camera) const
	{
		return Sprite::get_cropped_sprite_bounds(sprite_ptr, location.x, location.y);
	}

	void Billboard::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const 
	{
		Sprite::render_cropped_sprite_part(sprite_ptr, part, x, y, slice_buffer);
	}
}
