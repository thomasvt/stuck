#pragma once

namespace actors {

	constexpr int portal_height = 32;
	constexpr int portal_particle_count = 14;

	class PortalParticles
	{
		static char offsets_[portal_particle_count];

		friend class Portal;
	public:
		static void initialize();
	};

}