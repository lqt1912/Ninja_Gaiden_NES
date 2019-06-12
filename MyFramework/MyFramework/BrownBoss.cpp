#include "BrownBoss.h"


BrownBoss::BrownBoss()
{
	moveAni = new Animation("Resources/Enemy1/BrownBossStand.png", 1, 1, 1);
	flyAni = new Animation("Resources/Enemy1/BrownBossFly.png", 1, 1, 1);
	destroyedAni = new Animation("Resources/Enemy1/BossDestroyed.png", 2, 1, 2, 0.2);
	currentAni = moveAni;
	this->SetWidth(BOSS_WIDTH);
	this->SetHeight(BOSS_HEIGHT);
	acceleratorY = 4.0f;
	isIdling = false;
	vx = -120;
	vy = 220;
	count = 2;
	blood = 16;
	type = BROWN_BOSS_TYPE;
	scored =SCORE_3;
}


BrownBoss::~BrownBoss()
{

}



void BrownBoss::Update(float dt)
{
	if (blood < 1)
	{
		currentAni = destroyedAni;
		currentAni->Update(dt);
		Sound::getInstance()->play("Boss_Die", true, 0);
		s1 += dt;
		x -= vx * dt;
		y -= vy * dt;
		if (s1 > 2)
			isWin = true;
		return;
	}

	if (vx < 0)
		setFlipVertical(true);
	else if (vx > 0)
		setFlipVertical(false);
	if (!isIdling)
	{
		currentAni = flyAni;
		this->AddVy(-acceleratorY);
		if (vy <= 0)
		{
			acceleratorY = -4;
			vy = -220;
		}
		if (y <= 50)
		{

			vx = 0;
			vy = 0;
			acceleratorY = 4;
			isIdling = true;
			currentAni = moveAni;
		}
	}
	else
	{
		if (s > 0)
		{
			s -= dt;
		}
		else
		{
			if (count == 2)
			{
				isAttacking = true;
				count = 0;
			}
			else
				count += 1;
			if (IsFlipVertical())
			{
				x -= 6;
				vx = 120;
			}
			else
			{
				vx = -120;
				x += 6;
			}
			vy = 220;
			s = 1;
			isIdling = false;
		}
	}
	

}
BoundingBox BrownBoss::GetBoundingBox()
{
	BoundingBox b;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width/2;
	b.h = this->height/2;
	b.x = this->x - this->width / 2 ;
	b.y = this->y;
	return b;
}
void BrownBoss::MinusBlood()
{
	blood -= 1;
	Game_UI::getInstance()->MinusEnemyHealth();
}