#include "NinjaJumpingState.h"
#include "NinjaFallingState.h"
#include "NinjaIdlingState.h"
#include "NinjaAttackingState.h"
NinjaJumpingState::NinjaJumpingState(NinjaData *ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->SetVy(NINJA_JUMP_HEIGHT);

	acceleratorY = NINJA_ACE_Y;
	acceleratorX = NINJA_ACE_X;

	noPressed = false;
}

NinjaJumpingState::~NinjaJumpingState()
{

}
void NinjaJumpingState::HandleKeyboard(map<int, bool> keys)
{
	 if (keys[DIK_RIGHT] && keys[DIK_LEFT])
	{
		ninjaData->ninja->SetVx(0.0f);
	}
	else if (keys[DIK_RIGHT])
	{
		ninjaData->ninja->SetReverse(false);
		this->ninjaData->ninja->SetVx(NINJA_JUMP_VX);
		noPressed = false;
	}
	else if (keys[DIK_LEFT])
	{
		ninjaData->ninja->SetReverse(true);
		this->ninjaData->ninja->SetVx(-NINJA_JUMP_VX);
		noPressed = false;
	}
	else
	{	
		noPressed = true;
	}
}
void NinjaJumpingState::Update(float dt)
{
	
	this->ninjaData->ninja->AddVy(-acceleratorY);
	
	if (ninjaData->ninja->GetVy() <= 0.0f)
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

void NinjaJumpingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{
	//switch (side)
	//{
	//case Object::Bottom:
	//	//if (data.RegionCollision.right - data.RegionCollision.left >= 6.0f)
	//	
	//		
	//		this->ninjaData->ninja->AddPosition(0,(data.RegionCollision.top - data.RegionCollision.bottom));
	//	
	//	//this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	//}
}