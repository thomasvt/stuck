#include "Game.h"
#include <LevelLoader.h>
#include "PogoScene.h"
#include <InputProcessor.h>
#include "GameState.h"
#include "Time.h"

PogoScene Game::scene = PogoScene();
MenuScene Game::menu_scene = MenuScene();
GameState Game::state = GameState();
uint8_t Game::save_slot_ = 0;
screen Game::global_screen = screen::logo;
InputProcessor Game::input_processor = InputProcessor();

void Game::initialize()
{
	input_processor.set_controlled_camera(&Game::scene.camera);
	scene.camera.set_followed_target(&scene.hero);
	gametime::framecount = 0;
}

void Game::continue_or_new_game(const int save_slot)
{
	save_slot_ = save_slot;
	state.load(save_slot);
	LevelLoader::trigger_level_switch(state.spawn_point);
}

void Game::reload_last_save()
{
	state.load(save_slot_);
	LevelLoader::trigger_level_switch(state.spawn_point);
}

void do_menu()
{
	Game::menu_scene.update();
	Renderer::render(Game::menu_scene, true);
}

void do_game()
{
	LevelLoader::load_next_level_if_needed(Game::input_processor);
	Game::input_processor.update();
	Game::scene.update();
	Renderer::render(Game::scene, false);
}

void Game::do_loop()
{
	if (global_screen != screen::game)
	{
		do_menu();
	}
	else
	{
		do_game();
	}
}

void Game::progress_to_spawn_point(const uint8_t next_spawn_point)
{
	state.store_current_area_state();
	LevelLoader::trigger_level_switch(next_spawn_point);
	state.save(save_slot_);
}
