#include <Gamebuino-Meta.h>
#include "Renderer.h"
#include <Debug.h>
#include "Game.h"

constexpr int fps = 30;

void setup() {
	gb.begin();
	gb.setFrameRate(fps);
	SerialUSB.begin(9600);
	Renderer::delete_framework_backbuffer();
	Game::initialize();

	//Debug::start_wait_for_debug_button();
}

void log_hardware_stats()
{
	if (gb.frameCount % fps > 0)
		return;

	SerialUSB.printf("CPU: %i, RAM: %i\n", gb.getCpuLoad(), gb.getFreeRam());
}

void loop() {
	while (!gb.update());
	log_hardware_stats();

	if (!Debug::update())
		return;
	Game::do_loop();
}
