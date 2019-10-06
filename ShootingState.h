#pragma once
#include <HeroState.h>

namespace actors
{
	namespace hero
	{
		class ShootingState : public HeroState
		{
		public:
			void update(Hero& hero) override;
			void on_enter(Hero& hero) override;
			void on_exit(Hero& hero) override;
		};
	}
}



