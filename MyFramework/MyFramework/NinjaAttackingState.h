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
	virtual NinjaAnimations::eNinjaStates GetState();
	float s1;
};

