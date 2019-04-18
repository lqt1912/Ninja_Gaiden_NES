#include "NinjaJumpingState.h"
#include "NinjaFallingState.h"
#include "NinjaIdlingState.h"

NinjaJumpingState::NinjaJumpingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->SetVy(-150);

	acceleratorY = 6.0f;
	acceleratorX = 6.0f;

	noPressed = false;
}


NinjaJumpingState::~NinjaJumpingState()
{
}
void NinjaJumpingState::HandleKeyboard(map<int, bool> keys)
{
	
	if (keys[DIK_RIGHT])
	{
		ninjaData->ninja->SetReverse(false);

		this->ninjaData->ninja->SetVx(50);
		noPressed = false;
	}
	else if (keys[DIK_LEFT])
	{
		ninjaData->ninja->SetReverse(true);

		this->ninjaData->ninja->SetVx(-50);
		noPressed = false;
	}
	else
	{	
		noPressed = true;
	}
}
void NinjaJumpingState::Update(float dt)
{
	
	this->ninjaData->ninja->AddVy(acceleratorY);
	//DebugOut((wchar_t*)L"Jumpping : vy = %f, y = %f \n", ninjaData->ninja->GetVy(), ninjaData->ninja->getY());
	if (ninjaData->ninja->GetVy() >= 0.0f)
	{
		ninjaData->ninja->SetState(new NinjaFallingState(this->ninjaData));

		return;
	}

	if (noPressed)
	{
		if (ninjaData->ninja->GetMoveDirection() == Ninja::MoveToLeft)
		{
			//player dang di chuyen sang ben trai      
			if (ninjaData->ninja->GetVx() < 0)
			{
				this->ninjaData->ninja->AddVx(acceleratorX);

				if (ninjaData->ninja->GetVx() > 0)
					this->ninjaData->ninja->SetVx(0);
			}
		}
		else if ((ninjaData->ninja->GetMoveDirection() == Ninja::MoveToRight))
		{
			//player dang di chuyen sang phai   
			if (ninjaData->ninja->GetVx() > 0)
			{
				this->ninjaData->ninja->AddVx(-acceleratorX);

				if (ninjaData->ninja->GetVx() < 0)
					this->ninjaData->ninja->SetVx(0);
			}
		}
	}
}
NinjaAnimations::eNinjaStates NinjaJumpingState::GetState()
{
	return NinjaAnimations::Jumping;
}
