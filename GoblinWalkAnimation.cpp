#include "GoblinAnimations.h"
#include <Gamebuino-Meta.h>

namespace animations {

	namespace goblin {

		const uint16_t goblin_walk_data0[] PROGMEM = {
			 24, 20, 7, 4, 11, 16, 1,
0x492B, 0x0, 0x491A, 0x8944, 0x8944, 0x492B, 0x0, 0x491A, 0x0, 0x0, 0x0,
0x492B, 0x492B, 0x492B, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x1795, 0x2772, 0x1795,
0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x492B, 0x491A, 0x0, 0x2993, 0x2772, 0x2772,
0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x1795, 0x2993, 0x1795, 0x2772, 0x2772,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x2993, 0x2772, 0x2772, 0x2772, 0x1795,
0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x2772, 0x2772, 0x2772, 0x1795, 0x8551, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x2772, 0x2772, 0x8551, 0x8551, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x492B, 0x2772, 0x8551, 0x8944, 0x0, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x44B2, 0x492B, 0x8944, 0x8551, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0xA7D3, 0xA7D3, 0x44B2, 0x492B, 0x492B, 0x4481, 0x0, 0x0, 0x0, 0x0,
0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x44B2, 0x492B, 0x4481, 0x0, 0x4481, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x0, 0x0,
0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t goblin_walk_data1[] PROGMEM = {
			24, 20, 7, 4, 11, 15, 1,
0x492B, 0x0, 0x491A, 0x8944, 0x8944, 0x492B, 0x0, 0x491A, 0x0, 0x0, 0x0,
0x492B, 0x492B, 0x492B, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x492B, 0x491A, 0x0, 0x1795, 0x2772, 0x1795,
0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x2993, 0x2772, 0x2772,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x1795, 0x2993, 0x1795, 0x2772, 0x2772,
0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x491A, 0x2993, 0x2772, 0x2772, 0x2772, 0x1795,
0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x2772, 0x2772, 0x2772, 0x1795, 0x8551, 0x0,
0x0, 0x492B, 0x8944, 0x492B, 0x2772, 0x2772, 0x8551, 0x8551, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x492B, 0x2772, 0x8551, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x44B2, 0x8944, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0xA7D3, 0xA7D3, 0x492B, 0x492B, 0x492B, 0x4481, 0x0, 0x0, 0x0, 0x0,
0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x44B2, 0x492B, 0x4481, 0x0, 0x4481, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t goblin_walk_data2[] PROGMEM = {
			24, 20, 6, 3, 12, 16, 1,
0x0, 0x492B, 0x0, 0x491A, 0x8944, 0x8944, 0x492B, 0x0, 0x491A, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x492B, 0x492B, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x1795, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x2993, 0x2772, 0x2772, 0x1795,
0x0, 0x0, 0x8944, 0x492B, 0x8944, 0x2772, 0x1795, 0x2993, 0x1795, 0x2772, 0x2772, 0x0,
0x0, 0x492B, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x1795, 0x0,
0x492B, 0x492B, 0x491A, 0x8551, 0x8551, 0x8551, 0x8551, 0x8551, 0x1795, 0x8551, 0x0, 0x0,
0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0xA7D3, 0x0, 0x4481, 0x491A, 0x4481, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x491A, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t goblin_walk_data3[] PROGMEM = {
			24, 20, 4, 4, 12, 16, 1,
0x0, 0x0, 0x492B, 0x0, 0x0, 0x491A, 0x8944, 0x8944, 0x492B, 0x0, 0x491A, 0x0,
0x0, 0x0, 0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0,
0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x8944, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x0, 0x0,
0x492B, 0x492B, 0x2772, 0x2772, 0x2772, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0,
0x0, 0x491A, 0x491A, 0x2772, 0x2772, 0x2772, 0x2772, 0x8944, 0x492B, 0x491A, 0x0, 0x491A,
0x0, 0x0, 0x0, 0x8551, 0x8551, 0x2772, 0x2772, 0x1795, 0x2772, 0x1795, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x44B2, 0x1795, 0x8551, 0x2772, 0x2772, 0x2772, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0xA7D3, 0x0, 0x4481, 0x8551, 0x1795, 0x8551, 0x1795, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x491A, 0x8944, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x0, 0x0,
		};

		const uint16_t goblin_walk_data4[] PROGMEM = {
			24, 20, 6, 4, 12, 16, 1,
0x492B, 0x0, 0x0, 0x491A, 0x8944, 0x8944, 0x492B, 0x0, 0x491A, 0x0, 0x0, 0x0,
0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x8944, 0x8944, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x0, 0x1795, 0x0, 0x0,
0x0, 0x492B, 0x2772, 0x2772, 0x2772, 0x2993, 0x2993, 0x2993, 0x2993, 0x2772, 0x0, 0x0,
0x492B, 0x492B, 0x491A, 0x8551, 0x8551, 0x2772, 0x2772, 0x1795, 0x2772, 0x1795, 0x2772, 0x1795,
0x0, 0x492B, 0x4DBC, 0x492B, 0x2772, 0x492B, 0x8551, 0x2772, 0x2772, 0x2772, 0x8551, 0x0,
0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0x8551, 0x8551, 0x1795, 0x0, 0x0,
0x0, 0x0, 0xA7D3, 0x492B, 0x4481, 0x491A, 0x4481, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x0, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t goblin_walk_data5[] PROGMEM = {
			24, 20, 6, 3, 12, 17, 1,
0x492B, 0x0, 0x0, 0x491A, 0x8944, 0x8944, 0x492B, 0x0, 0x491A, 0x0, 0x0, 0x0,
0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x1795, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x492B, 0x8944, 0x8944, 0x8944, 0x2993, 0x2772, 0x2772, 0x1795,
0x0, 0x0, 0x492B, 0x8944, 0x492B, 0x8944, 0x2993, 0x1795, 0x2772, 0x1795, 0x2772, 0x0,
0x0, 0x492B, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x8551, 0x0,
0x492B, 0x492B, 0x491A, 0x8551, 0x8551, 0x8551, 0x8551, 0x8551, 0x1795, 0x8551, 0x1795, 0x0,
0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0xA7D3, 0x492B, 0x4481, 0x491A, 0x4481, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x0, 0x0, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t* walk_sprites[] PROGMEM = {
			goblin_walk_data0,
			goblin_walk_data1, 
			goblin_walk_data2, 
			goblin_walk_data3, 
			goblin_walk_data4, 
			goblin_walk_data5, 
		};

		Animation walk = Animation(walk_sprites, 6, true, 2);

	}

}