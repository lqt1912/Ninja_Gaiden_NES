#include "LeoPard.h"
#include "Ninja.h"


LeoPard::LeoPard()
{

	moveAni = new Animation("Resources/Enemy1/leopard.png", 2, 1, 2, 0.25);
	this->resetState();
	this->SetWidth(currentAni->GetWidth());
	this->SetHeight(currentAni->GetHeight());
	SetVx(LEOPARD_SPEED);
	type = LEOPARD_TYPE;
	SetVy(-55);
	scored = SCORE_3;
}


LeoPard::~LeoPard()
{

}

void LeoPard::Update(float dt)
{

	if (Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), curGround))
	{
		if (y < this->getInitPosition().y + 14)
			y += 4;
	}
	if (y < 0)
	{
		setActive(false);
		this->Respawn();
	}

	if (GetPosition().x == getInitPosition().x)
	{
		if (isFlip == false && Ninja::GetInstance()->GetPosition().x - getInitPosition().x >= DISTANCE_APPEAR)
		{
			SetVx(LEOPARD_SPEED);
			setActive(true);
			x += 10;
		}
		else if (isFlip == true && -Ninja::GetInstance()->GetPosition().x + getInitPosition().x >= DISTANCE_APPEAR)
		{
			SetVx(-LEOPARD_SPEED);
			setActive(true);
			x -= 10;
		}
		else
			setActive(false);
		x += 1;
	}
	if (!Collision::GetInstance()->isCollision(Camera::getInstance()->GetBound(), this->GetBound()))
	{
		Reset(getInitPosition());
	}
	Enemy::Update(dt);
}
bool LeoPard::detectGroundA(vector<BoundingBox> grounds)
{
	BoundingBox ninjaBox = this->GetBoundingBox();

	// neu dang o ground cu thi return
	if (Collision::GetInstance()->CollisionAABB(ninjaBox, curGround))
		return true;
	// neu khong co ground thi kiem tra ground moi
	for (auto g : grounds)
	{
		g.y -= 15;
		if (Collision::GetInstance()->CollisionAABB(ninjaBox, g))
		{
			curGround = g;
			return true;
		}
	}
	return false;
}

void LeoPard::OnCollisionWithGroundA(vector<BoundingBox> grounds)
{
	// tim ground va cham 
	if (detectGroundA(grounds))
	{
		if (this->vy < 0 && Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), curGround))
		{
			this->vy = this->dy = 0;
			this->y = curGround.y + ((int)(this->height) >> 1) - 16;
		}
	}
	// neu khong thi roi 
	else if (!this->vy)
	{
		y += 24;
		vy = -100;
	}

}