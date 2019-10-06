#pragma once
#include <HeroState.h>
#include <Gamebuino-Meta.h>

namespace actors
{
	namespace hero
	{
		class SpawnState : public HeroState
		{
			uint32_t start_frame_ = 0;
		public:
			void on_enter(Hero& hero) override;
			void on_exit(Hero& hero) override;
			void update(Hero& hero) override;
		};
	}
}
