#include "NinjaAttackSittingState.h"
#include "NinjaIdlingState.h"
#include "NinjaSittingState.h"

NinjaAttackSittingState::NinjaAttackSittingState(NinjaData* ninjaData)
{
	s2 = 0.0f;
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->listAni->GetInstance()->mAni[NinjaAnimations::Attack_Sitting]->SetCurrentIndex(0);
}


NinjaAttackSittingState::~NinjaAttackSittingState()
{
}

void NinjaAttackSittingState::Update(float dt)
{
	if (s2 > 0.35)
	{
		this->ninjaData->ninja->SetState(new NinjaSittingState(ninjaData));
		s2 = 0.0f;
		Ninja::GetInstance()->isAttacking = false;
	}
	else
	{
		s2 += dt;
		Ninja::GetInstance()->isAttacking = true;
	}
}
void NinjaAttackSittingState::HandleKeyboard(map<int, bool> keys)
{

}

NinjaAnimations::eNinjaStates NinjaAttackSittingState::GetState()
{
	return NinjaAnimations::Attack_Sitting;
}
void NinjaAttackSittingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}