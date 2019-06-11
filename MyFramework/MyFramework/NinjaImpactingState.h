#pragma once
#include "NinjaState.h"
class NinjaImpactingState : public NinjaState
{
public:
	NinjaImpactingState(NinjaData *ninjaData);
	~NinjaImpactingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	void OnCollision(Object* impactor, Object::SideCollisions side, CollisionReturn data);
	NinjaAnimations::eNinjaStates GetState();
private:
	float s;
};

