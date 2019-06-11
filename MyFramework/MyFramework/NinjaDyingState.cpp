#include "NinjaDyingState.h"



NinjaDyingState::NinjaDyingState(NinjaData* ninjaData)
{
	this->ninjaData = ninjaData;
}


NinjaDyingState::~NinjaDyingState()
{
}
void NinjaDyingState::Update(float dt)
{

}
void  NinjaDyingState::HandleKeyboard(map<int, bool> keys)
{

}
NinjaAnimations::eNinjaStates  NinjaDyingState::GetState()
{
	return NinjaAnimations::Dying;
}
void  NinjaDyingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{

}