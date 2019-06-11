#pragma once
#include "Object.h"



class Collision
{
public:


	~Collision();
	bool isCollision(RECT rect1, RECT rect2);
	
	bool CollisionAABB(BoundingBox b1, BoundingBox b2);
	Object::ResultCollision CollisionSweptAABB(BoundingBox b1, BoundingBox b2);
	static Collision* GetInstance();
private:
	Collision();
	static Collision* instance ;

	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	float xEntry, yEntry;
	float xExit, yExit;

	float entryTime;
	float exitTime;

	//van toc tuong doi cua 2 vat
	float vx, vy;
};

