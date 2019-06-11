#pragma once
#include "NinjaState.h"


class NinjaRunningState: public NinjaState
{
public:
	NinjaRunningState(NinjaData *ninjaData);
	void Update(float dt);
	~NinjaRunningState();
	void HandleKeyboard(map<int, bool> keys);
	
	NinjaAnimations::eNinjaStates GetState();
};

