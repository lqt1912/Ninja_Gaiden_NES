#pragma once
#include "NinjaState.h"
class NinjaClimbingState :
	public NinjaState
{
public:
	NinjaClimbingState(NinjaData*);
	~NinjaClimbingState();
	void Update(float);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
};

