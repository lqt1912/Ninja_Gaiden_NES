#include "EnemyBrownKnife.h"
#include "Ninja.h"


EnemyBrownKnife::EnemyBrownKnife()
{
	moveAni = new Animation("Resources/Enemy1/enemy_brown_with_knife.png", 5, 1, 5, 0.2);
	this->resetState();

	type = BROWN_KNIFE_TYPE;
	if (Ninja::GetInstance()->getX() - this->GetPosition().x < 0)
		this->setFlipVertical(true);
	else
		this->setFlipVertical(false);
}


EnemyBrownKnife::~EnemyBrownKnife()
{
}

void EnemyBrownKnife::Update(float dt)
{
	this->MoveBetween(this->firstPositionx, this->lastPositionX);
	if (vx >= 0)
		this->setFlipVertical(false);
	else this->setFlipVertical(true);
	Enemy::Update(dt);
	
}
