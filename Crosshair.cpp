#include "Crosshair.h"
#include <Game.h>
#include <Hero.h>
#include <Renderer.h>

namespace actors {
	namespace hero {

		Rectangle Crosshair::measure(const Camera& camera) const
		{
			if (Game::scene.hero.aim_state_ == Hero::aim_state::aiming)
			{
				const auto aim_velocity = Game::scene.hero.get_aim_velocity(true);
				const auto location_screen = camera.to_screen(VectorI(Game::scene.hero.rigid_body.location.x + aim_velocity.x, Game::scene.hero.rigid_body.location.y + aim_velocity.y));
				return { location_screen.x, location_screen.y, location_screen.x, location_screen.y };
			}
			return { 0, 0, -1, -1 };
		}

		void Crosshair::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
		{
			slice_buffer[(y * slice_width) + x] = 0xFFFF;
		}
	}
}