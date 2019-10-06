#include "AnimationPlayer.h"
#include <Gamebuino-Meta.h>
#include <Rectangle.h>
#include <Sprite.h>
#include "Time.h"

void AnimationPlayer::set_animation(const Animation* animation_ptr, const bool reset_frame_position)
{
	if (animation_ptr == this->animation_ptr)
		return;

	if (animation_ptr == nullptr)
	{
		stop();
	}
	else
	{
		this->animation_ptr = animation_ptr;
		if (reset_frame_position)
			this->start_frame = gametime::framecount;
	}
}

inline const uint16_t* AnimationPlayer::get_current_frame() const
{
	if (animation_ptr->get_repeat())
	{
		return animation_ptr->frames[((gametime::framecount - start_frame) >> animation_ptr->get_interval_pow2()) % animation_ptr->get_frame_count()];
	}
	auto frame = ((gametime::framecount - start_frame) >> animation_ptr->get_interval_pow2());
	if (frame >= animation_ptr->get_frame_count())
	{
		frame = animation_ptr->get_frame_count()-1; 
	}
	return animation_ptr->frames[frame];
}

Rectangle AnimationPlayer::get_cropped_sprite_bounds(const int x, const int y) const
{
	if (animation_ptr) // only when player has animation to play
	{
		return Sprite::get_cropped_sprite_bounds(get_current_frame(), x, y, get_flip());
	}
	return {0, 0, -1, -1};
}

void AnimationPlayer::to_last_frame()
{
	start_frame = 0;
}

bool AnimationPlayer::is_at_end() const
{
	return (gametime::framecount - start_frame) >= animation_ptr->get_animation_duration();
}

void AnimationPlayer::stop()
{
	animation_ptr = nullptr;
}

void AnimationPlayer::render(const Rectangle& part, const int anchor_x, const int anchor_y, uint16_t* const slice_buffer) const
{
	if (animation_ptr) // only when player has animation to play
	{
		Sprite::render_cropped_sprite_part(get_current_frame(), part, anchor_x, anchor_y, slice_buffer, flags);
	}
}
