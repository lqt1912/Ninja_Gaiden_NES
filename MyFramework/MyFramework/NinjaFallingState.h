#pragma once
#include "NinjaState.h"
class NinjaFallingState :
	public NinjaState
{
public:
	NinjaFallingState(NinjaData *ninjaData);
	~NinjaFallingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);

	virtual NinjaAnimations::eNinjaStates GetState();


protected:
	float acceleratorY;
	float acceleratorX;
	bool noPressed;
	bool isLeftOrRightKeyPressed;


};

