#pragma once
#include "NinjaState.h"
class NinjaDyingState:public NinjaState
{
public:
	NinjaDyingState(NinjaData *ninjaData);
	~NinjaDyingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
};

