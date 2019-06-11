#include "Bat2.h"
#include "Ninja.h"


Bat2::Bat2()
{
	moveAni = new Animation("Resources/Enemy1/bat-2.png", 2, 1, 2, 0.2);
	currentAni = moveAni;
	this->SetWidth(currentAni->GetWidth());
	this->SetHeight(currentAni->GetHeight());
	vx = 80;
	vy = 100;
	type = BAT_TYPE;
}


Bat2::~Bat2()
{
}
void Bat2::Update(float dt)
{
	if (GetPosition().x == getInitPosition().x)
	{
		if (isFlip == false && Ninja::GetInstance()->GetPosition().x - getInitPosition().x >= DISTANCE_APPEAR - 30)
		{
			SetVx(80);
			setActive(true);
			x += 10;
		}
		else if (isFlip == true && -Ninja::GetInstance()->GetPosition().x + getInitPosition().x >= DISTANCE_APPEAR - 30)
		{
			SetVx(-80);
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
	if (y > getInitPosition().y + 40 || y < getInitPosition().y - 40)
		vy = -vy;
	Enemy::Update(dt);
}


BoundingBox  Bat2::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width + 2;
	b.y = this->y + this->height / 2;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width / 2;
	b.h = this->height / 4;
	return b;
}