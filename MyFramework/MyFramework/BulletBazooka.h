#pragma once
#include "Enemy.h"
class BulletBazooka :
	public Enemy
{
public:
	BulletBazooka();
	~BulletBazooka();
	void Update(float dt);
};

