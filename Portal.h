#pragma once
#include <Vector.h>
#include <Gamebuino-Meta.h>

class Camera;
struct Rectangle;

namespace actors {
	class PortalParticles;

	constexpr uint16_t particle_color = 0x9F5F;
	constexpr uint16_t particle_tail_color = 0x5E46;

	class Portal
	{
		
	public:
		Vector8 location_grid;
		uint8_t target_id;

		Rectangle measure(const Camera& camera) const;
		void update();
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const;
	};

}