#include "NinjaAttackingState.h"
#include "NinjaRunningState.h"
#include "NinjaIdlingState.h"
#include "NinjaSittingState.h"
#include "NinjaFallingState.h"

NinjaAttackingState::NinjaAttackingState(NinjaData* ninjaData)
{
	ninjaData->ninja->allowRunAttack = false;
	s1 = 0.0f;
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->listAni->GetInstance()->mAni[NinjaAnimations::Attacking]->SetCurrentIndex(1);
	this->ninjaData->ninja->SetVx(0.0f);
	this->ninjaData->ninja->SetVy(this->ninjaData->ninja->GetVy() / 3.6);
}


NinjaAttackingState::~NinjaAttackingState()
{
}

void NinjaAttackingState::Update(float dt)
{

	
	if (s1  > Ninja::GetInstance()->listAni->GetInstance()->mAni[NinjaAnimations::Attacking]->mTotalFrame * 
		Ninja::GetInstance()->listAni->GetInstance()->mAni[NinjaAnimations::Attacking]->mTimePerFrame)
	{
		this->ninjaData->ninja->SetState(new NinjaFallingState(ninjaData));
		s1 = 0.0f;
		Ninja::GetInstance()->isAttacking = false;
	}
	else
	{
		s1 += dt;
		Ninja::GetInstance()->isAttacking = true;
	}
}

void NinjaAttackingState::HandleKeyboard(map<int, bool> keys)
{
	if(ninjaData->ninja->GetVy() > 0)
		if (keys[DIK_RIGHT])
			this->ninjaData->ninja->SetVx(50);
		else if (keys[DIK_LEFT])
			this->ninjaData->ninja->SetVx(-50);
}
NinjaAnimations::eNinjaStates NinjaAttackingState::GetState()
{
	return NinjaAnimations::Attacking;
}
void NinjaAttackingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}