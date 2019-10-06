#include "CollisionDetector.h"
#include <Vector.h>
#include <RigidBody.h>
#include <Level.h>
#include <LevelLoader.h>
#include <Game.h>
#include <TileGrid.h>

const Level* CollisionDetector::level_ptr_ = nullptr;

void CollisionDetector::set_level(const Level* level_ptr)
{
	level_ptr_ = level_ptr;
}

void CollisionDetector::detect_hits(RigidBody& rigid_body)
{
	rigid_body.particles_top[0].is_hit = is_obstacle(rigid_body.particles_top[0].location);
	rigid_body.particles_top[1].is_hit = is_obstacle(rigid_body.particles_top[1].location);

	rigid_body.particles_bottom[0].is_hit = is_obstacle(rigid_body.particles_bottom[0].location);
	rigid_body.particles_bottom[1].is_hit = is_obstacle(rigid_body.particles_bottom[1].location);

	rigid_body.particles_left[0].is_hit = is_obstacle(rigid_body.particles_left[0].location);
	rigid_body.particles_left[1].is_hit = is_obstacle(rigid_body.particles_left[1].location);

	rigid_body.particles_right[0].is_hit = is_obstacle(rigid_body.particles_right[0].location);
	rigid_body.particles_right[1].is_hit = is_obstacle(rigid_body.particles_right[1].location);
}

bool CollisionDetector::is_obstacle(const VectorI& location)
{
	auto is_hit = is_gridonly_obstacle(actors::TileGrid::to_grid_coords(location));
	if (!is_hit)
	{
		for (auto j = 0; j < Game::scene.door_count; j++)
		{
			const auto door_aabb = Game::scene.doors[j].get_bounding_box();
			is_hit = door_aabb.contains(location);
			if (is_hit)
				return true;
		}
	}
	return is_hit;
}

bool CollisionDetector::is_wood_obstacle(const VectorI& location_grid)
{
	// for speed, we grab level width and height directly form level data
	const auto i = location_grid.y * level_ptr_->data[0] + location_grid.x;
	return location_grid.y < 0 || location_grid.y >= level_ptr_->data[1]
		|| location_grid.x < 0 || location_grid.x >= level_ptr_->data[0]
		|| level_ptr_->terrain_data[i] >= 32;
}

bool CollisionDetector::is_gridonly_obstacle(const VectorI& location_grid)
{
	// for speed, we grab level width and height directly form level data
	const auto i = location_grid.y * level_ptr_->data[0] + location_grid.x;
	return location_grid.y < 0 || location_grid.y >= level_ptr_->data[1]
		|| location_grid.x < 0 || location_grid.x >= level_ptr_->data[0]
		|| (level_ptr_->terrain_data[i] >= 30 && level_ptr_->terrain_data[i] < 64) || Game::scene.tile_grid.terrain[i] == 44; // block or stairs (stairs can appear dynamically so we need to check on the tilegrid in RAM instead of level definition in flash)
}

bool CollisionDetector::is_ladder(const VectorI& location) {
	const auto corrected_location = VectorI(location.x, location.y - 4); // -4 shifts the grabbing center of Hero higher than body center, because we can use our hands to grab
	// for speed, we grab level width and height directly form level data
	const auto location_grid = actors::TileGrid::to_grid_coords(location); // no correctedlocation for ladders because we sink too low in ladder when on top (cannot walk onto stone floor next to ladder)
	return location_grid.y >= 0 && location_grid.y < level_ptr_->data[1]
		&& location_grid.x >= 0 && location_grid.x < level_ptr_->data[0]
		&& (level_ptr_->terrain_data[location_grid.y * level_ptr_->data[0] + location_grid.x] == level_ladder
			|| (Game::state.arrow_climb_enabled && Game::scene.has_climbable_arrow(corrected_location)));
}

bool CollisionDetector::is_spikes(const VectorI& location_grid) {
	// for speed, we grab level width and height directly form level data
	return location_grid.y >= 0 && location_grid.y < level_ptr_->data[1]
		&& location_grid.x >= 0 && location_grid.x < level_ptr_->data[0]
		&& level_ptr_->terrain_data[location_grid.y * level_ptr_->data[0] + location_grid.x] == level_spikes;
}
