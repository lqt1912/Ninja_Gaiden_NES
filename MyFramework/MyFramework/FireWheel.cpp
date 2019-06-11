#include "FireWheel.h"



FireWheel::FireWheel()
{
	ani = new Animation("Resources/Ninja/fire_wheel.png", 4, 1, 4);
	SetHeight(ani->GetHeight() - 4);
	SetWidth(ani->GetWidth() - 4);
	if(Ninja::GetInstance()->mCurrentReverse)
		SetVx(-80);
	else
		SetVx(80);
	SetVy(250);
	limitSpirit = FIREWHEEL_LIMIT_SPIRIT;
}


FireWheel::~FireWheel()
{
}

void FireWheel::Update(float dt)
{
	ani->Update(dt);
	Object::Update(dt);
}
void FireWheel::Update(float dt, vector<Object*> handleObject, Grid* grid)
{
	Weapon::Update(dt, handleObject, grid);
	FireWheel::Update(dt);
	if (y>200)
		setActive(false);
}
BoundingBox FireWheel::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width / 2 - 8;
	b.y = this->y + this->height / 2;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width;
	b.h = this->height;
	return b;
}