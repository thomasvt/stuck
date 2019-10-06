#include "Sparkles.h"
#include "SparklesAnimation.h"
#include <Camera.h>
#include <Rectangle.h>

namespace actors
{
	Sparkles::Sparkles()
	{
		animation_player_ = AnimationPlayer();
	}

	void Sparkles::start(const VectorI location)
	{
		location_ = location;
		animation_player_.set_animation(&animations::sparkles);
	}

	Rectangle Sparkles::measure(const Camera& camera) const
	{
		if (animation_player_.is_at_end())
			return {0,0,-1,-1};
		const auto location_screen = camera.to_screen(location_);
		return animation_player_.get_cropped_sprite_bounds(location_screen.x, location_screen.y);
	}

	void Sparkles::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		animation_player_.render(part, x, y, slice_buffer);
	}
}
