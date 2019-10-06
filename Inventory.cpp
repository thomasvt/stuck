#include "Inventory.h"

void Inventory::collect_pickup(const uint8_t type)
{
	data_ |= 1 << type;
}

void Inventory::remove_pickup(const uint8_t type)
{
	data_ &= ~(1 << type);
}