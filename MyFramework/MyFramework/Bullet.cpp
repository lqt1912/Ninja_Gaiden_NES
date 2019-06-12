#include "Bullet.h"



Bullet::Bullet()
{
	moveAni = new Animation("Resources/Enemy1/bullet.png", 1, 1, 1);
	currentAni = moveAni;

	SetHeight(BUllET_HEIGHT );
	SetWidth(BULLET_WIDTH);
	setActive(true);
	SetVy(0);
}


Bullet::~Bullet()
{
}
void Bullet::Update(float dt)
{
	Enemy::Update(dt);
	x += vx * dt;

	if (!Collision::GetInstance()->isCollision(Camera::getInstance()->GetBound(), this->GetBound()))
	{
		setActive(false);
	}
	if (vx<0 && vx > -60)
		AddVx(-2);
	else if (vx > 0 && vx < 60)
		AddVx(2);
}