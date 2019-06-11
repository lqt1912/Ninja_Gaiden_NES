#pragma once
#include "NinjaState.h"
class NinjaIdlingState :public NinjaState
{
public:
	NinjaIdlingState(NinjaData *ninjaData);
	~NinjaIdlingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
	NinjaAnimations::eNinjaStates GetState();
	float s = 0;
};

