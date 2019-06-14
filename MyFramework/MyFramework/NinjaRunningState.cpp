#include "NinjaRunningState.h"
#include "NinjaAttackingState.h"

#include "NinjaIdlingState.h"

NinjaRunningState::NinjaRunningState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
}

void NinjaRunningState::Update(float dt)
{

}


NinjaRunningState::~NinjaRunningState()
{
}

NinjaAnimations::eNinjaStates NinjaRunningState::GetState()
{
	return NinjaAnimations::Running;
}

void NinjaRunningState::HandleKeyboard(map<int, bool> keys)
{

	
	if (keys[DIK_RIGHT] && keys[DIK_LEFT])
	{
		this->ninjaData->ninja->SetVx(0.0f);
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	}

	else if (keys[DIK_RIGHT])
	{
		
			this->ninjaData->ninja->SetReverse(false);
			this->ninjaData->ninja->SetVx(NINJA_RUNNING_SPEED);
		

	}
	else if (keys[DIK_LEFT])
	{

			this->ninjaData->ninja->SetReverse(true);
			this->ninjaData->ninja->SetVx(-NINJA_RUNNING_SPEED);

	}
	else
	{
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	}

}


