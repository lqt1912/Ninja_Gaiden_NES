#pragma once
#include "NinjaState.h"
class NinjaJumpingState: public NinjaState
{
public:
	NinjaJumpingState(NinjaData *ninjaData);
	~NinjaJumpingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);

	virtual NinjaAnimations::eNinjaStates GetState();
	

protected:
	float acceleratorY;
	float acceleratorX;
	bool noPressed;
	bool allowMoveRight, allowMoveLeft;
};

