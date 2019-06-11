#pragma once
#include "Weapon.h"
class Star :
	public Weapon
{
public:
	Star();
	~Star();
	virtual void Update(float);
	void Update(float dt, BaseObjectList handleObject, Grid* grid);
	BoundingBox GetBoundingBox();
};

