#include "EnemyPinkWalk.h"


EnemyPinkWalk::EnemyPinkWalk()
{
	moveAni = new Animation("Resources/Enemy1/enemy_pink_walk.png", 2, 1, 2,0.2);
	attackAni = new Animation("Resources/Enemy1/enemy_pink_attack.png", 3, 1, 3,0.2);
	currentAni = moveAni;
	vx = PINKWALK_SPEED;
	isAttacking = false;
	type = PINK_WALK_TYPE;
	scored = SCORE_3;
}


EnemyPinkWalk::~EnemyPinkWalk()
{
}

void EnemyPinkWalk::Update(float dt)
{
	if (isFrozenEnemies == false)
	{
		this->MoveBetween(this->firstPositionx, this->lastPositionX);
		if (Ninja::GetInstance()->GetPosition().x - x < 0)
			setFlipVertical(true);
		else
			setFlipVertical(false);
	}

	if (currentAni == moveAni && isFrozenEnemies == false)
	{
		if (s >1.4)
		{
			isAttacking = false;
			currentAni = attackAni;
			s = 0;
		}
		else
		{
			s += dt;
		}
	}
	else if(currentAni == attackAni && isFrozenEnemies == false)
	{
		if (s > 0.4)
		{
			isAttacking = true;
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
