#pragma once
#include <HeroState.h>

namespace actors
{
	namespace hero
	{
		class OnLadderState : public HeroState
		{
			void update(actors::hero::Hero& hero) override;
			void on_enter(actors::hero::Hero& hero) override;
			void on_exit(Hero& hero) override;
		};
	}
}
