#pragma once
#include "NinjaData.h"
#include "Ninja.h"
#include <map>
using namespace std;

class NinjaState
{
public:

	virtual void Update(float dt);
	virtual void HandleKeyboard(map<int, bool> keys);
	virtual  NinjaAnimations::eNinjaStates GetState() = 0;
	~NinjaState();
protected:
	NinjaState(NinjaData *ninjaData);
	NinjaState();

	NinjaData *ninjaData;

};

