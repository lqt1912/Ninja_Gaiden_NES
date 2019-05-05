#include "NinjaSittingState.h"
#include "NinjaIdlingState.h"
#include "NinjaAttackSittingState.h"

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
	//else if (keys[DIK_DOWN] && keys[DIK_X] && this->ninjaData->ninja->allowSitAttack)
	//{
	//	NinjaState* newState = new NinjaAttackSittingState(ninjaData);
	//	this->ninjaData->ninja->SetState(newState);
	//}

	
}
