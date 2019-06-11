#pragma once
#include "NinjaState.h"
class NinjaInjuringState : public NinjaState
{
public:
	NinjaInjuringState(NinjaData* ninjaData);
	~NinjaInjuringState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
};

