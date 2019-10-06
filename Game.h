#pragma once
#include "PogoScene.h"
#include <Gamebuino-Meta.h>
#include "GameState.h"
#include "MenuScene.h"
#include "GlobalScreen.h"
#include "LevelLoader.h"

namespace actors
{
	namespace hero
	{
		class Hero;
	}
}

class Game
{
	static uint8_t save_slot_;
public:
	static GameState state;

	static void initialize();

	static void continue_or_new_game(int save_slot);
	static void reload_last_save();
	static void do_loop();

	// container for everything in-game: the current level and its content
	static PogoScene scene;
	static MenuScene menu_scene;
	static screen global_screen;
	static InputProcessor input_processor;
	// teleports a player to another spawnpoint and saves the game for reloading.
	static void progress_to_spawn_point(uint8_t next_spawn_point);
};

