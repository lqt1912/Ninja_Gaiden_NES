#include "NinjaImpactingState.h"
#include "NinjaRunningState.h"
#include "NinjaSittingState.h"
#include "NinjaIdlingState.h"

NinjaImpactingState::NinjaImpactingState(NinjaData *ninjaData)
{

	this->ninjaData = ninjaData;
	this->ninjaData->ninja->allowJump = true;
	this->ninjaData->ninja->allowRun = true;
	this->ninjaData->ninja->allowAttack = true;
	this->ninjaData->ninja->allowDart = true;

	this->ninjaData->ninja->SetVx(0);
}


NinjaImpactingState::~NinjaImpactingState()
{
}

void NinjaImpactingState::Update(float dt)
{
	if (s > 0.6)
	{
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
		s = 0;
	}
	else
	{
		s += dt;
	}
}
NinjaAnimations::eNinjaStates NinjaImpactingState::GetState()
{
	return NinjaAnimations::Impacting;
}
void NinjaImpactingState::HandleKeyboard(map<int, bool> keys)
{
	if (keys[DIK_LEFT] && keys[DIK_RIGHT])
	{

		return;
	}
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

}
void NinjaImpactingState::OnCollision(Object* impactor, Object::SideCollisions side, CollisionReturn data)
{

}