#pragma once
#include "Enemy.h"
class EnemyBrownKnife :
	public Enemy
{
public:
	EnemyBrownKnife();
	~EnemyBrownKnife();
	void Update(float);
	int getType()
	{
		return BROWN_KNIFE_TYPE;
	}
};

