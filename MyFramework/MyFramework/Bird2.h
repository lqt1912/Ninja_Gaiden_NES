#pragma once
#include "Enemy.h"
#include "Ninja.h"
class Bird2 : public Enemy
{
	
public:
	float s;
	bool rightToLeft = true;
	BoundingBox GetBoundingBox();
	Bird2();
	~Bird2();	

	void Update(float);

	int getType()
	{
		return BIRD2_TYPE;
	}

};

