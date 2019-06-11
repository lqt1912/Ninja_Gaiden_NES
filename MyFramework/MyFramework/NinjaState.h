#pragma once
#include "NinjaData.h"
#include "Ninja.h"
#include "GameSound.h"
#include <map>
using namespace std;

class NinjaState
{
public:

	virtual void Update(float dt);
	virtual void HandleKeyboard(map<int, bool> keys);
	virtual  NinjaAnimations::eNinjaStates GetState() = 0;
	//side va cham voi player
	virtual void OnCollision(Object* impactor, Object::SideCollisions side,Object::ResultCollision data);
	~NinjaState();
protected:
	NinjaState(NinjaData *ninjaData);
	NinjaState();

	NinjaData *ninjaData;

};

