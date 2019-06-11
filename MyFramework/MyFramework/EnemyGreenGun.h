#pragma once
#include "Enemy.h"
#include "Ninja.h"
class EnemyGreenGun :
	public Enemy
{
public:
	EnemyGreenGun();
	~EnemyGreenGun();
	void Update(float);
	
	int getType()
	{
		return GREEN_GUN_TYPE;
	}
	BoundingBox GetBoundingBox();
	Animation* attackAni;
	float s = 0;
	bool isAttacking;
};

