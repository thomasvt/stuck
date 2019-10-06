#pragma once

namespace actors
{
	namespace hero
	{
		class Hero;

		class HeroState
		{
			friend class Hero;
		public:
			virtual void update(Hero& hero) = 0;
			// triggered when entering this state coming from another state.
			virtual void on_enter(Hero& hero) = 0;
			// triggered when leaving this state.
			virtual void on_exit(Hero& hero) = 0;
		};
	}
}