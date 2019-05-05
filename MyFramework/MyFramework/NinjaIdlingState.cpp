#include "NinjaIdlingState.h"
#include "NinjaJumpingState.h"
#include "NinjaRunningState.h"
#include "NinjaSittingState.h"
#include "NinjaAttackingState.h"
#include "NinjaDartingState.h"
NinjaIdlingState::NinjaIdlingState(NinjaData *ninjaData)
{
	
	ninjaData->ninja->SetVx(0);
	ninjaData->ninja->SetVy(0);
	this->ninjaData = ninjaData;
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
		if (keys[DIK_X] && ninjaData->ninja->allowAttack)
		{
			this->ninjaData->ninja->SetState(new NinjaAttackingState(ninjaData));
		}

		else
			return;
	}
	/*if (keys[DIK_DOWN])
	{
		NinjaState* newState = new NinjaSittingState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}*/
	 else if (keys[DIK_LEFT] || keys[DIK_RIGHT])
	{
		NinjaState* newState = new NinjaRunningState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}
	 else if (keys[DIK_DOWN])
	 {
		 NinjaState* newState = new NinjaSittingState(ninjaData);
		 this->ninjaData->ninja->SetState(newState);
	 }
	 //else if (keys[DIK_X] && ninjaData->ninja->allowAttack)
	 //{
		// NinjaState* newState = new NinjaAttackingState(ninjaData);
		// this->ninjaData->ninja->SetState(newState);
		// 
	 //}
	 //else if (keys[DIK_C])
	 //{
		//	 NinjaState* newState = new NinjaDartingState(ninjaData);
		//	 this->ninjaData->ninja->SetState(newState);	
	 //}
	else 
	{
		NinjaState* newState = new NinjaIdlingState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}


}


void NinjaIdlingState::Update(float dt)
{
	if (ninjaData->ninja->getY() < 150.0f)
	{
		ninjaData->ninja->SetVy(80.0f);
	}
	else if (ninjaData->ninja->getY() > 150)
	{
		ninjaData->ninja->setY(150.0f);
	}
}