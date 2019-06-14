#include "NinjaClingingState.h"
#include "NinjaClimbingState.h"
#include "NinjaJumpingState.h"

NinjaClingingState::NinjaClingingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->allowAttack = false;
	this->ninjaData->ninja->allowDart = false;
	this->ninjaData->ninja->isClimbing = true;
	this->ninjaData->ninja->allowJump = true;


}


NinjaClingingState::~NinjaClingingState()
{
}
void NinjaClingingState::Update(float dt)
{

}
void NinjaClingingState::HandleKeyboard(map<int, bool> keys)
{
	if (keys[DIK_UP] || keys[DIK_DOWN] )
	{
		if (this->ninjaData->ninja->allowClimb)
		{
			this->ninjaData->ninja->SetState(new NinjaClimbingState(ninjaData));
			return;
		}
	}
	if (keys[DIK_SPACE])
	{
		
		if (keys[DIK_LEFT] && !this->ninjaData->ninja->mCurrentReverse)
		{
			this->ninjaData->ninja->isOnWall = false;
			this->ninjaData->ninja->mCurrentReverse = true;
			this->ninjaData->ninja->SetVx(-60);
			//this->ninjaData->ninja->setX(this->ninjaData->ninja->GetPosition().x - 2);
			this->ninjaData->ninja->SetState(new NinjaJumpingState(ninjaData));
		}
		else 	if (keys[DIK_RIGHT] && this->ninjaData->ninja->mCurrentReverse)
		{
			this->ninjaData->ninja->isOnWall = false;
			this->ninjaData->ninja->mCurrentReverse = false;
			this->ninjaData->ninja->SetVx(60);
			// this->ninjaData->ninja->setX(this->ninjaData->ninja->GetPosition().x + 2);
			this->ninjaData->ninja->SetState(new NinjaJumpingState(ninjaData));
		}
	}

}
NinjaAnimations::eNinjaStates NinjaClingingState::GetState()
{
	return NinjaAnimations::Clinging;
}