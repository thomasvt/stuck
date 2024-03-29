#include <Gamebuino-Meta.h>
#include <Animation.h>

namespace animations
{
	namespace hero
	{
		const uint16_t fall_sprite_data[] PROGMEM = {
			20, 25, 3, 1, 17, 24, 1,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x0, 0x2F6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x87FF, 0x2F6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60F4, 0xEB, 0xEB, 0xEB, 0x60F4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x60F4, 0xEB, 0xEB, 0xEB, 0xEB, 0xEB, 0xEB, 0x60F4, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x60F4, 0xEB, 0x44B2, 0xEB, 0xEB, 0x4DBC, 0x4DBC, 0xEB, 0x44B2, 0x60F4, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x60F4, 0xEB, 0x60F4, 0x44B2, 0x44B2, 0x4DBC, 0xCD11, 0x35EE, 0xCD11, 0xEB, 0xEB, 0x60F4, 0x0, 0x277A, 0x0,
0x0, 0x60F4, 0xEB, 0x44B2, 0xEB, 0xEB, 0x44B2, 0x35EE, 0x35EE, 0x35EE, 0x35EE, 0x4481, 0xEB, 0x44B2, 0x6D42, 0x0, 0x277A,
0x60F4, 0x44B2, 0xEB, 0x60F4, 0x44B2, 0x44B2, 0x87FF, 0x4481, 0x35EE, 0x35EE, 0x35EE, 0x4481, 0x44B2, 0xEB, 0x6D42, 0x0, 0x277A,
0xEB, 0xEB, 0x44B2, 0xEB, 0xEB, 0x44B2, 0x4481, 0x4481, 0x4DBC, 0x4DBC, 0x4481, 0x44B2, 0xEB, 0xEB, 0x6D42, 0x0, 0x277A,
0x0, 0x44B2, 0x44B2, 0x44B2, 0xEB, 0xDB34, 0xDB34, 0xDB34, 0x35EE, 0x35EE, 0xDB34, 0xDB34, 0xDB34, 0x5523, 0x6D42, 0x0, 0x8944,
0x0, 0xEB, 0x4481, 0xDB34, 0x5523, 0x5523, 0x5523, 0xDB34, 0xDB34, 0x35EE, 0xDB34, 0xDB34, 0x5523, 0x5523, 0x5523, 0x0, 0x492B,
0x0, 0x0, 0xDB34, 0x4481, 0x44B2, 0x4481, 0x44B2, 0x5523, 0xDB34, 0xDB34, 0xDB34, 0x5523, 0x44B2, 0xEB, 0x5523, 0x5523, 0x492B,
0x0, 0x35EE, 0x0, 0x0, 0x0, 0x44B2, 0x44B2, 0x44B2, 0x5523, 0x5523, 0x5523, 0x4481, 0xEB, 0x0, 0x6D42, 0x0, 0x35EE,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xA7D9, 0xA7D9, 0xA7D9, 0x0, 0x0, 0x0, 0x6D42, 0x0, 0x492B,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5523, 0x5523, 0x5E46, 0xDB34, 0x5523, 0x5523, 0x0, 0x0, 0x6D42, 0x0, 0x492B,
0x0, 0x0, 0x0, 0x0, 0x0, 0x5523, 0xDB34, 0xDB34, 0x5E46, 0xDB34, 0x5523, 0xDB34, 0x5523, 0x0, 0x6D42, 0x0, 0x8944,
0x0, 0x0, 0x0, 0x0, 0x5523, 0xDB34, 0xDB34, 0x5E46, 0xDB34, 0xDB34, 0xDB34, 0x5E46, 0xDB34, 0x5523, 0x6D42, 0x277A, 0x0,
0x0, 0x0, 0x0, 0x0, 0x5523, 0xDB34, 0x5E46, 0x2993, 0xDB34, 0x5523, 0xDB34, 0xDB34, 0x5E46, 0x5523, 0x6D42, 0x277A, 0x0,
0x0, 0x0, 0x0, 0x5523, 0xDB34, 0xDB34, 0x5E46, 0xDB34, 0xDB34, 0x5523, 0x5523, 0x2993, 0xDB34, 0x5E46, 0x6D42, 0x277A, 0x0,
0x0, 0x0, 0x0, 0x5523, 0xDB34, 0x5E46, 0x2993, 0xDB34, 0x5523, 0x5523, 0x5523, 0xDB34, 0x2993, 0x5E46, 0x277A, 0x5523, 0x0,
0x0, 0x0, 0x2993, 0xDB34, 0xDB34, 0x2993, 0x2772, 0x2993, 0x5523, 0x2993, 0x5523, 0x2993, 0x2772, 0x277A, 0x5E46, 0x5523, 0x0,
0x0, 0x0, 0x2772, 0x5523, 0x8551, 0xCD11, 0x35EE, 0xCD11, 0xCD11, 0xCD11, 0xCD11, 0x35EE, 0xCD11, 0x8551, 0x5523, 0x0, 0x0,
0x0, 0x0, 0x0, 0xCD11, 0x8551, 0xCD11, 0x35EE, 0x8551, 0x8551, 0x8551, 0x8551, 0x8551, 0x35EE, 0x8551, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x35EE, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		};

		const uint16_t* fall_sprites[] PROGMEM = {
			fall_sprite_data, 
		};

		Animation fall = Animation(fall_sprites, 1);
	}
}