#pragma once
#include "Enemy.h"
class EnemyGreenWalk :
	public Enemy
{
public:
	EnemyGreenWalk();
	~EnemyGreenWalk();
	BoundingBox boundGround;
	bool detectGroundA(vector<BoundingBox> grounds);
	void OnCollisionWithGroundA(vector<BoundingBox> grounds);
	BoundingBox curGround;
	int getType()
	{
		return GREEN_WALK_TYPE;
	}
	void Update(float);
};

