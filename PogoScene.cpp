#include "PogoScene.h"
#include <Debug.h>
#include <EnemyDefinition.h>
#include "Texts.h"
#include <Renderer.h>
#include <Game.h>
#include "TriggerController.h"
#include <Time.h>

const char too_many_portals_msg[] PROGMEM = "too many portals";
const char too_many_enemies_msg[] PROGMEM = "too many enemies";
const char too_many_doors_msg[] PROGMEM = "too many doors";
const char too_many_pickups_msg[] PROGMEM = "too many pickups";
const char too_many_flamethrowers_msg[] PROGMEM = "too many flamethrowers";
const char too_many_catapults_msg[] PROGMEM = "too many catapults";
const char teleport_out_of_bounds_msg[] PROGMEM = "level_id/spawn_id out of bounds";

const Gamebuino_Meta::Sound_FX fireball_shoot_sound[] = {
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,208,-2,5,16,50},
};

void PogoScene::initialize(const VectorI size)
{
	this->size = size;
	clear_portals();
	clear_enemies();
	clear_doors();
	clear_pickups();
	clear_arrows();
	clear_fireballs();
	clear_flamethrowers();
	clear_catapults();
	for (auto i = 0; i < 4; i++)
		inventory_icons[i] = actors::InventoryIcon(i);
}

void PogoScene::add_portal(const Vector8 location_grid, const uint8_t target_level_id, const uint8_t target_spawn_id)
{
	if (portal_count == max_portal_count)
		Debug::throw_fatal(too_many_portals_msg);
	if (target_level_id > 31 || target_spawn_id > 7)
		Debug::throw_fatal(teleport_out_of_bounds_msg);
	portals[portal_count] = actors::Portal();
	portals[portal_count].location_grid = location_grid;
	portals[portal_count].target_id = target_level_id << 3 | target_spawn_id;
	portal_count++;
}

void PogoScene::add_enemy(const Vector16 location, const actors::EnemyDefinition& enemy_definition, bool is_dead)
{
	if (enemy_count == max_enemy_count)
		Debug::throw_fatal(too_many_enemies_msg);
	enemies[enemy_count] = actors::Enemy();
	enemies[enemy_count].location = location;
	enemies[enemy_count].set_definition(&enemy_definition);
	if (is_dead)
		enemies[enemy_count].set_already_dead();
	enemy_count++;
}

void PogoScene::add_door(const Vector16& location, const int color, bool is_open)
{
	if (door_count == max_door_count)
		Debug::throw_fatal(too_many_doors_msg);
	doors[door_count] = actors::Door(location, color);
	if (is_open) 
		doors[door_count].open(true);
	door_count++;
}

void PogoScene::add_pickup(const Vector8& location, const int type)
{
	if (pickup_count == max_pickup_count)
		Debug::throw_fatal(too_many_pickups_msg);
	pickups[pickup_count] = actors::Pickup(location, type);
	pickup_count++;
}

void PogoScene::add_flamethrower(const Vector8& location_grid, const uint8_t& fire_offset)
{
	if (flamethrower_count == max_flamethrower_count)
		Debug::throw_fatal(too_many_flamethrowers_msg);
	flamethrowers[flamethrower_count] = actors::FlameThrower(location_grid, fire_offset);
	flamethrower_count++;
}

void PogoScene::add_catapult(const Vector8& location)
{
	if (catapult_count == max_catapult_count)
		Debug::throw_fatal(too_many_catapults_msg);
	catapults[catapult_count] = actors::Catapult(location);
	catapult_count++;
}

void PogoScene::clear_portals()
{
	portal_count = 0;
}

void PogoScene::clear_enemies()
{
	enemy_count = 0;
}

void PogoScene::clear_doors()
{
	door_count = 0;
}

void PogoScene::clear_pickups()
{
	pickup_count = 0;
}

void PogoScene::clear_arrows()
{
	arrow_control = 0;
}

void PogoScene::clear_fireballs()
{
	fireball_control = 0;
}

void PogoScene::clear_flamethrowers()
{
	flamethrower_count = 0;
}

void PogoScene::clear_catapults()
{
	catapult_count = 0;
}

void PogoScene::check_to_close_message()
{
	if (message.sprite_ptr != nullptr 
		&& gametime::framecount - message_start_ > 15  // prevent closing message first half second, against accidentally closing it
		&& gb.buttons.pressed(Button::a))
	{
		message.sprite_ptr = nullptr; 
		Game::reload_last_save() ;// currently only message in the game is You Die, so perform afterdeath logic when A pressed
	}
}

