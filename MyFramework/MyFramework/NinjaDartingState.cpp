#include "NinjaDartingState.h"
#include "NinjaFallingState.h"

NinjaDartingState::NinjaDartingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->listAni->GetInstance()->mAni[NinjaAnimations::Darting]->SetCurrentIndex(1);
	this->ninjaData->ninja->SetVx(0.0f);
	this->ninjaData->ninja->SetVy(this->ninjaData->ninja->GetVy() / 3.6);
}


NinjaDartingState::~NinjaDartingState()
{
}
void NinjaDartingState::Update(float dt)
{

	
	if (s > 0.45f)
	{
		this->ninjaData->ninja->SetState(new NinjaFallingState(ninjaData));
		s = 0.0f;
	}
	else
		s += dt;
}
void NinjaDartingState::HandleKeyboard(map<int, bool> keys)
{
	if (ninjaData->ninja->GetVy() > 0)
		if (keys[DIK_RIGHT])
			this->ninjaData->ninja->SetVx(50);
		else if (keys[DIK_LEFT])
			this->ninjaData->ninja->SetVx(-50);

}
NinjaAnimations::eNinjaStates NinjaDartingState::GetState()
{
	return NinjaAnimations::Darting;
}
void NinjaDartingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}