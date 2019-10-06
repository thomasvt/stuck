#include <Sounds.h>

namespace sounds {

	// shared sounds are here, most sounds are used only in 1 place and can be found there.

	const Gamebuino_Meta::Sound_FX click[] = {
		{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,113,1},
		{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,159,1},
		{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,89,2},
		{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,0,0,80,1},
	};

	const Gamebuino_Meta::Sound_FX click_quake[] = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,113,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,159,1},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,0,0,0,89,2},
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,255,0,0,80,1},
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,15,1,0,256,20},
	};

	const Gamebuino_Meta::Sound_FX quake[] = {
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,15,1,0,256,30},
	};

}
