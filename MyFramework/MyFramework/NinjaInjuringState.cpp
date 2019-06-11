#include "NinjaInjuringState.h"
#include "NinjaIdlingState.h"
#include "NinjaImpactingState.h"


NinjaInjuringState::NinjaInjuringState(NinjaData *ninjaData)
{
	Sound::getInstance()->play("ninja_collided_enemy", false, 1);
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->allowAttack = false;
	this->ninjaData->ninja->allowDart = false;
	this->ninjaData->ninja->allowJump = false;
	this->ninjaData->ninja->allowRun = false;
	this->ninjaData->ninja->SetVy(NINJA_INJURING_SPEED_Y);
	if (this->ninjaData->ninja->mCurrentReverse)
		this->ninjaData->ninja->SetVx(NINJA_INJURING_SPEED_X);
	else 
		this->ninjaData->ninja->SetVx(-NINJA_INJURING_SPEED_X);
	this->ninjaData->ninja->noCollision = 0;
	this->ninjaData->ninja->isInjuring = true;
}


NinjaInjuringState::~NinjaInjuringState()
{
}
void NinjaInjuringState::Update(float dt)
{
	this->ninjaData->ninja->AddVy(-10);
	if (ninjaData->ninja->isOnGround)
		ninjaData->ninja->SetState(new NinjaImpactingState(ninjaData));
}
void  NinjaInjuringState::HandleKeyboard(map<int, bool> keys)
{

}
NinjaAnimations::eNinjaStates  NinjaInjuringState::GetState()
{
	return NinjaAnimations::Injuring;
}
void  NinjaInjuringState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}