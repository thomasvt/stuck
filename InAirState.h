#pragma once

#include <HeroState.h>

namespace actors
{
	namespace  hero
	{

		class InAirState : public HeroState
		{
			void update(Hero& hero) override;
			void on_enter(Hero& hero) override;
			void on_exit(Hero& hero) override;
		};

	}
}