#include "Debug.h"
#include <Gamebuino-Meta.h>

bool Debug::fatal_error_occurred_ = false;
bool Debug::is_debug_frame = false;
const char* Debug::error_message_ = nullptr;
bool Debug::wait_for_debug_button_ = false;

const char halted_msg[] PROGMEM = ("Halted due to FATAL: %s\n");
const char wait_4_debug_msg[] PROGMEM = "Waiting for debug button.";
const char fatal_msg[] PROGMEM = "FATAL: %s";

bool Debug::update()
{
	if (wait_for_debug_button_)
	{
		if (gb.buttons.pressed(Button::menu))
		{
			wait_for_debug_button_ = false;
			return true;
		}
		if (gb.frameCount % 30 == 0)
			SerialUSB.println(wait_4_debug_msg);
		return false;
	}
	is_debug_frame = false; // reset debug frame flag in case previous frame was a debug frame
	if (gb.buttons.held(Button::menu, 60))
		is_debug_frame = true;

	if (fatal_error_occurred_ && gb.frameCount % 30 == 0)
		SerialUSB.printf(halted_msg, error_message_);
	return !fatal_error_occurred_;
}

void Debug::throw_fatal(const char* error_message)
{
	fatal_error_occurred_ = true;
	error_message_ = error_message;
	for (auto i = 0; i < 4; i++)
	{
		gb.sound.tone(1000, 60);
		delay(100);
	}
	SerialUSB.printf(fatal_msg, error_message);
}

bool Debug::start_wait_for_debug_button()
{
	wait_for_debug_button_ = true;
}
