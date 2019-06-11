#include "SwordOfPink.h"



SwordOfPink::SwordOfPink()
{
	moveAni = new Animation("Resources/Enemy1/weapon_pink.png", 4, 1, 4);
	currentAni = moveAni;
	setActive(true);
	SetHeight(currentAni->GetHeight() + 6);
	SetWidth(currentAni->GetWidth()+6);
	SetVy(100);
}


SwordOfPink::~SwordOfPink()
{
}



void SwordOfPink::Update(float dt)
{

	Enemy::Update(dt);
	x += vx * dt;
	y += vy * dt;
	if (y >= limitY)
		vy = -vy;
	if (y < 0)
		setActive(false);

}

