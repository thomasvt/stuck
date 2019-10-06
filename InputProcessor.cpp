#include "InputProcessor.h"
#include <Gamebuino-Meta.h>
#include <Game.h>
#include "Sounds.h"

using namespace actors::hero;

void InputProcessor::set_controlled_hero(actors::hero::Hero* hero_ptr)
{
	this->hero_ptr_ = hero_ptr;
}

void InputProcessor::set_controlled_camera(Camera* camera_ptr)
{
	this->camera_ptr_ = camera_ptr;
}

bool is_down(Button button)
{
	return gb.buttons.states[static_cast<uint8_t>(button)] > 0 && gb.buttons.states[static_cast<uint8_t>(button)] < 0xFFFF;
}

void InputProcessor::update() const
{
	control_hero();
	control_camera();
	if (gb.buttons.pressed(Button::menu))
	{
		gb.sound.fx(sounds::click);
		Game::menu_scene.configure_in_game_menu();
	}
}

void InputProcessor::control_hero() const
{
	auto throttle = Hero::direction::none;
	auto aim = Hero::direction::none;
	if (is_down(Button::left))
		throttle = Hero::direction::left;
	else if (is_down(Button::right))
		throttle = Hero::direction::right;
	else if (is_down(Button::up))
	{
		throttle = Hero::direction::up;
		aim = Hero::direction::up;
	}
	else if (is_down(Button::down))
	{
		throttle = Hero::direction::down;
		aim = Hero::direction::down;
	}
	hero_ptr_->set_throttle(throttle);
	hero_ptr_->set_aim_throttle(aim);

	if (gb.buttons.pressed(Button::a))
		hero_ptr_->jump();
	if (gb.buttons.pressed(Button::b))
	{
		hero_ptr_->draw_arrow();
	}
	else if (gb.buttons.released(Button::b))
	{
		hero_ptr_->release_arrow();
	}
}

void InputProcessor::control_camera() const
{
	if (hero_ptr_->get_state() != HeroFsm::hero_state::on_floor)
		return;

	// todo change to direction system too
	if (gb.buttons.pressed(Button::up))
		camera_ptr_->pan = Vector16(0, -3);
	else if (gb.buttons.pressed(Button::down))
		camera_ptr_->pan = Vector16(0, 3);
	else if (gb.buttons.released(Button::up) || gb.buttons.released(Button::down))
		camera_ptr_->pan = Vector16(0, 0);
}