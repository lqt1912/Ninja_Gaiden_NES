#include "Ninja.h"
#include "NinjaClimbingState.h"
#include "NinjaIdlingState.h"
#include "NinjaJumpingState.h"
#include "NinjaAttackingState.h"
#include "NinjaDartingState.h"
#include "NinjaAttackSittingState.h"
#include "NinjaFallingState.h"
#include "NinjaInjuringState.h"
#include "NinjaClingingState.h"
Ninja* Ninja::instance = NULL;

Ninja* Ninja::GetInstance()
{
	if (instance == NULL)
		instance = new Ninja();
	return instance;
}

Ninja::Ninja()
{
	listAni = NinjaAnimations::GetInstance();
	// Khoi tao animation
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Idling, "Resources/Ninja/ninja_stand.png", 1, 1, 1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Running, "Resources/Ninja/ninja_run.png", 3, 1, 3);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Jumping, "Resources/Ninja/ninja_jump.png", 4, 1, 4, 0.05f);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Sitting, "Resources/Ninja/ninja_sit.png", 1, 1, 1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Falling, "Resources/Ninja/ninja_jump.png", 4, 1, 4, 0.05f);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Attacking, "Resources/Ninja/ninja_stand_attack.png", 4, 1, 4);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Attack_Sitting, "Resources/Ninja/ninja_sit_attack.png", 3, 1, 3);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Darting, "Resources/Ninja/ninja_dart.png", 3, 1, 3, 0.167f);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Injuring, "Resources/Ninja/ninja_die.png", 1, 1, 1);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Impacting, "Resources/Ninja/ninja_injure.png", 3, 1, 3);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Climbing, "Resources/Ninja/ninja_climb.png", 2, 1, 2);
	listAni->GetInstance()->AddAnimation(NinjaAnimations::Clinging, "Resources/Ninja/ninja_cling.png", 1,1,1);
	this->ninjaData = new  NinjaData();
	this->ninjaData->ninja = this;
	this->ninjaData->ninja->SetWidth(32);
	this->ninjaData->ninja->SetHeight(32);
	this->SetState(new NinjaFallingState(this->ninjaData));
	Tag = Object::eNinja;
	int physical = 16;
	int spirit = 90;
	long score = 0;
	int life = 3;
}

Ninja::~Ninja()
{
}

void Ninja::Update(float dt)
{	
	if (isOnWall)
	{
		if (currentState == NinjaAnimations::Climbing)
		{
			listAni->GetInstance()->mAni[currentState]->Update(dt);
			dy = vy * dt;
			this->y += dy;
		}
		return;
	}
	// ninja roi xuong va chet
	if (vy != 0 && currentState)
	{
		isOnGround = false;
		if (y < 0)
		{
			
			Reset();
			life = life - 1;
			Camera::getInstance()->SetPosition(D3DXVECTOR3(0, 208, 0));
			Game_UI::getInstance()->setLife(life);
		}
	}

	// update state 
	isFlip = mCurrentReverse;
	listAni->GetInstance()->mAni[currentState]->Update(dt);

	if (this->ninjaData->ninjaState)
	{
		this->ninjaData->ninjaState->Update(dt);
	}

	dx = vx * dt;
	dy = vy * dt;

    this->x += dx;
	this->y += dy;
}

