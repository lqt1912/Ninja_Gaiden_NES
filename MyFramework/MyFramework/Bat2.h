#pragma once
#include "Enemy.h"
class Bat2 :
	public Enemy
{
public:
	Bat2();
	~Bat2();
	void Update(float);
	BoundingBox GetBoundingBox();
	int getType()
	{
		return BAT_TYPE;
	}
};

