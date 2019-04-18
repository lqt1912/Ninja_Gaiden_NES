#include "NinjaIdlingState.h"

#include "NinjaRunningState.h"
#include "NinjaSittingState.h"
NinjaIdlingState::NinjaIdlingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->SetVx(0);
	this->ninjaData->ninja->SetVy(0);
}


NinjaIdlingState::~NinjaIdlingState()
{
}
NinjaAnimations::eNinjaStates NinjaIdlingState::GetState()
{
	return NinjaAnimations::Idling;
}

void NinjaIdlingState::HandleKeyboard(map<int, bool> keys)
{
	if (keys[DIK_LEFT] && keys[DIK_RIGHT])
	{
		return;
	}
	/*if (keys[DIK_DOWN])
	{
		NinjaState* newState = new NinjaSittingState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}*/
	 if (keys[DIK_LEFT] || keys[DIK_RIGHT])
	{
		NinjaState* newState = new NinjaRunningState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}
	 else if (keys[DIK_DOWN])
	 {
		 NinjaState* newState = new NinjaSittingState(ninjaData);
		 this->ninjaData->ninja->SetState(newState);
	 }
	else 
	{
		NinjaState* newState = new NinjaIdlingState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}

}


