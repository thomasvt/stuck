#include "PortalParticles.h"
#include <Gamebuino-Meta.h>

namespace actors {

	char PortalParticles::offsets_[portal_particle_count] = {};

	void PortalParticles::initialize()
	{
		offsets_[0] = 16;
		offsets_[1] = 31; 
		offsets_[2] = 5;
		offsets_[3] = 18;
		offsets_[4] = 2;
		offsets_[5] = 6;
		offsets_[6] = 25;
		offsets_[7] = 15;
		offsets_[8] = 30;
		offsets_[9] = 27;
		offsets_[10] = 1;
		offsets_[11] = 21;
		offsets_[12] = 12;
		offsets_[13] = 9;
	}
}
