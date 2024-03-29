#include "ImpAnimations.h"
#include <Gamebuino-Meta.h>

namespace animations {

	namespace imp {

		const uint16_t imp_walk0[] PROGMEM = {
24, 22, 7, 2, 12, 17, 1,
0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0xEB5A, 0x0,
0x0, 0x0, 0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0xEB5A, 0x0, 0xEB5A, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xA7D9, 0xA7D9, 0xA7D3, 0xA7D3, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x579, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0xA7D9, 0x579, 0x0, 0x579, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x0,
0xA7D9, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x66B1, 0xE550, 0x579, 0x579, 0x0,
0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x579, 0x0, 0x0, 0x66B1, 0x66B1,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0xA7D9, 0xA7D9, 0x0, 0x0, 0x579, 0x66B1,
0x0, 0x0, 0x0, 0x0, 0x579, 0x66B1, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x579, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x0, 0xE550, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x0, 0x0, 0x66B1, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x579, 0x0, 0x0, 0x0, 0x0,
		};


		const uint16_t imp_walk1[] PROGMEM = {
24, 22, 7, 6, 12, 15, 1,
0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0xEB5A, 0x0,
0x0, 0x0, 0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0xEB5A, 0x0, 0xEB5A, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xA7D9, 0xA7D9, 0xA7D3, 0xA7D3, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0xA7D9, 0x66B1, 0x0, 0x66B1, 0x579, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0xA7D9, 0x579, 0x579, 0x579, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x0,
0xA7D9, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0x579, 0x579, 0xE550, 0x579, 0x66B1, 0x66B1,
0x66B1, 0xA7D9, 0x0, 0x0, 0xA7D9, 0x66B1, 0xA7D9, 0xA7D9, 0xE550, 0x0, 0x579, 0x66B1,
0x0, 0x0, 0x0, 0x0, 0x579, 0x66B1, 0x66B1, 0x579, 0xE550, 0x579, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x579, 0xE550, 0x579, 0x579, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x0, 0xE550, 0xE550, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x579, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t imp_walk2[] PROGMEM = {
24, 22, 6, 1, 12, 19, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0x0, 0xEB5A, 0x0, 0x0,
0xA7D9, 0xA7D9, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0xEB5A, 0x579, 0x0, 0x0,
0x0, 0x66B1, 0xA7D9, 0xA7D9, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x579, 0x66B1, 0xA7D9, 0xA7D9, 0x4AE5, 0x66B1, 0xA7D3, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x579, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x579, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x66B1, 0xA7D9, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x0,
0x0, 0x66B1, 0xA7D9, 0x0, 0x0, 0x66B1, 0xA7D9, 0x66B1, 0xE550, 0x579, 0x0, 0x0,
0x0, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x579, 0xE550, 0x579, 0x0, 0x0,
0x66B1, 0xA7D9, 0x0, 0x0, 0xA7D9, 0x66B1, 0xA7D9, 0xA7D9, 0x0, 0x579, 0x66B1, 0x0,
0x66B1, 0x66B1, 0x0, 0x0, 0x579, 0x66B1, 0x66B1, 0x579, 0xE550, 0x0, 0x66B1, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x579, 0xE550, 0xE550, 0x0, 0x66B1, 0x66B1,
0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x0, 0x0, 0xE550, 0x579, 0x0, 0x579, 0x66B1,
0x0, 0x0, 0x0, 0xA7D9, 0x0, 0x0, 0x0, 0xE550, 0x66B1, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x579, 0xE550, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0,
		};


		const uint16_t imp_walk3[] PROGMEM = {
24, 22, 6, 2, 12, 17, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0x0, 0xEB5A, 0x0, 0x0,
0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0xEB5A, 0x579, 0x0, 0x0,
0x0, 0x66B1, 0xA7D9, 0xA7D9, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x579, 0x66B1, 0xA7D9, 0xA7D9, 0x4AE5, 0x66B1, 0xA7D3, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x579, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x579, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0xA7D9, 0x579, 0x0, 0x579, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x0,
0xA7D9, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x66B1, 0xE550, 0x579, 0x579, 0x0,
0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x579, 0x0, 0x0, 0x66B1, 0x66B1,
0x0, 0x0, 0x0, 0x0, 0x0, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x579, 0x66B1,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xE550, 0xE550, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x579, 0xA7D9, 0xE550, 0x579, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0xE550, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x66B1, 0x0, 0x579, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0xA7D9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};


		const uint16_t imp_walk4[] PROGMEM = {
24, 22, 6, 6, 12, 15, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0x0, 0xEB5A, 0x0, 0x0,
0xA7D9, 0xA7D9, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0xEB5A, 0x579, 0x0, 0x0,
0x0, 0x66B1, 0xA7D9, 0xA7D9, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x579, 0x66B1, 0xA7D9, 0xA7D9, 0x4AE5, 0x66B1, 0xA7D3, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x579, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0xA7D9, 0x66B1, 0x0, 0x66B1, 0x579, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0xA7D9, 0x579, 0x579, 0x579, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x0,
0xA7D9, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x66B1, 0xE550, 0x579, 0x66B1, 0x66B1,
0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0xE550, 0x0, 0x0, 0x579, 0x66B1,
0x0, 0x0, 0x0, 0x0, 0xA7D9, 0x66B1, 0xA7D9, 0xA7D9, 0xE550, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x579, 0x66B1, 0x66B1, 0xE550, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xE550, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x579, 0x66B1, 0x0, 0x0, 0x579, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};


		const uint16_t imp_walk5[] PROGMEM = {
24, 22, 7, 1, 12, 19, 1,
0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0, 0x1084, 0x0, 0x0, 0xEB5A, 0x0,
0x0, 0x0, 0x66B1, 0xA7D9, 0x0, 0x0, 0x0, 0xEB5A, 0x0, 0xEB5A, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xA7D9, 0xA7D9, 0xA7D3, 0xA7D3, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xA7D9, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x579, 0x66B1, 0x579, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x66B1, 0xA7D9, 0x579, 0xA7D9, 0xA7D9, 0x66B1, 0xE550, 0x0, 0x0, 0x0,
0x0, 0x66B1, 0x66B1, 0x0, 0x0, 0x66B1, 0xA7D9, 0x66B1, 0xE550, 0x579, 0x0, 0x0,
0xA7D9, 0x66B1, 0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0x579, 0x0, 0x579, 0x579, 0x0,
0xA7D9, 0xA7D9, 0x0, 0x0, 0x66B1, 0x66B1, 0xA7D9, 0xE550, 0x0, 0x0, 0x66B1, 0x66B1,
0x66B1, 0xA7D9, 0x0, 0x66B1, 0x66B1, 0x66B1, 0xE550, 0xE550, 0x579, 0x0, 0x579, 0x66B1,
0x0, 0x0, 0x0, 0x66B1, 0xA7D9, 0xE550, 0xE550, 0x579, 0x66B1, 0x579, 0x0, 0x0,
0x0, 0x0, 0x0, 0x579, 0xA7D9, 0x0, 0xE550, 0x66B1, 0x579, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x66B1, 0x0, 0x579, 0xE550, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0xA7D9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x66B1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};



		const uint16_t* walk_sprites[] PROGMEM = {
			imp_walk0,
			imp_walk1,
			imp_walk2,
			imp_walk3,
			imp_walk4,
			imp_walk5
		};

		Animation walk = Animation(walk_sprites, 6, true, 2);

	}

}