#pragma once
#include <Gamebuino-Meta.h>
#include "Vector.h"
#include "PortalInfo.h"
#include <Debug.h>
#include <rectangle.h>

class Sprite;
struct Rectangle;

const char spawnpoint_id_out_of_bounds[] PROGMEM = "spawnlocation out of bounds";
const char portal_id_out_of_bounds[] PROGMEM = "spawnlocation out of bounds";

const int spawnpoints_offset = 2;
const uint8_t spawnpoint_struct_size = 2;
const uint8_t portal_struct_size = 4;
const uint8_t triggerarea_struct_size = 5;

struct Level
{
	const uint16_t* name_sprite;
	const uint8_t* data;
	const uint8_t* terrain_data;

	explicit Level(const uint16_t* name_sprite, const uint8_t* data) : name_sprite(name_sprite), data(data)
	{
		terrain_data = data + get_terrain_offset();
	}

	uint8_t get_spawnpoint_count() const
	{
		return data[spawnpoints_offset];
	}

	uint8_t get_portals_offset() const
	{
		return spawnpoints_offset + 1 + (get_spawnpoint_count() * spawnpoint_struct_size);
	}

	uint8_t get_portal_count() const
	{
		return data[get_portals_offset()];
	}

	int get_trigger_areas_offset() const
	{
		return get_portals_offset() + 1 + get_portal_count() * portal_struct_size;
	}

	// trigger_areas are rectangular areas with an associated trigger_id. The level content inside the area can contain special cell-values that cause blocks to appear or disappear depending on a trigger.
	uint8_t get_trigger_area_count() const
	{
		return data[get_trigger_areas_offset()];
	}

	VectorI get_spawnpoint(const uint8_t spawn_id) const
	{
		if (spawn_id >= get_spawnpoint_count())
			Debug::throw_fatal(spawnpoint_id_out_of_bounds);
		const auto offset = spawnpoints_offset + 1 + (spawn_id << 1);
		return  { data[offset], data[offset + 1] };
	}

	PortalInfo get_portal_info(const uint8_t portal_id) const
	{
		if (portal_id >= get_portal_count())
			Debug::throw_fatal(portal_id_out_of_bounds);
		const auto offset = get_portals_offset() + 1 + portal_id * portal_struct_size;
		return  { data[offset], data[offset + 1], data[offset + 2], data[offset + 3] };
	}

	int get_trigger_area_trigger_id(const int index) const
	{
		return data[get_trigger_areas_offset() + 1 + index * triggerarea_struct_size];
	}

	Rectangle get_trigger_area_rectangle(const int index) const
	{
		const auto offset = get_trigger_areas_offset() + 1 + index * triggerarea_struct_size + 1;
		return { data[offset], data[offset + 1], data[offset + 2], data[offset + 3] };
	}

	uint8_t get_terrain_offset() const
	{
		return get_trigger_areas_offset() + 1 + get_trigger_area_count() * triggerarea_struct_size;
	}

	Vector8 get_size() const
	{
		return { data[0], data[1] };
	}

	int get_pressure_plate_trigger_id(const VectorI& location_grid) const
	{
		return terrain_data[location_grid.y * data[0] + location_grid.x] - 64;
	}
};

