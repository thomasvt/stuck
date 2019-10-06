#pragma once
#include <Vector.h>

struct Rectangle
{
	Rectangle()
	{
		this->left = 0;
		this->top = 0;
		this->right = -1;
		this->bottom = -1;
	}

	Rectangle(const int left, const int top, const int right, const int bottom)
	{
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}

	int left, top, right, bottom;

	// returns the intersection rectangle
	Rectangle intersect(const Rectangle& other) const
	{
		if (right < other.left || left > other.right || bottom < other.top || top > other.bottom)
			return {}; // no overlap
		return {
			left > other.left ? left : other.left,
			top > other.top ? top : other.top,
			right < other.right ? right : other.right,
			bottom < other.bottom ? bottom : other.bottom
		};
	}

	bool is_empty() const
	{
		return right < left || top > bottom;
	}

	void log() const;

	bool contains(const VectorI& location) const
	{
		return location.x >= left && location.x <= right && location.y >= top && location.y <= bottom;
	}

	Rectangle subtract(const int& x, const int& y) const
	{
		return { left - x, top - y, right - x, bottom - y };
	}
};

