#pragma once
#include <Vector.h>

namespace actors {
	namespace hero {
		class Hero;
	}
}
class PogoScene;

class Camera
{
	int shake_ = -1;
	actors::hero::Hero* hero_ptr_ = nullptr;
	PogoScene& scene_;
public:
	Vector16 location = {};
	Vector16 pan = {};

	// bounds are size of level. The camera stays within 0,0 and bounds.
	explicit Camera(PogoScene& scene);

	void update();
	// converts a world location to on screen coordinates.
	VectorI to_screen(VectorI location_world) const;
	// makes the camera follow the target
	void set_followed_target(actors::hero::Hero* hero);
	// makes the camera shake for a set duration
	void quake(int frame_count);
};
