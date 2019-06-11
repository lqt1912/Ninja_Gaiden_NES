#include "BulletBazooka.h"
#include "Ninja.h"


BulletBazooka::BulletBazooka()
{
	moveAni = new Animation("Resources/Enemy1/bazooka.png", 1, 1, 1);
	currentAni = moveAni;

	SetHeight(currentAni->GetHeight() + 2);
	SetWidth(currentAni->GetWidth() - 4);
	setActive(true);
	SetVy(0);
	
}


BulletBazooka::~BulletBazooka()
{
}

void BulletBazooka::Update(float dt)
{
	Enemy::Update(dt);
	x += vx * dt;

	if (!Collision::GetInstance()->isCollision(Camera::getInstance()->GetBound(), this->GetBound()))
	{
		setActive(false);
	}

}