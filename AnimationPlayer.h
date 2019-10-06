#pragma once
#include <Animation.h>
#include <Gamebuino-Meta.h>

struct Rectangle;
class Sprite;

class AnimationPlayer
{
	const uint16_t* get_current_frame() const;
public:
	const Animation* animation_ptr = nullptr; // animation that is being played
	uint32_t start_frame = 0; // game frame at which animation started playing (we downcast so we go from 12 to 8 bytes for this struct)
	// render flags: bit 0 = flip horizontally, bit 1 = show all pixels in a bright color (flash effect)
	uint8_t flags = 0;

	void stop();
	// starts an animation. If the given animation is already running, it continues playing (no restart).
	void set_animation(const Animation* animation_ptr, const bool reset_frame_position = true);
	void render(const Rectangle& part, const int anchor_x, const int anchor_y, uint16_t* const slice_buffer) const;
	Rectangle get_cropped_sprite_bounds(const int x, const int y) const;
	// makes a non repeating animation jump to the last frame
	void to_last_frame();
	// is non-repeating animation at last frame or beyond?
	bool is_at_end() const;

	void set_flash(const bool flash)
	{
		if (flash)
			flags |= 0b10;
		else
			flags &= 0b11111101;
	}

	bool get_hurt() const {
		return flags & 0b10;
	}

	void set_flip(const bool flip)
	{
		if (flip)
			flags |= 0b1;
		else
			flags &= 0b11111110;
	}

	bool get_flip() const {
		return flags & 0b1;
	}
};

