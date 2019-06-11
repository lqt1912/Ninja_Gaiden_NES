#pragma once
#include "Weapon.h"
class Knife :
	public Weapon
{
public:
	Knife();
	~Knife();
	void Update(float dt);
	void Update(float dt, vector<Object*> handleObject,Grid *grid);
	BoundingBox GetBoundingBox();
	float s;
};

