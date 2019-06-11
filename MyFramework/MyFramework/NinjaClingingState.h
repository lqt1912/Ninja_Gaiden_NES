#pragma once
#include "NinjaState.h"
class NinjaClingingState :
	public NinjaState
{
public:
	NinjaClingingState(NinjaData*);
	~NinjaClingingState();
	void Update(float);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
};

