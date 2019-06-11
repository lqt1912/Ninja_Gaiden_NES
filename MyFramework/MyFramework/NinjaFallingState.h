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

	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);

protected:
	float acceleratorY;
	float acceleratorX;
	bool noPressed;
	bool isLeftOrRightKeyPressed;


};

