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


	if (keys[DIK_RIGHT] && keys[DIK_LEFT]&& !keys[DIK_X])
	{
		this->ninjaData->ninja->SetVx(0.0f);
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	}

	else if (keys[DIK_RIGHT])
	{
		if (keys[DIK_X] && this->ninjaData->ninja->allowRunAttack)
		{
			this->ninjaData->ninja->SetVx(0.0f);
			this->ninjaData->ninja->SetState(new NinjaAttackingState(ninjaData));
		}
		else 
		{
			this->ninjaData->ninja->SetReverse(false);
			this->ninjaData->ninja->SetVx(100.0f);
		}

	}
	else if (keys[DIK_LEFT])
	{
		if (keys[DIK_X] && this->ninjaData->ninja->allowRunAttack)
		{
			this->ninjaData->ninja->SetVx(0.0f);
			this->ninjaData->ninja->SetState(new NinjaAttackingState(ninjaData));
		}
		else
		{
			this->ninjaData->ninja->SetReverse(true);
			this->ninjaData->ninja->SetVx(-100.0f);
		}

	}
	else
	{
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	}
}

