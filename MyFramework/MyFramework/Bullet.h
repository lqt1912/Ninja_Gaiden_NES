#pragma once
#include "Enemy.h"
#include "Ninja.h"
class Bullet :
	public Enemy
{
public:
	Bullet();
	~Bullet();
	void Update(float dt);
};