void Ninja::Update(float dt, vector<Object*> handleObject)
{
	this->Update(dt);

	// ninja oncollision 
	// khi ninja va cham voi enemy va bat ra, se co 1 khoang thoi gian ngan ko bi va cham

	if (currentState == NinjaAnimations::Injuring || currentState == NinjaAnimations::Impacting)
		return;
	if (noCollision < 0.6 && isInjuring)
	{
		noCollision += dt;
		return;
	}
	else
	{
		noCollision = 0;
		isInjuring = false;
	}
	// xu li va cham khi va cham voi enemy,holder,item
	for (auto obj : handleObject)
	{
		switch (obj->getObjectType())
		{
			BoundingBox b1, b2;
			//enemy
		case Object::eEnemy:
		{
			auto e = (Enemy*)obj;
			// enemy chet roi thi khong va cham nua 
			if (e->isDead)
				continue;

			b1 = this->GetBoundingBox();
			b2 = e->GetBoundingBox();

			if (isAttacking)
			{
				b2.vx = 0;
				b2.vy = 0;
				b1.vx = 0;
				b1.vy = 0;
			}

			auto resultEnemy = Collision::GetInstance()->CollisionSweptAABB(b2, b1);
			auto resultNinja = Collision::GetInstance()->CollisionSweptAABB(b1, b2);
			auto resultBasic = Collision::GetInstance()->CollisionAABB(b1, b2);

			if (resultEnemy.isCollision || resultNinja.isCollision || resultBasic)
			{
				// neu va cham , ninja mat 1 mau 
				if (physical > 0)
				{
					physical -= NINJA_HITPOINT_PER_COLLIDED;
				}
				if (isOnWall)
				{
					if (this->ninjaData->ninja->mCurrentReverse)
					{
						this->ninjaData->ninja->isOnWall = false;
						this->ninjaData->ninja->mCurrentReverse = true;
						this->ninjaData->ninja->SetVx(-60);

					}
					else if (!this->ninjaData->ninja->mCurrentReverse)
					{
						this->ninjaData->ninja->isOnWall = false;
						this->ninjaData->ninja->mCurrentReverse = false;
						this->ninjaData->ninja->SetVx(60);
					}
				}
			}

			// xet phuong va cham 
			if (resultNinja.side == Object::Right || resultEnemy.side == Object::Left)
			{
				this->y = y + 30;
				this->mCurrentReverse = false;
				this->SetState(new NinjaInjuringState(ninjaData));
				this->isAttacking = false;
			}
			else if (resultNinja.side == Object::Left || resultEnemy.side == Object::Right)
			{
				this->y = y + 30;
				this->mCurrentReverse = true;
				this->SetState(new NinjaInjuringState(ninjaData));
				this->isAttacking = false;
			}
			else if (resultNinja.side == Object::Top || resultEnemy.side == Object::Top || resultNinja.side == Object::Bottom || resultEnemy.side == Object::Bottom)
			{
				this->y = y + 30;
				this->SetState(new NinjaInjuringState(ninjaData));
				this->isAttacking = false;
			}
			else if (resultBasic == true)
			{
				this->y = y + 30;
				this->SetState(new NinjaInjuringState(ninjaData));
				this->isAttacking = false;
			}

			
			break;
		}
		// item 
		case Object::eItem:
		{
			auto i = (Item*)obj;
			
			b1 = this->GetBoundingBox();
			b2 = i->GetBoundingBox();
			// va cham voi item thi se duoc spirit strengh, bonus score,..
			if (Collision::GetInstance()->CollisionAABB(b1, b2))
			{
				switch (i->getTypeItem())
				{
				case Object::SpiritBlue:
					AddSpirit(SPIRIT_BLUE);
					break;
				case Object::SpiritRed:
					AddSpirit(SPIRIT_RED);
					break;
				case Object::BonusBlue:
					AddScore(BONUS_BLUE);
					break;
				case Object::BonusRed:
					AddScore(BONUS_RED);
					break;
				case Object::Physical:
					AddPhysical(BONUS_PHYSICAL);
					for (int i = 0; i < 6; i++)
						Game_UI::getInstance()->PlusEnemyHealth();
					break;
				case Object::TimeFreeze:
					isFrozenEnemies = true;
					break;
				case Object::Star:
					Game_UI::getInstance()->setItem(i->ani);
					specialWeapon = Object::eStar;
					break;
				case Object::WindmillStar:
					specialWeapon = Object::eWindStar;
					Game_UI::getInstance()->setItem(i->ani);
					break;
				case Object::FireWheel:
					specialWeapon = Object::eFireWheel;
					Game_UI::getInstance()->setItem(i->ani);
					break;
				default:
					break;
				}
				Sound::getInstance()->play("Pick_Item", false, 1);
				i->setActive(false);
			}
			break;
		}
		}
	}
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
	
	if (position == D3DXVECTOR3())
	{
		Camera::getInstance()->ConvertFromViewportToWorldport(this->mPosition);

		listAni->GetInstance()->mAni[currentState]->FlipVertical(mCurrentReverse);
		listAni->GetInstance()->mAni[currentState]->SetPosition(this->mPosition);
		listAni->GetInstance()->mAni[currentState]->Draw(this->mPosition);
	}
	else
	{
		Camera::getInstance()->ConvertFromViewportToWorldport(position);

		listAni->GetInstance()->mAni[currentState]->FlipVertical(mCurrentReverse);
		listAni->GetInstance()->mAni[currentState]->SetPosition(position);
		listAni->GetInstance()->mAni[currentState]->Draw(position);
	}
}