void PogoScene::update()
{
	gametime::framecount++;
	hero.update();
	TriggerController::update();
	level_label.update();
	for (auto i = 0; i < portal_count; i++)
		portals[i].update();
	for (auto i = 0; i < door_count; i++)
		doors[i].update();
	for (auto i = 0; i < pickup_count; i++)
		pickups[i].update();
	for (auto i = 0; i < flamethrower_count; i++)
		flamethrowers[i].update();
	for (auto i = 0; i < catapult_count; i++)
		catapults[i].update();
	for (auto i = 0; i < enemy_count; i++)
	{
		if ((gametime::framecount % enemies[i].get_update_interval()) == (i % enemies[i].get_update_interval())) // call each enemy only every other frame, but distribute enemies over all frames.
			enemies[i].update();
	}
	camera.update();
	for (auto i = 0; i < max_arrow_count; i++)
	{
		const uint8_t flag = 1 << i;
		if (arrow_control & flag)
			arrows[i].update();
	}
	for (auto i = 0; i < max_fireball_count; i++)
	{
		const uint16_t flag = 1 << i;
		if (fireball_control & flag)
			fireballs[i].update();
	}

	check_to_close_message();
}

void PogoScene::render_slice(uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	render_actor(0, background, buffer, slice_bounds);
	render_actor(0, tile_grid, buffer, slice_bounds);	
	
	for (auto i = 0; i < portal_count; i++)
		render_actor(0, portals[i], buffer, slice_bounds);

	for (auto i = 0; i < pickup_count; i++)
		render_actor(0, pickups[i], buffer, slice_bounds);

	for (auto i = 0; i < flamethrower_count; i++)
		render_actor(0, flamethrowers[i], buffer, slice_bounds);

	for (auto i = 0; i < max_fireball_count; i++)
	{
		const uint16_t flag = 1 << i;
		if (fireball_control & flag)
			render_actor(0, fireballs[i], buffer, slice_bounds);
	}

	for (auto i = 0; i < enemy_count; i++)
		render_actor(0, enemies[i], buffer, slice_bounds);

	for (auto i = 0; i < door_count; i++)
		render_actor(0, doors[i], buffer, slice_bounds);

	for (auto i = 0; i < max_arrow_count; i++)
	{
		const uint8_t flag = 1 << i;
		if (arrow_control & flag)
			render_actor(0, arrows[i], buffer, slice_bounds);
	}

	for (auto i = 0; i < catapult_count; i++)
		render_actor(0, catapults[i], buffer, slice_bounds);

	render_actor(0, hero, buffer, slice_bounds);
	render_actor(0, sparkles, buffer, slice_bounds);
	render_actor(1, tile_grid, buffer, slice_bounds);

	// HUD
	render_actor(0, crosshair, buffer, slice_bounds);
	render_actor(0, health_bar, buffer, slice_bounds);
	render_actor(0, coin_counter, buffer, slice_bounds);

	for (auto i = 0; i < 4; i++)
		render_actor(0, inventory_icons[i], buffer, slice_bounds);

	if (level_label.is_visible) render_actor(0, level_label, buffer, slice_bounds);
	if (message.sprite_ptr != nullptr) render_actor(0, message, buffer, slice_bounds);
}

void PogoScene::show_message()
{
	message_start_ = gb.frameCount;
	message.sprite_ptr = text::you_died_sprite;
	message.location = Vector8(screen_center.x - (text::you_died_sprite[width_idx] >> 1), screen_center.y - (text::you_died_sprite[height_idx] >> 1));
}

void PogoScene::shoot_arrow(const VectorI& location, const VectorI velocity)
{
	const auto new_arrow_index = ((arrow_control >> 2) + 1) & 0b1; // (current value + 1) % 2
	arrows[new_arrow_index] = actors::Arrow(location, velocity);
	arrow_control = (new_arrow_index << 2) | (arrow_control & 0b11) | (1 << new_arrow_index);
}

void PogoScene::destroy_arrow(const actors::Arrow* arrow_ptr)
{
	for (auto i = 0; i < max_arrow_count; i++)
	{
		if (&arrows[i] == arrow_ptr)
		{
			const uint8_t flag = 1 << i;
			arrow_control &= ~flag; // inverted to put only the one bit to 0.
			return;
		}
	}
}

void PogoScene::shoot_fireball(const Vector16& location, const actors::direction direction)
{
	const auto new_fireball_index = ((fireball_control >> 12) + 1) % 12;
	fireballs[new_fireball_index] = actors::Fireball(location, direction);
	fireball_control = (new_fireball_index << 12) | (fireball_control & 0b111111111111) | (1 << new_fireball_index);
	const auto distance = camera.location.to_vector_i().get_manhattan_distance(VectorI(location.x, location.y));
	if (distance < 170)
	{
		gb.sound.fx(fireball_shoot_sound);
	}
}

void PogoScene::destroy_fireball(const actors::Fireball* fireball_ptr)
{
	for (auto i = 0; i < max_fireball_count; i++)
	{
		if (&fireballs[i] == fireball_ptr)
		{
			const uint16_t flag = 1 << i;
			fireball_control &= ~flag; // inverted to put only the one bit to 0.
			return;
		}
	}
}

void PogoScene::spawn_sparkles(const VectorI& location)
{
	sparkles = actors::Sparkles();
	sparkles.start(location);
}

