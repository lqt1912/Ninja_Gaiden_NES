#include "NinjaSittingState.h"
#include "NinjaIdlingState.h"


NinjaSittingState::NinjaSittingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
}


NinjaSittingState::~NinjaSittingState()
{
}
void NinjaSittingState::Update(float dt)
{
}
NinjaAnimations::eNinjaStates NinjaSittingState::GetState()
{
	return NinjaAnimations::Sitting;
}
void NinjaSittingState::HandleKeyboard(map<int, bool> keys)
{
	if (!keys[DIK_DOWN])
	{
		NinjaState* newState = new NinjaIdlingState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}
}
