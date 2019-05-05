#pragma once
#include "NinjaState.h"


class NinjaRunningState: public NinjaState
{
public:
	NinjaRunningState(NinjaData *ninjaData);
	void Update(float dt);
	~NinjaRunningState();
	//void Update(int dt);
	void HandleKeyboard(map<int, bool> keys);

	virtual NinjaAnimations::eNinjaStates GetState();
};

