#include "NinjaClimbingState.h"
#include "NinjaClingingState.h"
#include "NinjaJumpingState.h"

NinjaClimbingState::NinjaClimbingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
}


NinjaClimbingState::~NinjaClimbingState()
{
}

void NinjaClimbingState::Update(float dt)
{

}
void NinjaClimbingState::HandleKeyboard(map<int, bool> keys)
{
	if (this->ninjaData->ninja->GetPosition().y >= this->ninjaData->ninja->limitUp )
	{
		this->ninjaData->ninja->SetVy(1);
		this->ninjaData->ninja->setY(this->ninjaData->ninja->GetPosition().y - 1);
		return;
	}
	else if (this->ninjaData->ninja->GetPosition().y <= this->ninjaData->ninja->limitDown)
	{
		this->ninjaData->ninja->SetVy(1);
		this->ninjaData->ninja->setY(this->ninjaData->ninja->GetPosition().y + 1);
		return;
	}
	if (keys[DIK_UP])
	{
		this->ninjaData->ninja->SetVy(NINJA_CLIMBING_SPEED);
	}
	else if (keys[DIK_DOWN])
	{
		this->ninjaData->ninja->SetVy(-NINJA_CLIMBING_SPEED);
	}
	else
	{
		this->ninjaData->ninja->SetState(new NinjaClingingState(ninjaData));
	}
		
}
NinjaAnimations::eNinjaStates NinjaClimbingState::GetState()
{
	return NinjaAnimations::Climbing;
}