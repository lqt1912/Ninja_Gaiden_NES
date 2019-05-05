#include "NinjaAttackSittingState.h"
#include "NinjaIdlingState.h"
#include "NinjaSittingState.h"

NinjaAttackSittingState::NinjaAttackSittingState(NinjaData* ninjaData)
{
	s2 = 0.0f;
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->listAni->GetInstance()->mAni[NinjaAnimations::Attack_Sitting]->setCurrentIndex(0);
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
	}
	else
		s2 += dt;
}
void NinjaAttackSittingState::HandleKeyboard(map<int, bool> keys)
{
	//if (!keys[DIK_X] && keys[DIK_DOWN])
	//{
	//	NinjaState* newState = new NinjaSittingState(ninjaData);
	//	this->ninjaData->ninja->SetState(newState);
	//}
	//else if (!keys[DIK_X] && !keys[DIK_DOWN])
	//{
	//	this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	//}
}

NinjaAnimations::eNinjaStates NinjaAttackSittingState::GetState()
{
	return NinjaAnimations::Attack_Sitting;
}