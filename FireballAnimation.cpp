#include "FireballAnimation.h"
#include <Gamebuino-Meta.h>

namespace animations {

	const uint16_t fireball0[] PROGMEM = {
10, 10, 0, 2, 9, 6, 1,
0x0, 0x0, 0x0, 0x0, 0x60F4, 0x60F4, 0x60F4, 0x60F4, 0x0,
0xE6E3, 0x60F4, 0x2F6, 0x2F6, 0x2F6, 0x2F6, 0x2F6, 0x2F6, 0x60F4,
0x0, 0x0, 0x60F4, 0x2F6, 0x87FF, 0x87FF, 0x87FF, 0xFFFF, 0x2F6,
0x0, 0x0, 0x0, 0x60F4, 0x87FF, 0xFFFF, 0xFFFF, 0xFFFF, 0x2F6,
0x0, 0x60F4, 0x60F4, 0x87FF, 0x87FF, 0x87FF, 0x87FF, 0x2F6, 0x60F4,
0x0, 0x0, 0x0, 0x60F4, 0x60F4, 0xE6E3, 0x60F4, 0x60F4, 0x0,
	};


	const uint16_t fireball1[] PROGMEM = {
10, 10, 0, 2, 9, 6, 1,
0x0, 0x0, 0x0, 0x0, 0xE6E3, 0xE6E3, 0xE6E3, 0x0, 0x0,
0x0, 0x0, 0x60F4, 0x60F4, 0x6BF6, 0x6BF6, 0x6BF6, 0x6BF6, 0xE6E3,
0xE6E3, 0x60F4, 0x6BF6, 0x6BF6, 0x87FF, 0x87FF, 0x87FF, 0xFFFF, 0x6BF6,
0x0, 0x0, 0x60F4, 0x87FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6BF6,
0xE6E3, 0x60F4, 0x60F4, 0x87FF, 0x87FF, 0x87FF, 0x87FF, 0x6BF6, 0xE6E3,
0x0, 0x0, 0x0, 0x60F4, 0xE6E3, 0xE6E3, 0xE6E3, 0xE6E3, 0x0,
	};


	const uint16_t fireball2[] PROGMEM = {
10, 10, 0, 2, 9, 6, 1,
0x0, 0x0, 0x0, 0x0, 0x60F4, 0x60F4, 0x60F4, 0x60F4, 0x0,
0x0, 0x0, 0x0, 0x60F4, 0x60F4, 0x60F4, 0x2F6, 0x2F6, 0x60F4,
0x0, 0xE6E3, 0x60F4, 0x60F4, 0x2F6, 0x87FF, 0x87FF, 0x87FF, 0x2F6,
0x0, 0x0, 0x0, 0x2F6, 0x87FF, 0xFFFF, 0xFFFF, 0x87FF, 0x2F6,
0x0, 0x0, 0x60F4, 0x2F6, 0x2F6, 0x87FF, 0x87FF, 0x2F6, 0x60F4,
0xE6E3, 0x60F4, 0x2F6, 0x60F4, 0x60F4, 0x60F4, 0xE6E3, 0xE6E3, 0x0,
	};


	const uint16_t fireball3[] PROGMEM = {
10, 10, 0, 2, 9, 6, 1, 
0x0, 0x0, 0x0, 0x0, 0xE6E3, 0xE6E3, 0xE6E3, 0x0, 0x0, 
0x0, 0xE6E3, 0x60F4, 0x60F4, 0x6BF6, 0x6BF6, 0x6BF6, 0x6BF6, 0x60F4, 
0x0, 0x0, 0x60F4, 0x6BF6, 0x87FF, 0x87FF, 0x87FF, 0xFFFF, 0x6BF6, 
0xE6E3, 0x60F4, 0x60F4, 0x87FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x6BF6, 
0x0, 0x0, 0xE6E3, 0x87FF, 0x87FF, 0x87FF, 0x87FF, 0x6BF6, 0x60F4, 
0x0, 0xE6E3, 0xE6E3, 0x60F4, 0x60F4, 0xE6E3, 0xE6E3, 0xE6E3, 0x0, 
};


	const uint16_t* fireball_right_sprites[] PROGMEM = {
			fireball0,
			fireball1,
			fireball2,
			fireball3
	};

	// fireball up

