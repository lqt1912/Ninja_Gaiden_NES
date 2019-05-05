#pragma once
#include "NinjaState.h"
class NinjaDartingState : public NinjaState
{
public:
	NinjaDartingState(NinjaData *ninjaData);
	~NinjaDartingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	virtual NinjaAnimations::eNinjaStates GetState();
	float s = 0.0f;

};


