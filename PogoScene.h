#pragma once
#include "Background.h"
#include "TileGrid.h"
#include <Hero.h>
#include "LevelLabel.h"
#include "Portal.h"
#include <Camera.h>
#include "Enemy.h"
#include "HealthBar.h"
#include "Arrow.h"
#include <Crosshair.h>
#include "Door.h"
#include "Pickup.h"
#include "InventoryIcon.h"
#include "Scene.h"
#include "Fireball.h"
#include "FlameThrower.h"
#include "CoinCounter.h"
#include <billboard.h>
#include "Catapult.h"
#include "Sparkles.h"

constexpr int max_portal_count = 7;
constexpr int max_enemy_count = 16;
constexpr int max_door_count = 6;
constexpr int max_arrow_count = 2;
constexpr int max_fireball_count = 12;
constexpr int max_pickup_count = 6;
constexpr int max_flamethrower_count = 10;
constexpr int max_catapult_count = 20;

class PogoScene : public Scene
{
	uint32_t message_start_ = 0;
public:
	VectorI size;
	Camera camera = Camera(*this);
	Background background;
	actors::TileGrid tile_grid;
	actors::hero::Hero hero;
	actors::hero::Crosshair crosshair; // the little dot that shows the shooting angle for the player
	actors::ui::LevelLabel level_label;
	actors::ui::HealthBar health_bar;
	actors::ui::CoinCounter coin_counter;
	actors::Billboard message;
	actors::Portal portals[max_portal_count];
	actors::Enemy enemies[max_enemy_count];
	actors::Door doors[max_door_count];
	actors::Pickup pickups[max_pickup_count];
	actors::Arrow arrows[max_arrow_count];
	actors::Fireball fireballs[max_fireball_count];
	actors::InventoryIcon inventory_icons[4];
	actors::FlameThrower flamethrowers[max_flamethrower_count];
	actors::Catapult catapults[max_catapult_count];
	actors::Sparkles sparkles;
	uint8_t portal_count = 0;
	uint8_t enemy_count = 0;
	uint8_t door_count = 0;
	uint8_t pickup_count = 0;
	uint8_t flamethrower_count = 0;
	uint8_t arrow_control = 0; // managing byte: high 6 bit = rotating cursor with index for next spawned arrow. low 2 bit = up to 2 arrows' alive-state yes/no
	uint16_t fireball_control = 0; // managing byte: high 4 bit = rotating cursor with index for next spawned fireball. low 12 bit = up to 12 fireball' alive-state yes/no
	uint8_t catapult_count = 0;

	void initialize(VectorI size);
	void add_portal(Vector8 location_grid, const uint8_t target_level_id, const uint8_t target_spawn_id);
	void add_enemy(Vector16 location, const actors::EnemyDefinition& enemy_definition, bool is_dead);
	void add_door(const Vector16& location, int color, bool is_open);
	void add_pickup(const Vector8& location, int type);
	void add_flamethrower(const Vector8& location_grid, const uint8_t& fire_offset);
	void add_catapult(const Vector8& vector8);
	void clear_portals();
	void clear_enemies();
	void clear_doors();
	void clear_pickups();
	void clear_arrows();
	void clear_fireballs();
	void clear_flamethrowers();
	void clear_catapults();
	void check_to_close_message();
	void update();
	void render_slice(uint16_t* const buffer, const Rectangle& slice_bounds) const override;
	void show_message();
	void shoot_arrow(const VectorI& location, const VectorI velocity);
	void shoot_fireball(const Vector16& location, const actors::direction direction);
	void destroy_arrow(const actors::Arrow* arrow_ptr);
	void destroy_fireball(const actors::Fireball* fireball_ptr);
	void spawn_sparkles(const VectorI& location);

	bool has_climbable_arrow(const VectorI& location) const
	{
		return (arrow_control & 0b1 && (location.get_manhattan_distance(arrows[0].location8.to_1()) < 8))
			|| (arrow_control & 0b10 && (location.get_manhattan_distance(arrows[1].location8.to_1()) < 8));
	}

	
};

