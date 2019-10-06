#pragma once

namespace actors
{
	namespace hero
	{
		class Hero;
	}
}

struct Particle;
struct VectorI;
class RigidBody;

class Physics
{
	static int get_correction_y(RigidBody& rigid_body);
	static int get_correction_x(RigidBody& rigid_body);
	static bool can_correct_penetration(const Particle& particle, const VectorI& correction_direction);
	static bool process_collisions(RigidBody& rigid_body);
public:
	// applies physics: inertia, forces, resolves collisions and updates environmental querying flags.
	static void update(RigidBody& rigid_body);
};