	const uint16_t fireballup0[] PROGMEM = {
10, 10, 1, 0, 8, 10, 1,
0x0, 0xE96D, 0xE96D, 0xBA7, 0xBA7, 0xE96D, 0xE96D, 0x0,
0xE96D, 0xBA7, 0xBA7, 0xFFFF, 0xFFFF, 0xBA7, 0xBA7, 0xE96D,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0xE96D,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xCED7, 0xCED7, 0xCED7, 0xE96D,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xCED7, 0xCED7, 0xCED7, 0xE96D,
0x0, 0xBA7, 0xBA7, 0xBA7, 0xE96D, 0xCED7, 0xCED7, 0xE96D,
0x0, 0xBA7, 0xBA7, 0xE96D, 0x0, 0xE96D, 0xE96D, 0x0,
0x0, 0xE96D, 0xE96D, 0x0, 0x0, 0x8944, 0x8944, 0x0,
0x0, 0x8944, 0x8944, 0x0, 0x0, 0x0, 0x0, 0x0,
	};


	const uint16_t fireballup1[] PROGMEM = {
10, 10, 1, 0, 8, 10, 1,
0x0, 0x8944, 0x8944, 0xBA7, 0xBA7, 0x8944, 0x8944, 0x0,
0x0, 0xBA7, 0xBA7, 0xFFFF, 0xFFFF, 0xBA7, 0xBA7, 0x8944,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0x0, 0xE96D, 0xE96D, 0xBA7, 0xCED7, 0xCED7, 0xCED7, 0xE96D,
0x0, 0xE96D, 0xE96D, 0xBA7, 0xE96D, 0xE96D, 0xE96D, 0x0,
0x0, 0x0, 0xE96D, 0xE96D, 0x0, 0xE96D, 0xE96D, 0x0,
0x0, 0x0, 0x8944, 0x8944, 0x0, 0x8944, 0x8944, 0x0,
	};


	const uint16_t fireballup2[] PROGMEM = {
10, 10, 1, 0, 8, 10, 1,
0x0, 0xE96D, 0xE96D, 0xBA7, 0xBA7, 0xE96D, 0xE96D, 0x0,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xCED7, 0xBA7, 0xBA7, 0x8944,
0xE96D, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0xE96D, 0xE96D, 0xE96D, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0xE96D,
0xE96D, 0xE96D, 0xE96D, 0xBA7, 0xCED7, 0xBA7, 0xBA7, 0xE96D,
0xE96D, 0xE96D, 0xE96D, 0xBA7, 0xCED7, 0xBA7, 0xBA7, 0xE96D,
0x0, 0xE96D, 0xE96D, 0xE96D, 0xBA7, 0xBA7, 0xBA7, 0xE96D,
0x0, 0x0, 0xE96D, 0xE96D, 0x0, 0xE96D, 0xE96D, 0xBA7,
0x0, 0x0, 0x8944, 0x8944, 0x0, 0x0, 0xE96D, 0xE96D,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944,
	};


	const uint16_t fireballup3[] PROGMEM = {
10, 10, 1, 0, 8, 10, 1,
0x0, 0x8944, 0x8944, 0xBA7, 0xBA7, 0x8944, 0x8944, 0x0,
0x0, 0xBA7, 0xBA7, 0xFFFF, 0xFFFF, 0xBA7, 0xBA7, 0x8944,
0x8944, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0x8944, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0x8944,
0x8944, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0xE96D,
0x8944, 0xBA7, 0xBA7, 0xCED7, 0xFFFF, 0xCED7, 0xCED7, 0xE96D,
0x0, 0xE96D, 0xE96D, 0xBA7, 0xCED7, 0xCED7, 0xCED7, 0xE96D,
0x0, 0xE96D, 0xE96D, 0x0, 0xE96D, 0xE96D, 0x8944, 0x8944,
0x0, 0x8944, 0x8944, 0x0, 0xE96D, 0xE96D, 0x0, 0x8944,
0x0, 0x0, 0x0, 0x0, 0x8944, 0x8944, 0x0, 0x0,
	};



	const uint16_t* fireball_up_sprites[] PROGMEM = {
			fireballup0,
			fireballup1,
			fireballup2,
			fireballup3
	};

	Animation fireball_right = Animation(fireball_right_sprites, 4, true, 2);
	Animation fireball_up = Animation(fireball_up_sprites, 4, true, 2);

}