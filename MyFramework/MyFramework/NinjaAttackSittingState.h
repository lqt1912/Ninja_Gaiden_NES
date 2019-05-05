#pragma once
#include "NinjaState.h"
class NinjaAttackSittingState : public NinjaState
{
public:
	NinjaAttackSittingState(NinjaData* ninjaData);
	~NinjaAttackSittingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	virtual NinjaAnimations::eNinjaStates GetState();
	float s2;

};

