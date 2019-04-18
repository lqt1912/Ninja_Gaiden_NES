#include "Ninja.h"
#include "NinjaIdlingState.h"
#include "NinjaJumpingState.h"
Ninja::Ninja()
{
	listAni = new NinjaAnimations();
	// Khoi tao animation
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Idling, "Resources/Ninja/ninja_stand.png", 1, 1, 1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Running, "Resources/Ninja/ninja_run.png", 3, 1, 3);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Jumping, "Resources/Ninja/ninja_jump.png", 4, 1, 4);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Sitting, "Resources/Ninja/ninja_sit.png", 1, 1, 1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Falling, "Resources/Ninja/ninja_jump.png", 4, 1, 4);
	this->ninjaData = new  NinjaData();
	this->ninjaData->ninja = this;
	

	//this->vx = 0.5;
	//this->vy = 0;
	this->SetState(new NinjaIdlingState(this->ninjaData));

}


Ninja::~Ninja()
{
}

void Ninja::Update(float dt)
{
	listAni->GetInstance()->mAni[currentState]->Update(dt);

	if (this->ninjaData->ninjaState)
	{
		
		this->ninjaData->ninjaState->Update(dt);
		
	
	}
	
	Object::Update(dt);
	
}

void Ninja::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->ninjaData->ninjaState)
	{
		this->ninjaData->ninjaState->HandleKeyboard(keys);
	}
}
void Ninja::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}

void Ninja::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	listAni->GetInstance()->mAni[currentState]->FlipVertical(mCurrentReverse);
	listAni->GetInstance()->mAni[currentState]->SetPosition(this->GetPosition());
	listAni->GetInstance()->mAni[currentState]->Draw(D3DXVECTOR3(x,y, 0));
	
}

void Ninja::SetState(NinjaState *newState)
{
	delete this->ninjaData->ninjaState;

	this->ninjaData->ninjaState = newState;

	this->ChangeAnimation(newState->GetState());

	currentState = newState->GetState();
}

RECT Ninja::GetBound()
{
	RECT rect;
	rect.left = this->x - listAni->GetInstance()->mAni[currentState]->GetWidth() / 2;
	rect.right = rect.left + listAni->GetInstance()->mAni[currentState]->GetWidth();
	rect.top = this->y - listAni->GetInstance()->mAni[currentState]->GetHeight() / 2;
	rect.bottom = rect.top + listAni->GetInstance()->mAni[currentState]->GetHeight();

	return rect;
}

void Ninja::ChangeAnimation(NinjaAnimations::eNinjaStates state)
{
	/*switch (state)
	{
	case NinjaAnimations::eNinjaStates::Idling:
		listAni->GetInstance()->Idling;
		break;
	case NinjaAnimations::eNinjaStates::Running:
		listAni->GetInstance()->Running;
		break;
	case NinjaAnimations::eNinjaStates::Jumping:
		listAni->GetInstance()->Jumping;
		break;
	case NinjaAnimations::eNinjaStates::Falling:
		listAni->GetInstance()->Falling;
		break;
	}*/
	currentState = state;
	this->width = listAni->GetInstance()->mAni[currentState]->GetWidth();
	this->height = listAni->GetInstance()->mAni[currentState]->GetHeight();
}

Ninja::eMoveDirection Ninja::GetMoveDirection()
{
	if (this->vx > 0)
	{
		return MoveToRight;
	}
	else if (this->vx < 0)
	{
		return MoveToLeft;
	}

	return None;
}

NinjaAnimations::eNinjaStates Ninja::GetState()
{
	return currentState;
}

void Ninja::OnKeyPressed(int KeyCode)
{
	if (KeyCode == DIK_SPACE)
	{
		
		if (allowJump)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Running || ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Idling)
			{
				ninjaData->ninja->SetState(new NinjaJumpingState(this->ninjaData));
			}
			allowJump = false;
		}
	}
}
void Ninja::OnKeyUp(int KeyCode)
{
	if(KeyCode == DIK_SPACE)
		allowJump = true;
}

void Ninja::setY(int y)
{
	this->y = y;
}

void Ninja::setX(int x)
{
	this->x = x;
}
