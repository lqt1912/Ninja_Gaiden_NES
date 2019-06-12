#include "BulletBoss.h"

#include "Collision.h"

BulletBoss::BulletBoss()
{
	moveAni = new Animation("Resources/Enemy1/bullet_boss.png", 1, 1, 1);
	currentAni = moveAni;

	SetHeight(BUllET_HEIGHT);
	SetWidth(BULLET_WIDTH);
	setActive(true);
	SetVy(0);
}


BulletBoss::~BulletBoss()
{
}
void BulletBoss::Update(float dt)
{
	Enemy::Update(dt);
	x += vx * dt;

	if (!Collision::GetInstance()->isCollision(Camera::getInstance()->GetBound(), this->GetBound()))
	{
		setActive(false);
	}

}