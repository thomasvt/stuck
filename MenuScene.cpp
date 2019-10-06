#include "MenuScene.h"
#include <Gamebuino-Meta.h>
#include <Rectangle.h>
#include "MenuSprites.h"
#include <GlobalScreen.h>
#include <Game.h>
#include <Renderer.h>
#include "Texts.h"
#include "GemSprites.h"
#include "Sounds.h"

const Gamebuino_Meta::Sound_FX move_cursor[] = {
	{Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,255,-38,-93,50,3},
};

const Gamebuino_Meta::Sound_FX reset_saveslot[] = {
	{Gamebuino_Meta::Sound_FX_Wave::NOISE,0,255,-1,80,80,25},
};

int MenuScene::get_save_slot() const
{
	return (billboard_[6].location.x - 35) / 30;
}

void MenuScene::update_game_menu()
{
	if (gb.buttons.pressed(Button::menu))
	{
		gb.sound.fx(sounds::click);
		Game::global_screen = screen::game;
	}
	else if (gb.buttons.held(Button::b, 60))
	{
		gb.sound.fx(sounds::click);
		configure_saveslot_screen();
	}
}

bool allow_reset_saveslot = false;

void MenuScene::update_picksaveslot()
{
	if (gb.buttons.released(Button::b))
		allow_reset_saveslot = true; // must release B before we can hold it to reset a saveslot.

	auto& crown_billboard = billboard_[6];
	auto time = gb.buttons.timeHeld(Button::b);
	if (!allow_reset_saveslot)
		time = 0;
	if (time > 0 && time < 80)
	{
		crown_billboard.location.y = 45 - (time >> 2);
	}
	else if (time == 80)
	{
		GameState::reset(get_save_slot());
		gb.sound.fx(reset_saveslot);
	}
	else
	{
		crown_billboard.location.y = 45 - offset_y_wave[(gb.frameCount >> 2) & 0b111]; // have the crown float
	}

	if (gb.buttons.pressed(Button::a))
	{
		Game::continue_or_new_game(get_save_slot());
		Game::global_screen = screen::game;
	}
	else if (gb.buttons.pressed(Button::left))
	{
		if (crown_billboard.location.x > 35)
		{
			crown_billboard.location.x -= 30;
			gb.sound.fx(move_cursor);
		}
	}
	else if (gb.buttons.pressed(Button::right))
	{
		if (crown_billboard.location.x < 125)
		{
			crown_billboard.location.x += 30;
			gb.sound.fx(move_cursor);
		}
	}
}

void MenuScene::update()
{
	switch (Game::global_screen)
	{
	case screen::logo:
		if (gb.frameCount - logo_delay_start_ > 120)
		{
			configure_saveslot_screen();
		}
		break;
	case screen::picksaveslot:
		update_picksaveslot();
		break;
	case screen::game_menu:
		update_game_menu();
		break;
	}
}

void MenuScene::render_slice(uint16_t* const buffer, const Rectangle& slice_bounds) const
{
	for (auto i = 0; i < count_; i++)
		render_actor(0, billboard_[i], buffer, slice_bounds);
}


void MenuScene::add_billboard(const uint16_t* sprite_ptr, const uint8_t x, const uint8_t y)
{
	billboard_[count_].sprite_ptr = sprite_ptr;
	billboard_[count_].location = Vector8(x, y);
	count_++;
}

void MenuScene::reset_billboards()
{
	count_ = 0;
}

void MenuScene::configure_logo_screen()
{
	logo_delay_start_ = gb.frameCount;
	Game::global_screen = screen::logo;
	reset_billboards();
	add_billboard(logo_sprite, (screen_width) >> 1, (screen_height) >> 1);
}


void MenuScene::configure_saveslot_screen()
{
	Game::global_screen = screen::picksaveslot;
	reset_billboards();
	add_billboard(text::pick_save_slot, (screen_width - text::pick_save_slot[0]) >> 1, 10);
	add_billboard(text::pick_save_slot_button_msg, (screen_width - text::pick_save_slot[0]) >> 1, screen_height - text::pick_save_slot_button_msg[1] - 7);
	add_billboard(sprites::gems_large[0], 35, 60);
	add_billboard(sprites::gems_large[1], 65, 60);
	add_billboard(sprites::gems_large[2], 95, 60);
	add_billboard(sprites::gems_large[3], 125, 60);
	add_billboard(crown_sprite, 35, 45);
}

void MenuScene::configure_in_game_menu()
{
	Game::global_screen = screen::game_menu;
	reset_billboards();

	add_billboard(menu_skills, 10, 8);
	add_billboard(Game::state.air_jump_count > 0 ? skill1 : skill_unknown, 20, 25);
	add_billboard(Game::state.air_jump_count > 1 ? skill2 : skill_unknown, 20, 50);
	add_billboard(Game::state.arrow_climb_enabled ? skill3 : skill_unknown, 20, 75);
	add_billboard(menu_quit, 72, 114);
}

MenuScene::MenuScene()
{
	configure_logo_screen();
}
