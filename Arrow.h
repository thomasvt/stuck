#pragma once
#include <Vector.h>
#include <Rectangle.h>

class Camera;

namespace actors
{
	class Arrow
	{
	public:
		VectorI location8;
		VectorI velocity8_;
		uint8_t angle_;
		bool attached_;

		Arrow();
		explicit Arrow(VectorI location, VectorI velocity);
		Rectangle measure(const Camera& camera) const ;
		void update() ;
		static uint8_t get_angle(int x, int y);
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const ;
	};
}

