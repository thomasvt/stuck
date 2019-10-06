#pragma once
#include <Gamebuino-Meta.h>
#include <Vector.h>
#include <AnimationPlayer.h>

class Camera;
struct Rectangle;

namespace actors {

	class Sparkles
	{
		AnimationPlayer animation_player_;
		VectorI location_;
	public:
		Sparkles();

		void start(VectorI location);

		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
	};

}
