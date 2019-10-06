#pragma once

#include <Vector.h>
#include "Particle.h"

// 8 particles used by collision detection, so we have a rectangle with rounded corners (roughly)
//   *------*
//  /        \
// *          *
// |          |   * = a collision particle
// |          |
// |          |
// |          |
// |          |
// *          *
//  \        /
//   *------*

class RigidBody
{
	int* x_;
	int* y_;

	// physical properties are stored *8 (<<3) when used in physics, so we can use 3 bits for fraction.
	VectorI location8_ = {};
	VectorI velocity8_ = {};
	bool is_on_floor_ = false;
	bool is_on_ladder_ = false;

	friend class Physics;
public:
	// accepts the coords of all cornerpoints (see drawing above) per dimension: form left to right and from top to bottom
	RigidBody(int x[4], int y[4]);

	bool is_gravity_enabled = true;
	bool is_on_floor() const;
	bool is_on_ladder() const;
	VectorI location = {};
	Particle particles_top[2];
	Particle particles_bottom[2];
	Particle particles_left[2];
	Particle particles_right[2];

	// updates particle locations and location_grids to match new rigidbody location
	void update_particle_locations(VectorI rigid_body_location);
	void set_velocity8_x(int x);
	void set_velocity8_y(int y);
	bool is_going_up() const;
	void set_location(const VectorI& location);
};

