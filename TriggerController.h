#pragma once

// Controls pressure plates and performs the changes in the level they cause.
class TriggerController
{
	static void apply_trigger_changes(const int trigger_id);
public:
	static void update();
};

