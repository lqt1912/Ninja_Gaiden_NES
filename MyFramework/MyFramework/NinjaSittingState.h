#pragma once
#include "NinjaState.h"

class NinjaSittingState:public NinjaState
{
public:
	NinjaSittingState(NinjaData *ninjaData);
	~NinjaSittingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
};

