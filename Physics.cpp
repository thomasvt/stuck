#include <Physics.h>
#include "TileGrid.h"
#include "CollisionDetector.h"
#include <Particle.h>
#include <Vector.h>
#include <RigidBody.h>

constexpr int gravity8_y = 6; // acceleration per frame
constexpr int max_falling_speed8 = 80;
constexpr  int max_collision_detection_iterations = 2;

// checks if particle is hit, and if the neighbour cell, where we would push the RigidBody to when we fix the penetration, isn't an obstacle itself.
inline bool Physics::can_correct_penetration(const Particle& particle, const VectorI& correction_direction)
{
	return particle.is_hit && !CollisionDetector::is_gridonly_obstacle(VectorI(particle.location_grid.x + correction_direction.x, particle.location_grid.y + correction_direction.y));
}

inline int Physics::get_correction_y(RigidBody& rigid_body)
{
	auto correction_y = 0;
	if (rigid_body.velocity8_.y > 0) {
		// bottom particles:
		auto collision_detected = false;
		for (const auto& particle : rigid_body.particles_bottom)
		{
			if (can_correct_penetration(particle, VectorI(0, -1)))
			{
				collision_detected = true;
				const auto penetration = (particle.location_grid.y << tile_size_pow2) - particle.location.y;
				if (penetration < correction_y)
					correction_y = penetration;
			}
			rigid_body.is_on_floor_ = collision_detected;
		}
	}
	else if (rigid_body.velocity8_.y < 0) {
		// top particles:
		for (const auto& particle : rigid_body.particles_top)
		{
			if (can_correct_penetration(particle, VectorI(0, 1)))
			{

				const auto penetration = ((particle.location_grid.y + 1) << tile_size_pow2) - particle.location.y;
				if (penetration > correction_y)
					correction_y = penetration;
			}
		}
		rigid_body.is_on_floor_ = false;
	}
	return correction_y;
}

inline int Physics::get_correction_x(RigidBody& rigid_body)
{
	auto correction_x = 0;
	if (rigid_body.velocity8_.x < 0) {
		// left particles:
		for (const auto& particle : rigid_body.particles_left)
		{
			if (can_correct_penetration(particle, VectorI(1, 0)))
			{
				const auto penetration_x = ((particle.location_grid.x + 1) << tile_size_pow2) - particle.location.x;
				if (penetration_x > correction_x)
					correction_x = penetration_x;
			}
		}
	}
	else if (rigid_body.velocity8_.x > 0) {
		// right particles:
		for (const auto& particle : rigid_body.particles_right)
		{
			if (can_correct_penetration(particle, VectorI(-1, 0)))
			{
				const auto penetration_x = (particle.location_grid.x << tile_size_pow2) - particle.location.x;
				if (penetration_x < correction_x)
					correction_x = penetration_x;
			}
		}
	}
	return correction_x;
}

bool Physics::process_collisions(RigidBody& rigid_body)
{
	rigid_body.update_particle_locations(rigid_body.location);
	CollisionDetector::detect_hits(rigid_body);

	const auto correction_y = get_correction_y(rigid_body);
	const auto correction_x = get_correction_x(rigid_body);

	if (correction_x == 0 && correction_y == 0)
		return false;

	const auto abs_correction_x = abs(correction_x);
	const auto abs_correction_y = abs(correction_y);

	// pick smallest correction != 0 for least physical incorrectness when correcting rigidbody location.
	if (correction_x == 0 || (correction_y != 0 && abs_correction_y <= abs_correction_x)) {
		rigid_body.location.y += correction_y;
		rigid_body.velocity8_.y = 0;
		rigid_body.location8_.y = rigid_body.location.y << 3;
		return true;
	}

	rigid_body.location.x += correction_x;
	rigid_body.velocity8_.x = 0;
	rigid_body.location8_.x = rigid_body.location.x << 3;
	return true;
}

void Physics::update(RigidBody& rigid_body)
{
	// apply movement
	rigid_body.location8_ = rigid_body.location8_ + rigid_body.velocity8_;
	rigid_body.location = rigid_body.location8_.to_1();

	// we use a simple collision model where we correct penetrations caused by the current location of the RigidBody towards the closest location where the penetration is resolved. We dont use the previous location of the body nor 
	// we fix 1 detected collision per call to process_collisions() because else we would do multiple corrections based on the same original particle-locations (even though an earlier fix already changed the position already)
	//    so, we loop a configured amount of time because one correction can lead to another penetration (eg. in corner), and we redetect hits after each correction
	auto iteration_count = 0;
	while (process_collisions(rigid_body) && iteration_count < max_collision_detection_iterations)
	{
		iteration_count++;
	}

	// update particle locations after potentially changing the rigid_body's location, so that following code uses up to date particles.
	rigid_body.update_particle_locations(rigid_body.location);

	rigid_body.is_on_ladder_ = CollisionDetector::is_ladder(rigid_body.particles_bottom[0].location) || CollisionDetector::is_ladder(rigid_body.location);

	// apply gravity (caution: changing location of this code will change jump height)
	if (rigid_body.is_gravity_enabled)
	{
		rigid_body.velocity8_.y += gravity8_y;
		if (rigid_body.velocity8_.y > max_falling_speed8)
			rigid_body.velocity8_.y = max_falling_speed8;
	}
}
