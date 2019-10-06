#pragma once

class Debug
{
	static bool fatal_error_occurred_;
	static const char* error_message_;
	static bool wait_for_debug_button_;
public:
	// debug frame is activated by holding Home button for 60 frames (2s), its true for only 1 frame. So, use it for logging things for only one frame.
	static bool is_debug_frame;
	static bool update();
	// orders to stop running the game without crashing the device. the error will be reported repeatedly over serial so you can find out.
	static void throw_fatal(const char* error_message);
	// call this in your setup() to enable a mode where Debug::update() returns false until the Gamebuino's Menu button is pressed. Used to attach a serial monitor before the game starts.
	static bool start_wait_for_debug_button();
};
