#pragma once

#include <Gamebuino-Meta.h>
#include <Vector.h>
#include <Rectangle.h>
#include <AnimationPlayer.h>

class Camera;

namespace actors
{
	
	class FlameThrower
	{
	public:
		Vector8 position_grid;
		uint8_t fire_offset;
		AnimationPlayer animation_player = AnimationPlayer();

		FlameThrower()
		{
			position_grid = Vector8();
			fire_offset = 0;
		}

		explicit FlameThrower(const Vector8& location_grid, const uint8_t& fire_offset);

		void update();
		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
	};

}
