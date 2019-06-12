#pragma once
#include "Enemy.h"
#include "Game_UI.h"

class BrownBoss :	public Enemy
{
protected:
	Animation* flyAni;

public:
	void Update(float dt);
	BoundingBox GetBoundingBox();
	void MinusBlood();

	bool isAttacking;
	bool isIdling;
	int count;
	float s = 1,s1 = 0;
	BrownBoss();
	~BrownBoss();
	int getType()
	{
		return BROWN_BOSS_TYPE;
	}
	float acceleratorY;
	int blood;
};

