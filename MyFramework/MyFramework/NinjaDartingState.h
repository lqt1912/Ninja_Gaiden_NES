#pragma once
#include "NinjaState.h"
class NinjaDartingState : public NinjaState
{
public:
	NinjaDartingState(NinjaData *ninjaData);
	~NinjaDartingState();
	void Update(float dt);
	void HandleKeyboard(map<int, bool> keys);
	NinjaAnimations::eNinjaStates GetState();
	void OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data);
private:
	float s = 0.0f;

};


