#include "Ninja.h"
#include "NinjaIdlingState.h"
#include "NinjaJumpingState.h"
#include "NinjaAttackingState.h"
#include "NinjaDartingState.h"
#include "NinjaAttackSittingState.h"
Ninja::Ninja()
{
	listAni = new NinjaAnimations();
	// Khoi tao animation
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Idling, "Resources/Ninja/ninja_stand.png",1,1,1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Running, "Resources/Ninja/ninja_run.png", 3, 1, 3);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Jumping, "Resources/Ninja/ninja_jump.png", 4, 1, 4,0.05f);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Sitting, "Resources/Ninja/ninja_sit.png", 1, 1, 1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Falling, "Resources/Ninja/ninja_jump.png", 4, 1, 4,0.05f);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Attacking, "Resources/Ninja/ninja_stand_attack.png", 4, 1, 4);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Attack_Sitting, "Resources/Ninja/ninja_sit_attack.png", 3, 1, 3);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Darting, "Resources/Ninja/ninja_dart.png", 3, 1, 3,0.167f);
	this->ninjaData = new  NinjaData();
	this->ninjaData->ninja = this;
	
	//this->vx = 0.5;
	//this->vy = 0;
	this->SetState(new NinjaIdlingState(this->ninjaData));
	dart = new Dart();
	dart->dartAni = new Animation("Resources/Ninja/dart.png", 2, 1, 2, 0.4f, D3DCOLOR_XRGB(0, 0, 0));
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

	if (isDarting)
	{
		//float dxx = this->getX() - dart->getX();
		//float dyy = this->getY() - dart->getY();
		//float length = sqrt(dxx*dxx + dyy * dyy);
		//dxx /= length;
		//dyy /= length;
		//dxx *= 20;
		//dyy *= 20;
		//dart->SetVx(dxx);
		//dart->SetVy(dyy);
		if (abs(dart->getX() - this->getX()) > 50)
		{
			dart->SetVx(-dart->GetVx());
			//float dxx = this->getX() - dart->getX();
			//float dyy = this->getY() - dart->getY();
			//float length = sqrt(dxx*dxx + dyy * dyy);
			//dxx /= length;
			//dyy /= length;
			//dxx *= 50;
			//dyy *= 50;
			//dart->SetVx(dxx);
			//dart->SetVy(dyy);
			dart->moveTo(this);
		}

		this->ninjaData->ninja->dart->Update(dt);
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
	
	if (isDarting)
	{
		dart->SetPosition(dart->GetPosition());
		dart->Draw(D3DXVECTOR3(dart->getX(), dart->getY(), 0));
	}
	else
	{

		dart->SetPosition(this->GetPosition());
	}
	
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
	else if (KeyCode == DIK_C)
	{
		if (allowDart)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::Idling)
				ninjaData->ninja->SetState(new NinjaDartingState(this->ninjaData));
			allowDart = false;
			isDarting = true;
			if (this->GetVx() < 0)
				dart->SetVx(-(dart->GetVx()));
		}
	}
	else if (KeyCode == DIK_X)
	{
		if (allowAttack)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Idling)
			{
				ninjaData->ninja->SetState(new NinjaAttackingState(this->ninjaData));
			}
			/*	else if (ninjaData->ninja->currentState == NinjaAnimations::Running)
				{
					ninjaData->ninja->SetState(new NinjaAttackingState(this->ninjaData));
				}*/
			allowAttack = false;
		}
		if (allowSitAttack)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::Sitting)
			{
				ninjaData->ninja->SetState(new NinjaAttackSittingState(this->ninjaData));
			}
			allowSitAttack = false;
		}
	}

}
void Ninja::OnKeyUp(int KeyCode)
{
	if (KeyCode == DIK_SPACE)
	{

		allowJump = true;
	}
	if (KeyCode == DIK_C)
	{

		allowDart = true;
	}
	if (KeyCode == DIK_X)
	{
		allowAttack = true;
		allowSitAttack = true;
		allowRunAttack = true;
	}

}

void Ninja::setY(int y)
{
	this->y = y;
}

void Ninja::setX(int x)
{
	this->x = x;
}
