#pragma once
#include "Enemy.h"
class EnemyGreenBazooka :
	public Enemy
{
public:
	EnemyGreenBazooka();
	~EnemyGreenBazooka();
	void Update(float);
	int getType()
	{
		return GREEN_BAZOOKA_TYPE;
	}

	Animation* attackAni;
	float s = 0;
	bool isAttacking;
};

