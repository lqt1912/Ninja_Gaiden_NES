#pragma once
#include "Enemy.h"
class BulletBoss :
	public Enemy
{
public:
	BulletBoss();
	~BulletBoss();
	BoundingBox GetBoundingBox();
	void Update(float dt);
};

