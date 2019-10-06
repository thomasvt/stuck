#include "Enemy.h"
#include <Camera.h>
#include "GoblinDefinition.h"
#include <Rectangle.h>
#include <Game.h>

namespace actors {

	const Gamebuino_Meta::Sound_FX hit_sound[] PROGMEM = { {Gamebuino_Meta::Sound_FX_Wave::NOISE,0,255,-10,74,0,5} };

	void Enemy::update()
	{
		if (location.to_vector_i().get_manhattan_distance(Game::scene.hero.get_location()) > 300)
			return;

		enemy_definition_ptr_->update(*this);
		animation_player.set_flash(false);
	}

	Rectangle Enemy::measure(const Camera& camera) const
	{
		const auto location_screen = camera.to_screen(location.to_vector_i());
		return animation_player.get_cropped_sprite_bounds(location_screen.x, location_screen.y);
	}

	void Enemy::render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const
	{
		animation_player.render(part, x, y, slice_buffer);
	}

	void Enemy::set_definition(const EnemyDefinition* definition)
	{
		enemy_definition_ptr_ = definition;
		definition->initialize(*this);
	}

	void Enemy::set_already_dead()
	{
		enemy_definition_ptr_->die(*this, true);
	}

	void Enemy::hit(const int hitpoints)
	{
		if (state == EnemyState::die)
			return;

		gb.sound.fx(hit_sound);
		auto health = get_health() - hitpoints;
		if (health < 0)
			health = 0;
		if (health == 0)
			enemy_definition_ptr_->die(*this);
		set_health(health);
		animation_player.set_flash(true);
	}
}
