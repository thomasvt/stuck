#pragma once
#include <Gamebuino-Meta.h>

// calculation vector with x and y 32bit (for storage optimized version, use Vector8 or Vector16)
// calculations are fastest on 32 bit int. (probably because other types get casted/converted all the time)
struct VectorI
{
	VectorI()
	{
		this->x = 0;
		this->y = 0;
	}

	VectorI(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}

	int x, y;

	VectorI operator-(const VectorI& b) const
	{
		return { x - b.x, y - b.y };
	}

	VectorI operator+(const VectorI& b) const
	{
		return { x + b.x, y + b.y };
	}

	VectorI to_8() const
	{
		return { x << 3, y << 3 };
	}

	VectorI to_1() const
	{
		return { x >> 3, y >> 3 };
	}

	// returns a vector with positive distance values for x and y. (deltaX, deltaY)
	VectorI get_distance(const VectorI& location) const
	{
		return { x < location.x ? location.x - x : x - location.x, (y < location.y ? location.y - y : y - location.y) };
	}

	// returns x + y of the get_distance() == manhattan distance
	int get_manhattan_distance(const VectorI& location) const
	{
		return (x < location.x ? location.x - x : x - location.x) + (y < location.y ? location.y - y : y - location.y);
	}

	VectorI add(VectorI b) const
	{
		return { x + b.x, y + b.y };
	}
};

// storage vector with x and y 8 bit (for calculations optimized version, use VectorI)
struct Vector8
{
	uint8_t x, y;

	Vector8()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector8(const Vector8& a)
	{
		this->x = a.x;
		this->y = a.y;
	}

	Vector8(const uint8_t x, const uint8_t y)
		: x(x), y(y)
	{
	}
};

// storage vector with x and y 16 bit (for calculations optimized version, use VectorI)
struct Vector16
{
	int16_t x, y;

	Vector16()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector16(const Vector16& a)
	{
		this->x = a.x;
		this->y = a.y;
	}

	Vector16(const int16_t x, const int16_t y)
		: x(x), y(y)
	{
	}

	VectorI to_vector_i() const { return { x, y }; }
};