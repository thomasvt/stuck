#pragma once
#include <Vector.h>
#include <Rectangle.h>
#include <Gamebuino-Meta.h>

class Camera;
struct Rectangle;

namespace actors {

	class Door 
	{
	public:
		Vector16 location = Vector16();
		uint8_t color_ = 0;
		uint8_t open_distance = 32;

		Door();
		explicit Door(Vector16 location, uint8_t color);

		void update() ;
		Rectangle measure(const Camera& camera) const ;
		void render(const uint8_t& layer, const Rectangle& part, int x, int y, uint16_t* slice_buffer) const ;

		// start opening the door
		void open(bool instant = false);
		// is door fully opened?
		bool is_open() const;
		Rectangle get_bounding_box() const;
	};

	class Door0 {
	public:
		Vector16 location = Vector16();
		uint8_t color_ = 0;
		uint8_t open_distance = 32;
	};


}
