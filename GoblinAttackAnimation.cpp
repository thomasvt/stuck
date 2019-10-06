#include "GoblinAnimations.h"
#include <Gamebuino-Meta.h>

namespace animations {

	namespace goblin {

		const uint16_t goblin_attack_data0[] PROGMEM = {
			24, 20, 0, 0, 15, 20, 1,
0x1795, 0x2993, 0x1795, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x2993, 0x2993, 0x2772, 0x2772, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x1795, 0x2993, 0x2772, 0x1795, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x8551, 0x2772, 0x2993, 0x2772, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x1795, 0x2772, 0x2772, 0x2772, 0x492B, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x491A,
0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0,
0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8551, 0x2772, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x2772, 0x492B, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x492B, 0x492B, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x491A, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x492B, 0x8944, 0x491A,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x492B, 0x492B, 0x492B, 0x492B, 0x8944, 0x491A,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44B2, 0x492B, 0x8944, 0x8944, 0x8944, 0x492B, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xA7D3, 0xA7D3, 0x44B2, 0xA7D3, 0x44B2, 0x4481, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44B2, 0x0, 0x4481, 0x0, 0x4481, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t goblin_attack_data1[] PROGMEM = {
			24, 20, 0, 1, 16, 19, 1,
0x1795, 0x2772, 0x1795, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x2993, 0x2772, 0x2772, 0x2772, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x1795, 0x2993, 0x2772, 0x1795, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x8551, 0x2772, 0x2993, 0x2772, 0x8551, 0x0, 0x492B, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x491A,
0x0, 0x1795, 0x2772, 0x2772, 0x8551, 0x0, 0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0,
0x0, 0x0, 0x8551, 0x8551, 0x2772, 0x8551, 0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x8551, 0x8551, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x2772, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x492B, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x491A, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x491A, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x492B, 0x492B, 0x492B, 0x8944, 0x491A, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44B2, 0x492B, 0x8944, 0x8944, 0x8944, 0x491A, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xA7D3, 0xA7D3, 0x44B2, 0xA7D3, 0x44B2, 0x4481, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44B2, 0x0, 0x4481, 0x0, 0x4481, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t goblin_attack_data2[] PROGMEM = {
			24, 20, 4, 0, 20, 20, 1,
0x0, 0x0, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0, 0x0, 0x0, 0x0, 0x0,
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB495, 0xFFFF, 0xFFFF, 0xB495, 0x54A6, 0x54A6, 0xB495, 0xFFFF, 0xFFFF, 0x148D, 0xFFFF, 0xFFFF, 0xFFFF, 0x0, 0x0, 0x0,
0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB495, 0xB495, 0xFFFF, 0x54A6, 0x54A6, 0x54A6, 0x54A6, 0xB495, 0x148D, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0, 0x0,
0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xB495, 0x54A6, 0x54A6, 0x518C, 0x54A6, 0xB495, 0x518C, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0,
0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x8944, 0x8944, 0x8944, 0x8944, 0x54A6, 0xDACE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0,
0x0, 0x0, 0xFFFF, 0xFFFF, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0xFFFF, 0x0, 0x0, 0x0, 0x492B, 0x492B, 0x492B, 0x492B, 0x492B, 0x0, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x0, 0x0, 0xA7D3, 0x44B2, 0x44B2, 0x492B, 0x492B, 0x0, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x2772, 0x0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x0, 0x44B2, 0x0, 0x4481, 0x0, 0x4481, 0x492B, 0x8551, 0x2772, 0x2993, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
0x0, 0x0, 0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x8551, 0x2772, 0x2993, 0x2993, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x7394,
0x0, 0x0, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x8551, 0x2772, 0x2772, 0x2993, 0x2993, 0x1795, 0xFFFF, 0x7394,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x7394,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x1795, 0x2772, 0x1795,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1795, 0x2772, 0x2772, 0x2772, 0x2772,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x1795, 0x8551, 0x1795,
		};

		const uint16_t goblin_attack_data3[] PROGMEM = {
			 24, 20, 6, 3, 18, 17, 1,
0x0, 0x0, 0x492B, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x492B, 0x492B, 0x492B, 0x492B, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x492B, 0x8944, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D3, 0x44B2, 0x44B2, 0x492B, 0x492B, 0x2772, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x2772, 0x2772, 0x2993, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x44B2, 0x0, 0x4481, 0x0, 0x4481, 0x492B, 0x0, 0x8551, 0x2772, 0x2993, 0x2993, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x8551, 0x2772, 0x2772, 0x2993, 0x2993, 0x1795, 0x0, 0x0,
0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x1795, 0x2772, 0x1795,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1795, 0x2772, 0x2772, 0x2772, 0x2772,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x1795, 0x8551, 0x1795,
		};

		const uint16_t goblin_attack_data4[] PROGMEM = {
			24, 20, 7, 5, 17, 15, 1,
0x492B, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x492B, 0x492B, 0x492B, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x492B, 0x492B, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x491A, 0x8944, 0x8944, 0x8944, 0x8944, 0x2772, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x492B, 0x492B, 0x492B, 0x492B, 0x2772, 0x2772, 0x2993, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x8551, 0x2772, 0x2993, 0x2993, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0xA7D3, 0x44B2, 0x44B2, 0x492B, 0x492B, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x2993, 0x2993, 0x1795, 0x0, 0x0,
0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0xE550, 0x0, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x0,
0x0, 0x44B2, 0x0, 0x4481, 0x0, 0x4481, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x2772, 0x2772, 0x1795, 0x2772, 0x1795,
0x0, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x1795, 0x2772, 0x2772, 0x2772, 0x2772,
0x0, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8551, 0x1795, 0x8551, 0x1795,
		};

		const uint16_t goblin_attack_data5[] PROGMEM = {
			24, 20, 6, 4, 12, 16, 1,
0x492B, 0x0, 0x0, 0x492B, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x491A, 0x0, 0x0,
0x492B, 0x492B, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0,
0x0, 0x492B, 0x8944, 0x8944, 0x8210, 0x8944, 0x492B, 0x8210, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x8944, 0x8944, 0x8944, 0x492B, 0x491A, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x492B, 0x492B, 0x491A, 0x0, 0x0, 0x1795, 0x0, 0x0,
0x0, 0x8944, 0x492B, 0x8944, 0x8944, 0x8944, 0x8944, 0x492B, 0x2993, 0x2772, 0x2772, 0x1795,
0x0, 0x8944, 0x8944, 0x492B, 0x8944, 0x2993, 0x2993, 0x1795, 0x2772, 0x1795, 0x2772, 0x0,
0x0, 0x492B, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x2772, 0x8551, 0x0,
0x492B, 0x492B, 0x491A, 0x8551, 0x8551, 0x8551, 0x8551, 0x8551, 0x1795, 0x8551, 0x1795, 0x0,
0x0, 0x492B, 0x4DBC, 0x492B, 0x2772, 0x492B, 0x492B, 0x2772, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x44B2, 0x44B2, 0xA7D3, 0x4481, 0x4481, 0x8551, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x44B2, 0x0, 0x4481, 0x0, 0x4481, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x0, 0x0, 0x0, 0x492B, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x8944, 0x0, 0x0, 0x0, 0x491A, 0x492B, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x492B, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t* attack_sprites[] PROGMEM = {
			goblin_attack_data0, 
			goblin_attack_data1, 
			goblin_attack_data2, 
			goblin_attack_data3,
			goblin_attack_data4, 
			goblin_attack_data5, 
		};

		Animation attack = Animation(attack_sprites, 6, false, 1);

	}

}