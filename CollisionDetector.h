#pragma once

namespace actors
{
	class TileGrid;
}

struct Level;
class RigidBody;
struct VectorI;
struct Particle;

class CollisionDetector
{
	const static Level* level_ptr_;
public:
	static void set_level(const Level* level_ptr);

	// updates is_hit flag on all particles of the rigid-body
	static void detect_hits(RigidBody& rigid_body);
	static bool is_obstacle(const VectorI& location);
	static bool is_wood_obstacle(const VectorI& location_grid);
	// faster than is_obstacle, but does not take dynamic actors into account.
	static bool is_gridonly_obstacle(const VectorI& location_grid);
	static bool is_ladder(const VectorI& location_grid);
	static bool is_spikes(const VectorI& location_grid);
};

