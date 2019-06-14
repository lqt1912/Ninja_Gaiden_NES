#include "EnemyGreenBazooka.h"
#include "Ninja.h"


EnemyGreenBazooka::EnemyGreenBazooka()
{
	moveAni = new Animation("Resources/Enemy1/green_bazooka.png", 1, 1, 1);
	attackAni = new Animation("Resources/Enemy1/green_bazooka_attack.png", 2, 1, 2, 0.1);
	this->resetState();
	s = 1.4;
	vx = 0;
	type = GREEN_BAZOOKA_TYPE;
	scored = SCORE_2;
}


EnemyGreenBazooka::~EnemyGreenBazooka()
{
}
void EnemyGreenBazooka::Update(float dt)
{
	if (!isFrozenEnemies)
		if (Ninja::GetInstance()->GetPosition().x - x < 0)
		{
			setFlipVertical(true);
		}
		else
		{
			setFlipVertical(false);
		}

	if (currentAni == moveAni)
	{
		if (s > 3)
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