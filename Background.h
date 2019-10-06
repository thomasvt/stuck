#pragma once
#include "rectangle.h"

class Camera;
class Sprite;
struct Level;

class Background
{
public:
	Rectangle measure(const Camera& camera) const ;
	void render(const uint8_t& layer, const Rectangle& part, int anchor_x, int anchor_y, uint16_t* slice_buffer) const ;
};