void Ninja::SetState(NinjaState * newState)
{
	allowMoveLeft = true;
	allowMoveRight = true;

	delete this->ninjaData->ninjaState;

	this->ninjaData->ninjaState = newState;

	this->ChangeAnimation(newState->GetState());

	currentState = newState->GetState();
}

RECT Ninja::GetBound()
{
	RECT rect;
	rect.left =(int) this->x - listAni->GetInstance()->mAni[currentState]->GetWidth() / 2;
	rect.right = rect.left + listAni->GetInstance()->mAni[currentState]->GetWidth();
	rect.top =(int) this->y + listAni->GetInstance()->mAni[currentState]->GetHeight() / 2;
	rect.bottom = rect.top - listAni->GetInstance()->mAni[currentState]->GetHeight();

	return rect;
}

void Ninja::ChangeAnimation(NinjaAnimations::eNinjaStates state)
{
	currentState = state;
	this->width = 32;/*listAni->GetInstance()->mAni[currentState]->GetWidth();*/
	this->height = 32;/*listAni->GetInstance()->mAni[currentState]->GetHeight();*/
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
				Sound::getInstance()->play("ninja_jump",false,1);
			}
			allowJump = false;
		}
	}
	else if (KeyCode == DIK_C)
	{
		Sound::getInstance()->play("ninja_attack", false, 1);
		if (allowDart)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::Idling
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Jumping
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Falling
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Running
				||ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Impacting)

				ninjaData->ninja->SetState(new NinjaDartingState(this->ninjaData));
				allowDart = false;
				isDarting = true;
		}
	}
	else if (KeyCode == DIK_X)
	{
		if (allowAttack)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Idling
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Jumping
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Falling
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Running
				|| ninjaData->ninja->currentState == NinjaAnimations::eNinjaStates::Impacting)
			{
				ninjaData->ninja->SetState(new NinjaAttackingState(this->ninjaData));
				Sound::getInstance()->play("ninja_attack", false, 1);
			}
			allowAttack = false;
		}
		if (allowSitAttack)
		{
			if (ninjaData->ninja->currentState == NinjaAnimations::Sitting)
			{
				ninjaData->ninja->SetState(new NinjaAttackSittingState(this->ninjaData));
				Sound::getInstance()->play("ninja_attack", false, 1);
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

// oncollision with ground
bool Ninja::detectGround(vector<Object*> grounds)
{
	BoundingBox ninjaBox = this->GetBoundingBox();
	
	// neu dang o ground cu thi return
	if (Collision::GetInstance()->CollisionAABB(ninjaBox, curGround))
		return true;
	// neu khong co ground thi kiem tra ground moi
	for (auto g : grounds)
	{
		if (Collision::GetInstance()->CollisionAABB(ninjaBox,g->GetBoundingBox()))
		{
			
			curGround = g->GetBoundingBox();
			return true;
		}
	}
	return false;
}

void Ninja::OnCOllisionWithGround(vector<Object*> grounds)
{

	if (this->vy)
	{
		this->isOnGround = false;
	}
	// tim ground va cham 
	if (detectGround(grounds))
	{
		if (this->vy <= 0 && Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(),curGround))
		{
			
			this->isOnGround = true;
			this->vy = this->dy = 0;
			this->y = curGround.y + ((int)(this->height) >> 1) - 20;
		}
	}
	// neu khong thi roi 
	else if (!this->vy && currentState != NinjaAnimations::Injuring)
	{
		this->SetState(new NinjaFallingState(ninjaData));
	}

}

bool Ninja::detectGroundA(vector<BoundingBox> grounds)
{
	BoundingBox ninjaBox = this->GetBoundingBox();
	// neu dang o ground cu thi return
	if (Collision::GetInstance()->CollisionAABB(ninjaBox, curGround))
		return true;
	// neu khong co ground thi kiem tra ground moi
	for (auto g : grounds)
	{
		if (Collision::GetInstance()->CollisionAABB(ninjaBox, g))
		{
			curGround = g;
			return true;
		}
	}
	return false;
}

void Ninja::OnCollisionWithGroundA(vector<BoundingBox> grounds)
{
	if (this->vy)
	{
		this->isOnGround = false;
	}
	// tim ground va cham 
	if (detectGroundA(grounds))
	{
		if (this->vy < 0 && Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(),curGround))
		{
			this->isOnGround = true;
			this->vy = this->dy = 0;
			this->y = curGround.y + ((int)(this->height) >> 1) -28;
		}
	}
	// neu khong thi roi 
	else if (!this->vy && currentState != NinjaAnimations::Injuring)
	{
		y += 10;
		if (mCurrentReverse)
			vx = -NINJA_JUMP_VX;
		else
			vx = NINJA_JUMP_VX;
		this->SetState(new NinjaFallingState(ninjaData));
	
		Game_UI::getInstance()->setLife(life);
	}
	//check ngung di chuyen
	BoundingBox ninjaBox = GetBoundingBox();
	for (auto w : grounds)
	{
		w.h *= 2;
		w.y -= w.h;
		ResultCollision result = Collision::GetInstance()->CollisionSweptAABB(ninjaBox, w);
		///ResultCollision result1 = Collision::GetInstance()->CollisionSweptAABB(w,ninjaBox);
		if (result.isCollision)
		{
			if (result.side == Object::Right)
			{
				//	MessageBox(NULL, L"Right", L"", 1);

				this->x -= 2;

			}
			else if (result.side == Object::Left)
			{
				this->x += 2;

			}
		}
	}
}

