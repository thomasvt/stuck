#pragma once
#include "Animation.h"

namespace animations {

	namespace hero {

		constexpr uint8_t shoot_duration = 8;
		constexpr uint8_t spawn_arrow_time = 2;

		extern Animation idle;
		extern Animation run;
		extern Animation fall;
		extern Animation jump;
		extern Animation climb;
		extern Animation climb_idle;
		extern Animation teleport;
		extern Animation spawn;
		extern Animation dead;
		extern Animation shoot;
	}

}