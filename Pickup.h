#pragma once
#include <Gamebuino-Meta.h>
#include <Vector.h>

const uint8_t offset_y_wave[]{ 0, 1, 2, 2, 2, 1, 0, 0 };

class Camera;
struct Rectangle;

namespace actors {

class Pickup final
{
	inline VectorI get_location() const;
public:
	Vector8 location_grid_;
	uint8_t type_;
	explicit Pickup() { location_grid_ = Vector8(); type_ = 255; }
	explicit Pickup(const Vector8& location, const uint8_t type) : location_grid_ (location), type_(type) {}

	void update() ;
	Rectangle measure(const Camera& camera) const ;
	void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const ;
	bool is_looted() const
	{
		return type_ == 255;
	}
};

}
