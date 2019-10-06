#pragma once
#include <AnimationPlayer.h>
#include <Vector.h>
#include <Gamebuino-Meta.h>

class Camera;
struct Rectangle;

namespace actors {

	enum class direction
	{
		up, down, right, left
	};

	class Fireball
	{
		static AnimationPlayer animation_player_;
		Vector16 location_;
		direction direction_; // can go up left or right. down is not supported.
	public:
		Fireball();
		Fireball(const Vector16& location, direction direction);

		void update() ;
		Rectangle measure(const Camera& camera) const ;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const ;
	};

}
