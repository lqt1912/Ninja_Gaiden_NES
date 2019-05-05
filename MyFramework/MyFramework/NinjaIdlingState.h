#pragma once
#include "NinjaState.h"
class NinjaIdlingState :public NinjaState
{
public:
	NinjaIdlingState(NinjaData *ninjaData);
	~NinjaIdlingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);

	virtual NinjaAnimations::eNinjaStates GetState();

};

