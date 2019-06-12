#include "Star.h"



Star::Star()
{
	ani = new Animation("Resources/Ninja/star.png", 2, 1, 2,0.08);
	SetHeight(ani->GetHeight());
	SetWidth(ani->GetWidth());
	SetVy(0);
	if (Ninja::GetInstance()->mCurrentReverse )
		SetVx(-80);
	else
		SetVx(80);
	limitSpirit = STAR_LIMIT_SPIRIT;
	this->type = Object::eStar;
}


Star::~Star()
{
}
void Star::Update(float dt)
{
	ani->Update(dt);
	Object::Update(dt);
}
void Star::Update(float dt, BaseObjectList handleObject, Grid* grid)
{
	Weapon::Update(dt, handleObject, grid);
	Star::Update(dt);
	if (!Collision::GetInstance()->isCollision(Camera::getInstance()->GetBound(),GetBound()))
		setActive(false);
}
BoundingBox Star::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width ;
	b.y = this->y + this->height / 2;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width;
	b.h = this->height;
	return b;
}