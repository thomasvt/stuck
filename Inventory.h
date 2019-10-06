#pragma once
#include <Gamebuino-Meta.h>
#include "Cheat.h"

class Inventory
{
	uint8_t data_ = 0;
	public:
		Inventory() { data_ = 0; }

		void collect_pickup(uint8_t type);
		bool has_pickup(const uint8_t type) const
		{
			return cheat || (data_ & (1 << type));
		}
		void remove_pickup(uint8_t type);
};

