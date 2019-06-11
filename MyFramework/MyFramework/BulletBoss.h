#pragma once
#include "Enemy.h"
class BulletBoss :
	public Enemy
{
public:
	BulletBoss();
	~BulletBoss();
	void Update(float dt);
};

