#pragma once
#include <Vector.h>
#include <Gamebuino-Meta.h>

struct PortalInfo
{
	const Vector8 location;
	const uint8_t target_level_id;
	const uint8_t target_spawn_id;

	PortalInfo(const uint8_t location_x, const uint8_t location_y, const uint8_t target_level_id, const uint8_t target_spawn_id) : location(Vector8(location_x, location_y)), target_level_id(target_level_id), target_spawn_id(target_spawn_id) { }
};
