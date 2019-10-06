#include "Scene.h"
#include <Game.h>
#include <Fireball.h>
#include <Enemy.h>
#include <Hero.h>
#include <Crosshair.h>
#include <HealthBar.h>
#include <InventoryIcon.h>
#include <LevelLabel.h>
#include <Arrow.h>
#include <Background.h>
#include <Door.h>
#include <Fireball.h>
#include <Pickup.h>
#include <Portal.h>
#include <TileGrid.h>

void Scene::render_actor(const uint8_t layer, const actors::Enemy& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::hero::Hero& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Sparkles& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::hero::Crosshair& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::ui::HealthBar& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::ui::CoinCounter& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::InventoryIcon& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::ui::LevelLabel& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Arrow& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Catapult& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const Background& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Billboard& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Door& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Fireball& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Pickup& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::FlameThrower& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::Portal& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}

void Scene::render_actor(const uint8_t layer, const actors::TileGrid& actor, uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	const auto bounds = actor.measure(Game::scene.camera);
	const auto intersection_bounds = slice_bounds.intersect(bounds);
	if (intersection_bounds.is_empty())
		return;
	const auto sprite_part = intersection_bounds.subtract(bounds.left, bounds.top);
	actor.render(layer, sprite_part, bounds.left - slice_bounds.left, bounds.top, buffer);
}
