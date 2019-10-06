#pragma once
#include <Gamebuino-Meta.h>
#include <Vector.h>
#include <Rectangle.h>

class Camera;

namespace actors
{
	namespace ui
	{
		// a Label that is shown on the foreground when entering a new zone and moves to the top of the screen after a while.
		class LevelLabel
		{
			uint32_t sequence_startframe = 0;
			VectorI location_ = VectorI();
			
			const uint16_t* name_sprite_ = nullptr;
		public:
			bool is_visible = false;
			void start_zone_label_sequence(const uint16_t* name_sprite);
			void update();
			Rectangle measure(const Camera& camera) const;
			void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
		};
	}
}

