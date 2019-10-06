#include "RigidBody.h"
#include <TileGrid.h>

RigidBody::RigidBody(int x[4], int y[4])
: x_(x), y_(y)
{
}

bool RigidBody::is_on_floor() const
{
	return is_on_floor_;
}

bool RigidBody::is_on_ladder() const
{
	return is_on_ladder_;
}

void RigidBody::update_particle_locations(const VectorI rigid_body_location)
{
	particles_top[0].location = rigid_body_location + VectorI(x_[1], y_[0]);
	particles_top[0].location_grid = actors::TileGrid::to_grid_coords(particles_top[0].location);
	particles_top[1].location = rigid_body_location + VectorI(x_[2], y_[0]);
	particles_top[1].location_grid = actors::TileGrid::to_grid_coords(particles_top[1].location);

	particles_bottom[0].location = rigid_body_location + VectorI(x_[1], y_[3]);
	particles_bottom[0].location_grid = actors::TileGrid::to_grid_coords(particles_bottom[0].location);
	particles_bottom[1].location = rigid_body_location + VectorI(x_[2], y_[3]);
	particles_bottom[1].location_grid = actors::TileGrid::to_grid_coords(particles_bottom[1].location);

	particles_left[0].location = rigid_body_location + VectorI(x_[0], y_[1]);
	particles_left[0].location_grid = actors::TileGrid::to_grid_coords(particles_left[0].location);
	particles_left[1].location = rigid_body_location + VectorI(x_[0], y_[2]);
	particles_left[1].location_grid = actors::TileGrid::to_grid_coords(particles_left[1].location);

	particles_right[0].location = rigid_body_location + VectorI(x_[3], y_[1]);
	particles_right[0].location_grid = actors::TileGrid::to_grid_coords(particles_right[0].location);
	particles_right[1].location = rigid_body_location + VectorI(x_[3], y_[2]); 
	particles_right[1].location_grid = actors::TileGrid::to_grid_coords(particles_right[1].location);
}

void RigidBody::set_velocity8_x(int x)
{
	velocity8_.x = x;
}

void RigidBody::set_velocity8_y(int y)
{
	velocity8_.y = y;
}

bool RigidBody::is_going_up() const
{
	return velocity8_.y < 0;
}

void RigidBody::set_location(const VectorI& location)
{
	this->location = location;
	this->location8_ = location.to_8();
}
