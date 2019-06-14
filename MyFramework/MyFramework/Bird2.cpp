#include "Bird2.h"



BoundingBox Bird2::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width + 2;
	b.y = this->y + this->height / 2 - 4;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width / 2;
	b.h = this->height / 4;
	return b;
}

Bird2::Bird2()
{
	moveAni = new Animation("Resources/Enemy1/bird-2.png", 2, 1, 2, 0.05);
	resetState();
	this->SetWidth(currentAni->GetWidth());
	this->SetHeight(currentAni->GetHeight());
	srand(time(NULL));
	/*s = (float)( 1.0*(rand()%6 + 2 )/10);*/
	s = 0.9f;
	type = BIRD2_TYPE;
	scored = SCORE_3;
}


Bird2::~Bird2()
{
}


void Bird2::Update(float dt)
{
	if (!isFrozenEnemies)
	{
		if (x - Ninja::GetInstance()->getX() < 0)
		{
			this->setFlipVertical(false);
		}
		else
			this->setFlipVertical(true);
	}
	if (GetPosition().x == getInitPosition().x)
	{
		if (isFlip == false && Ninja::GetInstance()->GetPosition().x - getInitPosition().x >= DISTANCE_APPEAR - 20)
		{
			setActive(true);
			x += 10;
		}
		else if (isFlip == true && -Ninja::GetInstance()->GetPosition().x + getInitPosition().x >= DISTANCE_APPEAR -20)
		{
			setActive(true);
			x -= 10;
		}
		else
			setActive(false);
		x += 1;
	}
	
	if(isActive)
	{
		Enemy::Update(dt);

		if (x - Ninja::GetInstance()->GetPosition().x > 0 && rightToLeft)
		{
			this->moveTo(Ninja::GetInstance()->GetPosition().x - 50, Ninja::GetInstance()->GetPosition().y);
		}
		else if (x - Ninja::GetInstance()->GetPosition().x < 0 && !rightToLeft)
		{
			this->moveTo(Ninja::GetInstance()->GetPosition().x + 50, Ninja::GetInstance()->GetPosition().y);
		}

		if (s > 0.8)
		{
			if (x <= Ninja::GetInstance()->GetPosition().x - 30)
			{
				rightToLeft = false;
				vx = -vx;
			}
			else if (x >= Ninja::GetInstance()->GetPosition().x + 30)
			{
				rightToLeft = true;
				vx = -vx;
			}
			s = 0;
		}
		else
			s += dt;
		if (!Collision::GetInstance()->isCollision(Camera::getInstance()->GetBound(), GetBound()))
			setActive(false);
	}
}

