#pragma once
#include "Ninja.h"
#include "Enemy.h"
class SwordOfPink:public Enemy
{
	
	
	Object::WeaponTypes type;
public:

	SwordOfPink();
	~SwordOfPink();
	void Update(float dt);

	float limitY;
};

