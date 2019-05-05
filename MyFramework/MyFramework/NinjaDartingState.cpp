#include "NinjaDartingState.h"
#include "NinjaIdlingState.h"

NinjaDartingState::NinjaDartingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->listAni->GetInstance()->mAni[NinjaAnimations::Darting]->setCurrentIndex(1);
}


NinjaDartingState::~NinjaDartingState()
{
}
void NinjaDartingState::Update(float dt)
{
	
	if (s > 0.45f)
	{
		this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
		s = 0.0f;
	}
	else
		s += dt;
}
void NinjaDartingState::HandleKeyboard(map<int, bool> keys)
{


}
NinjaAnimations::eNinjaStates NinjaDartingState::GetState()
{
	return NinjaAnimations::Darting;
}