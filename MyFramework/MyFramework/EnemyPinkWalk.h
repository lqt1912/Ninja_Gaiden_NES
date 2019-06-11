#pragma once
#include "Enemy.h"
#include "Ninja.h"
#include "SwordOfPink.h"


class EnemyPinkWalk :
	public Enemy
{
public:
	EnemyPinkWalk();
	~EnemyPinkWalk();
	void Update(float);
	int getType()
	{
		return PINK_WALK_TYPE;
	}
	Animation* attackAni;
	float s = 0;
	bool isAttacking;

};

