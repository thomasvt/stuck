#pragma once
#include <Camera.h>
#include "Hero.h"

class InputProcessor
{
	actors::hero::Hero* hero_ptr_ = nullptr;
	Camera* camera_ptr_ = nullptr;

	void control_hero() const;
	void control_camera() const;
public:
	// assigns the hero that is controlled by user input
	void set_controlled_hero(actors::hero::Hero* hero_ptr);
	// assigns the camera that is controller by user input
	void set_controlled_camera(Camera* camera_ptr);
	void update() const;
};

