#include "LevelLabel.h"
#include <Sprite.h>
#include <renderer.h>

namespace actors
{
	namespace ui
	{
		constexpr int keyframe_show_label = 30;
		constexpr int keyframe_move_label = 90;

		void LevelLabel::start_zone_label_sequence(const uint16_t* name_sprite)
		{
			name_sprite_ = name_sprite;
			is_visible = false;
			location_ = VectorI(30, 100);
			sequence_startframe = gb.frameCount;
		}

		void LevelLabel::update()
		{
			const auto frame = gb.frameCount - sequence_startframe;
			if (frame == keyframe_show_label)
				is_visible = true;

			if (frame > keyframe_move_label) {
				const auto f = frame - keyframe_move_label;
				location_.y += f;
				if (location_.y >= screen_height)
					is_visible = false;
			}
			
		}

		Rectangle LevelLabel::measure(const Camera& camera) const
		{
			if (!is_visible)
				return { 0, 0, -1, -1 };
			return { location_.x, location_.y, location_.x + name_sprite_[width_idx] - 1, location_.y + name_sprite_[height_idx] - 1 };
		}

		void LevelLabel::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
		{
			Sprite::render_cropped_sprite_part(name_sprite_, part, x, y, slice_buffer);
		}
	}
}