BoundingBox Ninja::GetBoundingBox()
{
	BoundingBox b;
	b.w = this->width/2;
	b.h = this->height/2;
	b.x = this->x - b.w ;
	b.y = this->y + b.h;
	b.vx = this->dx;
	b.vy = this->dy;
	return b;
}
void Ninja::Reset()
{
	
	SetPosition(50, 100);
	mCurrentReverse = false;
}

void Ninja::AddPhysical(int a)
{
	physical += a;
	if (physical > 16)
		physical = 16;
}
int Ninja::getPhysical()
{
	return physical;
}
void Ninja::AddSpirit(int a)
{
	spirit += a;
	if (spirit > 99)
		spirit = 99;
}
int Ninja::getSpirit()
{
	return spirit;
}
void Ninja::AddScore(long a)
{
	score += a;
	if (score > 999999)
		score = 999999;
}
long Ninja::getScore()
{
	return score;
}
void Ninja::AddLife(int a)
{
	life += a;
	if (life > 99)
		life = 99;

}
int Ninja::getLife()
{
	return life;
}
void Ninja::OnCollisionWithWall(vector<BoundingBox> walls)
{
	BoundingBox ninjaBox = GetBoundingBox();
	for (auto w : walls)
	{

		w.h *= 2;
		w.y -= w.h;
		ResultCollision result = Collision::GetInstance()->CollisionSweptAABB(ninjaBox, w);
		///ResultCollision result1 = Collision::GetInstance()->CollisionSweptAABB(w,ninjaBox);
		if (result.isCollision)
		{

			if (result.side == Object::Right)
			{
				mCurrentReverse = false;
				isOnWall = true;
				this->SetState(new NinjaClingingState(ninjaData));
			}
			else if (result.side == Object::Left)
			{
				mCurrentReverse = true;
				isOnWall = true;
				this->SetState(new NinjaClingingState(ninjaData));
			}

		}
	}
}
void Ninja::OnCollisionWithWallA(vector<BoundingBox> walls)
{
	BoundingBox ninjaBox = GetBoundingBox();

	for (auto w : walls)
	{
		
		if (Collision::GetInstance()->CollisionAABB(ninjaBox,w))
		{

				//MessageBox(NULL, L"", L"", 1);
				isOnWall = true;
				this->x -= 2;
				if (this->GetState() == NinjaAnimations::Jumping || this->GetState() == NinjaAnimations::Falling)
					this->SetState(new NinjaClimbingState(ninjaData));

		}
	}
}
void Ninja::OnCollisionWithLadder(vector<BoundingBox> ladders)
{
	BoundingBox ninjaBox = GetBoundingBox();
	for (auto w : ladders)
	{
		w.h *= 2;
		w.y -= w.h;
		ResultCollision result = Collision::GetInstance()->CollisionSweptAABB(ninjaBox, w);
		///ResultCollision result1 = Collision::GetInstance()->CollisionSweptAABB(w,ninjaBox);
		if (result.isCollision)
		{

			if (result.side == Object::Right)
			{
				mCurrentReverse = false;
				isOnWall = true;
				this->SetState(new NinjaClingingState(ninjaData));
			}
			else if (result.side == Object::Left)
			{
				mCurrentReverse = true;
				isOnWall = true;
				this->SetState(new NinjaClingingState(ninjaData));
			}
			this->limitUp = w.y + w.h - 10;
			this->limitDown = w.y - w.h;
			this->allowClimb = true;
		}
	}
}