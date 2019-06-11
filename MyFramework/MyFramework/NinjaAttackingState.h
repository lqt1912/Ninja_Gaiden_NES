#pragma once
#include "NinjaState.h"

class NinjaAttackingState :
	public NinjaState
{
public:
	NinjaAttackingState(NinjaData* ninjaData);
	~NinjaAttackingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
private:
	float s1;
};

