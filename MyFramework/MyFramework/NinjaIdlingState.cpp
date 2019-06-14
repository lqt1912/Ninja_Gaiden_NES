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
	this->ninjaData->ninja->allowAttack = true;
	this->ninjaData->ninja->allowDart = true;
	this->ninjaData->ninja->allowJump = true;
	this->ninjaData->ninja->allowRun = true;
	this->ninjaData->ninja->isAttacking = false;
	this->ninjaData->ninja->isDarting = false;
	this->ninjaData->ninja->isClimbing = false;
	ninjaData->ninja->isSitting = false;
	this->ninjaData->ninja->isOnWall = false;
	this->ninjaData->ninja->allowClimb = false;
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
	//if (ninjaData->ninja->getY() != 50)
	//	return;

	if (keys[DIK_LEFT] && keys[DIK_RIGHT])
	{

			return;
	}
	 else if (keys[DIK_LEFT] || keys[DIK_RIGHT] )
	{

		NinjaState* newState = new NinjaRunningState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}
	 else if (keys[DIK_DOWN])
	 {
		 NinjaState* newState = new NinjaSittingState(ninjaData);
		 this->ninjaData->ninja->SetState(newState);
	 }
}


void NinjaIdlingState::Update(float dt)
{
	/*if (ninjaData->ninja->getY() > 50.0f)
	{
		ninjaData->ninja->SetVy(-80.0f);
	}
	else if (ninjaData->ninja->getY() < 50)
	{
		ninjaData->ninja->setY(50.0f);
	}*/

}

void NinjaIdlingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}