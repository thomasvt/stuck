#include "Portal.h"
#include <Renderer.h>
#include <Game.h>
#include <Hero.h>
#include <PortalParticles.h>
#include <Rectangle.h>
#include <Camera.h>
#include "Time.h"

Rectangle actors::Portal::measure(const Camera& camera) const
{
	const auto location = VectorI((location_grid.x << tile_size_pow2) + 1, (location_grid.y - 1) << tile_size_pow2);
	const auto location_screen = camera.to_screen(location);
	return { location_screen.x, location_screen.y, location_screen.x + 9, location_screen.y + portal_height-1 };
}

void actors::Portal::update()
{
	// check if player steps inside portal
	const auto x = (location_grid.x << tile_size_pow2) + 1;
	const auto y = (location_grid.y - 1) << tile_size_pow2;
	const auto aabb = Rectangle(x, y, x + 9, y + portal_height);
	if (aabb.contains(Game::scene.hero.get_location()))
	{
		Game::scene.hero.teleport(target_id);
	}
}

void actors::Portal::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
{
	const auto bottom = y + portal_height;
	for (auto particle_x = part.left; particle_x <= part.right; particle_x++)
	{
		const auto particle_index = particle_x - part.left;
		const auto offset = PortalParticles::offsets_[particle_index];
		const auto particle_y = ((gametime::framecount << (particle_x & 1))  // framecount is time, particle_x & 1 makes every odd particle have double the speed
			+ offset) & 0b11111;

		const auto y_in_slice = bottom - particle_y;
		if (y_in_slice < 0 || y_in_slice >= screen_height) // clip if math goes offscreen
			continue;
		const auto slice_ptr = slice_buffer + (y_in_slice * slice_width) + x + particle_x;
		*slice_ptr = particle_color;
		if (y_in_slice < screen_height-1) // clip!!
			*(slice_ptr+slice_width) = particle_tail_color;
	}
}
