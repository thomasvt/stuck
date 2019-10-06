#pragma once
#include <Gamebuino-Meta.h>
#include <Vector.h>
#include <AnimationPlayer.h>

class Camera;
struct Rectangle;

namespace actors {

	class Catapult
	{
		static AnimationPlayer animation_player_;
		Vector8 location_ = Vector8();
	public:
		Catapult();
		explicit Catapult(const Vector8& location);

		void update();
		Rectangle measure(const Camera& camera) const;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
	};

}
