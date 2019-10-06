#pragma once
#include <Gamebuino-Meta.h>
#include "Scene.h"
#include <billboard.h>

namespace actors {
	class Actor;
}
struct Rectangle;

class MenuScene : public Scene
{
	uint32_t logo_delay_start_ = 0;
	actors::Billboard billboard_[7];
	uint8_t count_ = 0;

	void render_slice(uint16_t* const buffer, const Rectangle& slice_bounds) const override;
	void configure_logo_screen();
	void add_billboard(const uint16_t* sprite_ptr, const uint8_t x, const uint8_t y);
	void reset_billboards();
	void configure_saveslot_screen();
	int get_save_slot() const;
	void update_game_menu();
	void update_picksaveslot();
public:
	MenuScene();

	void update();
	void configure_in_game_menu();
};

