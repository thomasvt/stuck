#include <FlameThrower.h>
#include <TileGrid.h>
#include <Camera.h>
#include "FlameThrowerAnimations.h"
#include <Game.h>
#include <Scene.h>
#include "Time.h"

namespace actors {

	FlameThrower::FlameThrower(const Vector8& location_grid, const uint8_t& fire_offset) : position_grid(location_grid), fire_offset(fire_offset)
	{
		animation_player.set_animation(&animations::flamethrower_idle);
	}

	void FlameThrower::update()
	{
		if (animation_player.animation_ptr == &animations::flamethrower_idle && ((gametime::framecount - fire_offset) & 0b111111) == 0)
		{
			animation_player.set_animation(&animations::flamethrower_shoot);
		}
		else if (animation_player.animation_ptr == &animations::flamethrower_shoot)
		{
			const auto current_time = gametime::framecount - animation_player.start_frame;
			const auto shoot_animation_duration = animations::flamethrower_shoot.get_animation_duration();
			const auto half_shoot_animation_duration = shoot_animation_duration >> 1;
			if (current_time == half_shoot_animation_duration)
			{
				Game::scene.shoot_fireball(Vector16((position_grid.x << tile_size_pow2) + 8, (position_grid.y << tile_size_pow2) + 8), direction::up);
			}
			else if (current_time == shoot_animation_duration)
			{
				animation_player.set_animation(&animations::flamethrower_idle);
			}
		}
	}

	Rectangle FlameThrower::measure(const Camera& camera) const
	{
		const auto position_screen = camera.to_screen(VectorI(position_grid.x << tile_size_pow2, position_grid.y << tile_size_pow2));
		return animation_player.get_cropped_sprite_bounds(position_screen.x, position_screen.y);
	}

	void FlameThrower::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		animation_player.render(part, x, y, slice_buffer);
	}
}
