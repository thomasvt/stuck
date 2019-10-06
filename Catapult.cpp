#include <Gamebuino-Meta.h>
#include "CatapultAnimation.h"
#include "Catapult.h"
#include <TileGrid.h>
#include <Camera.h>
#include <Rectangle.h>
#include <Game.h>

namespace actors
{
	const Gamebuino_Meta::Sound_FX catapult_sound[] = {
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,181,-2,-57,176,36},
	};

	AnimationPlayer Catapult::animation_player_ = AnimationPlayer();

	Catapult::Catapult() = default; // for static allocation only

	Catapult::Catapult(const Vector8& location) : location_(location)
	{
		animation_player_.set_animation(&animations::catapult);
	}

	void Catapult::update()
	{
		if (VectorI((location_.x << tile_size_pow2) + 8, location_.y << tile_size_pow2).get_manhattan_distance(Game::scene.hero.get_location()) < 15)
		{
			Game::scene.hero.catapult();
			gb.sound.fx(catapult_sound);
		}
	}

	Rectangle Catapult::measure(const Camera& camera) const
	{
		const auto location_screen = camera.to_screen(VectorI((location_.x << tile_size_pow2) + 8, location_.y << tile_size_pow2));
		return animation_player_.get_cropped_sprite_bounds(location_screen.x, location_screen.y);
	}

	void Catapult::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		animation_player_.render(part, x, y, slice_buffer);
	}
}
