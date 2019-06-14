#include "Knife.h"



Knife::Knife()
{
	this->type = Object::eKnife;
	this->SetWidth(26);
	this->SetHeight(16);
	s = 0;
	limitSpirit = 0;
}


Knife::~Knife()
{
}
void Knife::Update(float dt)
{
	if(Ninja::GetInstance()->isSitting)
		this->y = Ninja::GetInstance()->GetPosition().y;
	else 
		this->y = Ninja::GetInstance()->GetPosition().y + 4;

	if(Ninja::GetInstance()->getFlip())
		this->x = Ninja::GetInstance()->GetPosition().x - 20;
	else
		this->x = Ninja::GetInstance()->GetPosition().x + 20;
}
void Knife::Update(float dt, vector<Object*> handleObject,Grid *grid)
{
	
	if (s < 0.01)
	{
		this->Update(dt);
		Weapon::Update(dt, handleObject, grid);
		s += dt;
	}
	else
	{
		setActive(false);
		s = 0;
	}
}
BoundingBox Knife::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width / 2 - 8;
	b.y = this->y + this->height / 2;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width - 4;
	b.h = this->height;
	return b;
}
