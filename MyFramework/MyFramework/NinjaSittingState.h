#pragma once
#include "NinjaState.h"

class NinjaSittingState:public NinjaState
{
public:
	NinjaSittingState(NinjaData *ninjaData);
	~NinjaSittingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	virtual NinjaAnimations::eNinjaStates GetState();
	
};

