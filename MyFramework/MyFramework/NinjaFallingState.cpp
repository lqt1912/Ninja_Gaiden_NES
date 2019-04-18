#include "NinjaFallingState.h"
#include "NinjaIdlingState.h"



NinjaFallingState::NinjaFallingState(NinjaData * ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->SetVy(150);

	acceleratorY =6.0f;
	acceleratorX = 6.0f;

	noPressed = false;
}

NinjaFallingState::~NinjaFallingState()
{
}

void NinjaFallingState::Update(float dt)
{
	this->ninjaData->ninja->AddVy(-acceleratorY);
	//DebugOut((wchar_t*)L"Falling : vy = %f, y = %f \n" ,ninjaData->ninja->GetVy(), ninjaData->ninja->getY());
	if (ninjaData->ninja->GetVy() <= 0.0f)
	{
		ninjaData->ninja->SetState(new NinjaIdlingState(this->ninjaData));
		
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

void NinjaFallingState::HandleKeyboard(map<int, bool> keys)
{
	if (keys[DIK_RIGHT])
	{
		ninjaData->ninja->SetReverse(false);

		//di chuyen sang phai
		/*if (this->ninjaData->ninja->GetVx() < 180) 
		{
			this->ninjaData->ninja->AddVx(acceleratorX);

			if (this->ninjaData->ninja->GetVx() >= 180)
			{
				this->ninjaData->ninja->SetVx(180);
			}
		}*/
		this->ninjaData->ninja->SetVx(50);
		noPressed = false;
	}
	else if (keys[DIK_LEFT])
	{
		ninjaData->ninja->SetReverse(true);

		//di chuyen sang trai
		/*if (this->ninjaData->ninja->GetVx() > -180)
		{
			this->ninjaData->ninja->AddVx(-acceleratorX);

			if (this->ninjaData->ninja->GetVx() < -180)
			{
				this->ninjaData->ninja->SetVx(-180);
			}
		}*/
		this->ninjaData->ninja->SetVx(-50);
		noPressed = false;
	}
	else
	{

		noPressed = true;
	}
}

NinjaAnimations::eNinjaStates NinjaFallingState::GetState()
{
	return NinjaAnimations::eNinjaStates::Falling;
}
