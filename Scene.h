#pragma once
#include <Gamebuino-Meta.h>
#include <Rectangle.h>
#include <Renderer.h>
#include "FlameThrower.h"
#include "Catapult.h"
#include "Sparkles.h"

namespace actors {
	class Fireball;
	class Enemy;

	namespace hero {

		class Hero;
		class Crosshair;

	}
	class InventoryIcon;
	namespace ui {
		class CoinCounter;
		class HealthBar;
		class LevelLabel;
	}
	class Arrow;
	class Billboard;
	class Door;
	class Pickup;
	class Portal;
	class TileGrid;

}

class Background;

class Scene
{

	virtual void render_slice(uint16_t* const buffer, const Rectangle& slice_bounds) const = 0;

	friend class Renderer;

protected:
	void render_actor(uint8_t layer, const actors::Enemy& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	virtual void render_actor(uint8_t layer, const actors::hero::Hero& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Sparkles& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::hero::Crosshair& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::ui::HealthBar& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::ui::CoinCounter& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::InventoryIcon& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::ui::LevelLabel& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Arrow& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Catapult& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const Background& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Billboard& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Door& actor, uint16_t* buffer, const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Fireball& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Pickup& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::FlameThrower& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::Portal& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
	void render_actor(uint8_t layer, const actors::TileGrid& actor, uint16_t* buffer,
	                  const Rectangle& slice_bounds) const;
};

