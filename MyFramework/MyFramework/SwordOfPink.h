#pragma once
#include "Ninja.h"
#include "Enemy.h"
class SwordOfPink:public Enemy
{
public:

	SwordOfPink();
	~SwordOfPink();
	void Update(float dt);

	float limitY;
};

