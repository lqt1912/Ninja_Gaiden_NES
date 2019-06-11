#pragma once
#include "Enemy.h"
class LeoPard :
	public Enemy
{
public:
	LeoPard();
	~LeoPard();
	bool detectGroundA(vector<BoundingBox> grounds);
	void OnCollisionWithGroundA(vector<BoundingBox> grounds);
	int getType()
	{
		return LEOPARD_TYPE;
	}
	void Update(float);
};

