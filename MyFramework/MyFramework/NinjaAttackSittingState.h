#pragma once
#include "NinjaState.h"
class NinjaAttackSittingState : public NinjaState
{
public:
	NinjaAttackSittingState(NinjaData* ninjaData);
	~NinjaAttackSittingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
private:
	float s2;

};

