#include "NinjaAttackingState.h"
#include "NinjaRunningState.h"
#include "NinjaIdlingState.h"
#include "NinjaSittingState.h"

NinjaAttackingState::NinjaAttackingState(NinjaData* ninjaData)
{
	ninjaData->ninja->allowRunAttack = false;
	s1 = 0.0f;
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->listAni->GetInstance()->mAni[NinjaAnimations::Attacking]->setCurrentIndex(1);
}


NinjaAttackingState::~NinjaAttackingState()
{
}

void NinjaAttackingState::Update(float dt)
{
	if (ninjaData->ninja->getY() < 150.0f)
	{
		ninjaData->ninja->SetVy(80.0f);
	}
	else if (ninjaData->ninja->getY() > 150)
	{
		ninjaData->ninja->setY(150.0f);
		ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	}

	
	if (s1  > 0.4 )
	{
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
		s1 = 0.0f;
	}
	else
		s1 += dt;
}

void NinjaAttackingState::HandleKeyboard(map<int, bool> keys)
{
	/*if (!keys[DIK_X] && ninjaData->ninja->getY() > 150 )
	{
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	}*/

}
NinjaAnimations::eNinjaStates NinjaAttackingState::GetState()
{
	return NinjaAnimations::Attacking;
}