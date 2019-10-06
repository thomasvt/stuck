#include <Gamebuino-Meta.h>
#include "Pickup.h"
#include "GemSprites.h"
#include <Camera.h>
#include <Sprite.h>
#include <Vector.h>
#include <Rectangle.h>
#include <Game.h>
#include <Inventory.h>
#include "Time.h"

namespace actors {

	const Gamebuino_Meta::Sound_FX collect_sound[] PROGMEM = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,-10,0,89,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,-10,0,89,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,-10,0,89,5},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,-10,0,22,10},
	};

	void Pickup::update()
	{
		if (type_ == 255)
			return;

		const auto location = get_location();
		const auto distance = Game::scene.hero.get_location().get_distance(location);
		if (distance.x < 8 && distance.y < 8)
		{
			gb.sound.fx(collect_sound);
			Game::state.inventory.collect_pickup(type_);
			Game::scene.spawn_sparkles(location);
			switch (type_)
			{
			case 4:
				Game::state.air_jump_count = 1;
				Game::scene.hero.reset_air_jumps();
				break;
			case 5:
				Game::state.air_jump_count = 2;
				Game::scene.hero.reset_air_jumps();
				break;
			case 6:
				Game::state.arrow_climb_enabled = true;
				break;
			}

			type_ = 255;
		}
	}

	inline VectorI Pickup::get_location() const
	{
		return { 
			(location_grid_.x << tile_size_pow2) + 8,
			(location_grid_.y << tile_size_pow2) + 9 - offset_y_wave[(gametime::framecount >> 2) & 0b111]
		};
	}

	Rectangle Pickup::measure(const Camera& camera) const
	{
		if (type_ == 255)
			return { 0, 0, -1, -1 };
		const auto location_screen = camera.to_screen(get_location());
		return Sprite::get_cropped_sprite_bounds(sprites::pickups[type_], location_screen.x, location_screen.y);
	}

	void Pickup::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		Sprite::render_cropped_sprite_part(sprites::pickups[type_], part, x, y, slice_buffer);
	}
}
