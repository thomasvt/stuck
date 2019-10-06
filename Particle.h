#pragma once

#include <Vector.h>

// a point in physical space, used for physical calculations (not a graphical particle system)
struct Particle
{
	VectorI location, location_grid;
	// penetrating something in the current frame?
	bool is_hit;
};

