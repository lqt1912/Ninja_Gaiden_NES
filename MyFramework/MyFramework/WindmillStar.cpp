#include "WindmillStar.h"



WindmillStar::WindmillStar()
{
	limitSpirit = WINDMILLSTAR_LIMIT_SPIRIT;
	this->type = Object::eWindStar;
	isBack = false;
	s = 0.5;
}


WindmillStar::~WindmillStar()
{
}

void WindmillStar::Update(float dt, vector<Object*> handleObject, Grid* grid)
{

	if (isBack)
	{

		if (isActive)
		{

			if (x - Ninja::GetInstance()->GetPosition().x < -60)
			{
				temp.x = Ninja::GetInstance()->GetPosition().x + 70;
				temp.y = Ninja::GetInstance()->GetPosition().y - 40;
				rightToLeft = false;
				vx = 200;
			}
			else if (x - Ninja::GetInstance()->GetPosition().x > 60)
			{
				temp.x = Ninja::GetInstance()->GetPosition().x - 70;
				temp.y = Ninja::GetInstance()->GetPosition().y + 40;
				rightToLeft = true;
				vx = -200;
			}
			else
			{
				if (rightToLeft)
				{
					this->moveTo(temp.x, temp.y, 100);
				}
				else if (!rightToLeft)
				{
					this->moveTo(temp.x, temp.y, 100);
				}
			}



			ani->Update(dt);
			Object::Update(dt);
			Weapon::Update(dt, handleObject, grid);
			if (Collision::GetInstance()->isCollision(Ninja::GetInstance()->GetBound(), GetBound()))
			{
				setActive(false);
				isBack = false;
			}
		}
	}
	else
	{
		Star::Update(dt, handleObject, grid);
	}

}