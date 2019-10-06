#pragma once

// some lowlevel display-ST7735 control and some hooking into the GamebuinoMeta internals to enable our Renderer 

namespace Gamebuino_Meta {
	constexpr auto dma_desc_count = 3;
	extern volatile uint32_t dma_desc_free_count;
	// extern Adafruit_ZeroDMA tftDMA; // todo find how to get to this so we can do parallel SPI streaming

	static void wait_for_desc_available(const uint32_t min_desc_num) {
		while (dma_desc_free_count < min_desc_num);
	}

	static SPISettings tft_spi_settings = SPISettings(24000000, MSBFIRST, SPI_MODE0);
};