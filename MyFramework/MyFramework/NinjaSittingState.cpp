#include "NinjaSittingState.h"
#include "NinjaIdlingState.h"
#include "NinjaAttackSittingState.h"

NinjaSittingState::NinjaSittingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	ninjaData->ninja->isSitting = true;
}


NinjaSittingState::~NinjaSittingState()
{
}
void NinjaSittingState::Update(float dt)
{
}
NinjaAnimations::eNinjaStates NinjaSittingState::GetState()
{
	return NinjaAnimations::Sitting;
}
void NinjaSittingState::HandleKeyboard(map<int, bool> keys)
{
	if (!keys[DIK_DOWN])
	{
		NinjaState* newState = new NinjaIdlingState(ninjaData);
		this->ninjaData->ninja->SetState(newState);
	}

}
void NinjaSittingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}