#include "EnemyGreenGun.h"



EnemyGreenGun::EnemyGreenGun()
{

	moveAni = new Animation("Resources/Enemy1/green_enemy_with_gun_walk.png", 2, 1, 2,0.2);
	attackAni = new Animation("Resources/Enemy1/green_enemy_attack.png", 2, 1, 2, 0.1);
	this->resetState();
	scored = SCORE_3;
	type = GREEN_GUN_TYPE;
}


EnemyGreenGun::~EnemyGreenGun()
{
}
BoundingBox EnemyGreenGun::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width / 2 - 4;
	b.y = this->y + this->height / 2;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width / 2;
	b.h = this->height;
	return b;
}
void EnemyGreenGun::Update(float dt)
{
	if (x <lastPositionX && x >firstPositionx)
	{
		if (x > lastPositionX + 100)
			return;
		if (!isFrozenEnemies)
			if (Ninja::GetInstance()->GetPosition().x - x < 0)
			{
				setFlipVertical(true);
				vx = -GREENGUN_SPEED;
			}
			else
			{
				setFlipVertical(false);
				vx = GREENGUN_SPEED;
			}
		if (!isFrozenEnemies)
			if (currentAni == moveAni)
			{
				if (s > 1.6)
				{
					isAttacking = true;
					currentAni = attackAni;
					s = 0;
				}
				else
				{
					s += dt;
				}
			}
			else if (currentAni == attackAni)
			{
				if (s > 0.6)
				{
					currentAni = moveAni;
					s = 0;
				}
				else
				{
					s += dt;
				}
			}
		Enemy::Update(dt);
	}
	else
		vx = -vx;
}

