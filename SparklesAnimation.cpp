#include <SparklesAnimation.h>
#include <Gamebuino-Meta.h>

namespace animations {

	const uint16_t sparkles0[] PROGMEM = {
24, 24, 6, 12, 12, 6, 1,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles1[] PROGMEM = {
24, 24, 5, 9, 14, 9, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x87FF,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles2[] PROGMEM = {
24, 24, 4, 6, 16, 11, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x87FF, 0x0, 0x87FF,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles3[] PROGMEM = {
24, 24, 4, 4, 17, 11, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles4[] PROGMEM = {
24, 24, 3, 2, 18, 11, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles5[] PROGMEM = {
24, 24, 3, 3, 17, 8, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x87FF, 0x0, 0x87FF,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles6[] PROGMEM = {
24, 24, 3, 4, 17, 5, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x87FF, 0x0,
0x87FF, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x87FF, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	};

	const uint16_t sparkles7[] PROGMEM = {
24, 24, 12, 3, 3, 3, 1,
0x0, 0x87FF, 0x0,
0x87FF, 0x0, 0x87FF,
0x0, 0x87FF, 0x0,
	};


	const uint16_t* sparkles_sprites[] PROGMEM = {
		sparkles0,
		sparkles1,
		sparkles2,
		sparkles3,
		sparkles4,
		sparkles5,
		sparkles6,
		sparkles7,
	};

	Animation sparkles = Animation(sparkles_sprites, 8, false, 1);

}