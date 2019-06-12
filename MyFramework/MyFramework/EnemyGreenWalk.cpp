#include "EnemyGreenWalk.h"
#include "Ninja.h"


EnemyGreenWalk::EnemyGreenWalk()
{
	moveAni = new Animation("Resources/Enemy1/green_walk.png", 2, 1, 2, 0.1);
	this->resetState();

	SetVx(GREENWALK_SPEED);
	SetVy(-10);
	type = GREEN_WALK_TYPE;
	scored = SCORE_3;
}


EnemyGreenWalk::~EnemyGreenWalk()
{
}
void EnemyGreenWalk::Update(float dt)
{
	if (Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), boundGround))
	{
		this->vy = 0;
		this->dy = 0;
	}
	else this->dy = vy * dt;
	if (y < 0)
	{
		setActive(false);
		this->Respawn();
	}

	if (x == getInitPosition().x)
	{
		if (isFlip == false && Ninja::GetInstance()->GetPosition().x - x >= 70)
		{
			SetVx(GREENWALK_SPEED);
			setActive(true);
			x += 10;
		}
		else if (isFlip == true && -Ninja::GetInstance()->GetPosition().x + x >= 70)
		{
			SetVx(-GREENWALK_SPEED);
			setActive(true);
			x -= 10;
		}
		else
			setActive(false);
		x += 1;
	}

	Enemy::Update(dt);

}
bool EnemyGreenWalk::detectGroundA(vector<BoundingBox> grounds)
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

void EnemyGreenWalk::OnCollisionWithGroundA(vector<BoundingBox> grounds)
{
	// tim ground va cham 
	if (detectGroundA(grounds))
	{
		if (this->vy < 0 && Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), curGround))
		{
			this->vy = this->dy = 0;
			this->y = curGround.y + ((int)(this->height) >> 1) - 28;
		}
	}
	// neu khong thi roi 
	else if (!this->vy)
	{
		y += 16;
		vy = -100;
	}
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
				this->x += 4;
				this->y += 32;

			}
			else if (result.side == Object::Left)
			{
				this->x -= 2;
				this->y += 32;
			}
		}
	}
}