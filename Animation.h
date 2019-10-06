#pragma once
#include <Gamebuino-Meta.h>

struct Animation
{
private:
	uint8_t settings_;
public:
	const uint16_t** frames;

	// frame_interval: power of 2 of game frames between animation frames: 0 = 1 frame = 30fps, 1 = 2 frames = 15fps, 2 = 4 frames = +-7 fps, 3 = 8 frames = +-4fps
	Animation(const uint16_t** frames, const uint8_t frame_count, const bool repeat = true, const uint8_t frame_interval_pow2 = 0) : frames(frames)
	{
		const auto repeat_mask = repeat ? 0b10000000 : 0;
		const auto interval_mask = frame_interval_pow2 << 5;
		settings_ = repeat_mask | interval_mask | frame_count;
	}

	bool get_repeat() const
	{
		return settings_ & 0b10000000;
	}

	int get_frame_count() const
	{
		return settings_ & 0b00011111;
	}

	int get_interval_pow2() const
	{
		return (settings_ & 0b01100000) >> 5;
	}

	// returns the duration of this animation in game frames (=animation frame count * frame interval).
	int get_animation_duration() const
	{
		return get_frame_count() << get_interval_pow2();
	}
};

