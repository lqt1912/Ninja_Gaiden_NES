#pragma once
#include "Weapon.h"
class FireWheel :
	public Weapon
{
public:
	FireWheel();
	~FireWheel();
	void Update(float);
	void Update(float dt, vector<Object*> handleObject, Grid* grid);
	BoundingBox GetBoundingBox();
};

