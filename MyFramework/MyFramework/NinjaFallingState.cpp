#include "NinjaFallingState.h"
#include "NinjaIdlingState.h"
#include "NinjaAttackingState.h"


NinjaFallingState::NinjaFallingState(NinjaData * ninjaData)
{
	this->ninjaData = ninjaData;
	this->ninjaData->ninja->SetVy(-80);

	acceleratorY = NINJA_ACE_Y;
	acceleratorX = NINJA_ACE_X;
	noPressed = false;
}

NinjaFallingState::~NinjaFallingState()
{
}

void NinjaFallingState::Update(float dt)
{
	//MessageBox(NULL, L"", L"", 1);
	if (ninjaData->ninja->GetVy() == 0.0f)
	{
		ninjaData->ninja->SetState(new NinjaIdlingState(this->ninjaData));
		return;
	}
	else
		this->ninjaData->ninja->AddVy(-acceleratorY);

}

void NinjaFallingState::HandleKeyboard(map<int, bool> keys)
{
	if(ninjaData->ninja->allowRun)
		if (keys[DIK_RIGHT] && keys[DIK_LEFT])
		{
			ninjaData->ninja->SetVx(0.0f);

		}
		else if (keys[DIK_RIGHT])
		{
			ninjaData->ninja->SetReverse(false);

			this->ninjaData->ninja->SetVx(NINJA_JUMP_VX + 20);
			noPressed = false;
		}
		else if (keys[DIK_LEFT])
		{
			ninjaData->ninja->SetReverse(true);
			this->ninjaData->ninja->SetVx(-NINJA_JUMP_VX - 20);
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

void NinjaFallingState::OnCollision(Object* impactor, Object::SideCollisions side, Object::ResultCollision data)
{
	//switch (side)
	//{
	//	case Object::Bottom:
	//		
	//		//DebugOut((wchar_t*)L"region %d %d ", data.RegionCollision.bottom, data.RegionCollision.top	);
	//		if (data.RegionCollision.right - data.RegionCollision.left >= 6.0f)
	//		{
	//			
	//			this->ninjaData->ninja->AddPosition(0, (int)(ninjaData->ninja->dy * data.t));
	//			this->ninjaData->ninja->SetState(new NinjaIdlingState(ninjaData));
	//		}
	//}

}