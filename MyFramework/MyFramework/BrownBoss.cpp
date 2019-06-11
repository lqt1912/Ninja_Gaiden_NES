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
}


BrownBoss::~BrownBoss()
{

}



void BrownBoss::Update(float dt)
{
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
				vx = 120;
			else
				vx = -120;
			vy = 220;
			s = 1;
			isIdling = false;
		}
	}
	if (blood == 0)
	{
		if (currentAni)
		{
			if (currentAni == destroyedAni)
			{
				if (s < 10)
				{
					s += dt;
				}
				else
				{
					s = 0;
					isActive = false;
					Ninja::GetInstance()->AddScore(20);
					//SetPosition(D3DXVECTOR2(-100, -100));
				}
			}
			dx = vx * dt;
			dy = vy * dt;

			if (currentAni == destroyedAni)
			{
				
				currentAni->Update(dt);
			}
			if (isFrozenEnemies == true)
				return;

			currentAni->Update(dt);
			//Object::Update(dt);
		}
	}

	if(blood <1)
		Sound::getInstance()->play("Boss_Die", true, 0);
}
BoundingBox BrownBoss::GetBoundingBox()
{
	BoundingBox b;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width;
	b.h = this->height;
	b.x = this->x - this->width / 2;
	b.y = this->y - this->height / 2;
	return b;
}
void BrownBoss::MinusBlood()
{
	blood -= 1;
	Game_UI::getInstance()->MinusEnemyHealth();
}