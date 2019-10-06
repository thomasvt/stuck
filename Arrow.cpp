#include "Arrow.h"
#include <Camera.h>
#include "ArrowSprites.h"
#include "CollisionDetector.h"
#include <TileGrid.h>
#include <Game.h>

namespace actors
{
	const Gamebuino_Meta::Sound_FX hit_wall_sound[] PROGMEM = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,0,636,2},
	};

	constexpr int gravity8 = 2;

	const uint8_t angle_lookup[56] = {  // this is an angle lookup by velocity vector ([-3..3], [-3..3]) so we need 7x7 but make 8x7 (and ignore last column) so we can use << 3 instead of * 7
		6, 5, 5, 4, 3, 3, 2, 0,
		7, 6, 5, 4, 3, 2, 1, 0,
		7, 7, 6, 4, 2, 1, 1, 0,
		8, 8, 8, 0, 0, 0, 0, 0,
		9, 9, 10, 12, 14, 15, 15, 0,
		9, 10, 11, 12, 13, 14, 15, 0,
		10, 11, 11, 12, 13, 13, 14, 0
	};

	Arrow::Arrow()
	{
		location8 = VectorI();
		velocity8_ = VectorI();
		angle_ = 0;
		attached_ = false;
	}

	Arrow::Arrow(const VectorI location, const VectorI velocity8) {
		location8 = location.to_8();
		velocity8_ = velocity8.to_8();
		angle_ = 0;
		attached_ = false;
	}

	Rectangle Arrow::measure(const Camera& camera) const
	{
		const auto location_screen = camera.to_screen(location8.to_1());
		return Sprite::get_cropped_sprite_bounds(sprites::arrows[angle_], location_screen.x, location_screen.y);
	}

	void Arrow::update()
	{
		if (attached_) // once stuck in wall, arrow doesn't move anymore
			return;

		const auto location = location8.to_1();
		// collide with wall?
		if (CollisionDetector::is_obstacle(location))
		{
			gb.sound.fx(hit_wall_sound);
			const auto location_grid = TileGrid::to_grid_coords(location);
			if (CollisionDetector::is_wood_obstacle(location_grid)) // get stuck? only in non dynamic objects!
			{
				if (angle_ < 2 || angle_ > 14) // arrow moving right horizontally 
				{
					location8 = VectorI(((location_grid.x - 1) << tile_size_pow2) + half_tile_size + 3, location.y).to_8();
					attached_ = true;
					return;
				}
				if (angle_ < 10 && angle_ > 6)  // arrow moving left horizontally 
				{
					location8 = VectorI(((location_grid.x + 1) << tile_size_pow2) + half_tile_size - 4, location.y).to_8();
					attached_ = true;
					return;
				}
			}
			Game::scene.destroy_arrow(this);
		}

		// hit an enemy?
		for (auto i = 0; i < Game::scene.enemy_count; i++)
		{
			if (Game::scene.enemies[i].state == EnemyState::die)
				continue;
			const auto distance = Game::scene.enemies[i].location.to_vector_i().get_distance(location);
			if (distance.x < 8 && distance.y < 10)
			{
				Game::scene.enemies[i].hit(1);
				Game::scene.destroy_arrow(this);
				break; // prevent destroying multiple times (and hitting multiple enemies)
			}
		}

		location8 = location8.add(velocity8_);
		velocity8_.y += gravity8;

		angle_ = get_angle(velocity8_.x, velocity8_.y);

	}

	inline uint8_t Arrow::get_angle(int x, int y)
	{
		// this is a quite heavy algorithm for finding the angle from a vector. 
		// On a device with floating point hardware, you would do this with atan2(). But doing that is heavy too because we don't have the hardware instructions. 
		// with atan2, we need to convert radians to our angle-index too (more float math), so I made a guess that it would be faster with the following algorithm:

		// normalize vector so that both x and y are within [-3,3]
		auto abs_x = x < 0 ? -x : x;
		auto abs_y = y < 0 ? -y : y;
		auto reference = abs_x > abs_y ? abs_x : abs_y;
		while (reference > 3) // we need to normalize using positive values because -1 >> 1 == -1 and we want 0 in that case
		{
			reference = reference >> 1;
			abs_x = abs_x >> 1;
			abs_y = abs_y >> 1;
		}

		x = x < 0 ? -abs_x : abs_x;
		y = y < 0 ? -abs_y : abs_y;

		// lookup angle from table
		const auto angle = angle_lookup[((y + 3) << 3) + x + 3];
		return angle;
	}

	void Arrow::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		Sprite::render_cropped_sprite_part(sprites::arrows[angle_], part, x, y, slice_buffer);
	}
}
