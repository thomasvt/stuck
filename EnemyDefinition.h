#pragma once

struct Animation;

namespace actors {
	class Enemy;

	class EnemyDefinition
	{
	public:
		virtual void initialize(Enemy& enemy) const = 0;
		virtual void update(Enemy& enemy) const = 0;
		virtual void die(Enemy& enemy, const bool silent = false) const = 0;
	};

}
