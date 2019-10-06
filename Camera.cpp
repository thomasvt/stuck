#include "Camera.h"
#include <Vector.h>
#include <Renderer.h>
#include <PogoScene.h>
#include <Game.h>
#include "Time.h"

constexpr int camera_follow_margin_x = 75;
constexpr int camera_follow_margin_y = 50;

Camera::Camera(PogoScene& scene) : scene_(scene) {
}

void Camera::update()
{
	// earthquake
	if (shake_ >= 0)
	{
		shake_--;
		if ((gametime::framecount >> 1) & 1)
			Game::scene.camera.location.x++;
		else
			Game::scene.camera.location.x--;
	}


	location = Vector16(location.x + pan.x, location.y + pan.y);

	if (hero_ptr_ == nullptr)
		return;

	// follow player
	const auto player_location_screen = to_screen(hero_ptr_->get_location());
	if (player_location_screen.x < camera_follow_margin_x)
		location.x -= camera_follow_margin_x - player_location_screen.x;
	else if (player_location_screen.x > screen_width - camera_follow_margin_x)
		location.x += player_location_screen.x - screen_width + camera_follow_margin_x;

	if (player_location_screen.y < camera_follow_margin_y)
		location.y -= camera_follow_margin_y - player_location_screen.y;
	else if (player_location_screen.y > screen_height - camera_follow_margin_y)
		location.y += player_location_screen.y - screen_height + camera_follow_margin_y;

	// coerce within bounds of level
	if (location.x < screen_center.x)
		location.x = screen_center.x;
	if (location.y < screen_center.y)
		location.y = screen_center.y;
	if (location.x > scene_.size.x - screen_center.x)
		location.x = scene_.size.x - screen_center.x;
	if (location.y > scene_.size.y - screen_center.y)
		location.y = scene_.size.y - screen_center.y;

	
}

VectorI Camera::to_screen(const VectorI location_world) const
{
	return { location_world.x - location.x + screen_center.x, location_world.y - location.y + screen_center.y };
}

void Camera::set_followed_target(actors::hero::Hero* hero)
{
	hero_ptr_ = hero;
	const auto loc = hero->get_location();
	location = Vector16(loc.x, loc.y);
	update(); // ensure camera abides by the rules
}

void Camera::quake(const int frame_count)
{
	shake_ = frame_count;
}
