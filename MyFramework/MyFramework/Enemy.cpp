#include "Enemy.h"
#include "Ninja.h"
#include "Game_UI.h"

Enemy::Enemy()
{
	destroyedAni = new Animation("Resources/Enemy1/destroyed_state.png", 2, 1, 2, 0.2);
	isDead = false;
	Tag = Object::eEnemy;
	this->SetWidth(ENEMY_WIDTH);
	this->SetHeight(ENEMY_HEIGHT);
	s = 0;
	scored = 0;
	damage = DEFAULT_DAMAGE;
}


Enemy::~Enemy()
{
}

void Enemy::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	Camera::getInstance()->ConvertFromViewportToWorldport(position);
	currentAni->SetPosition(position);
	currentAni->Draw(position);


}
void Enemy::setFlipVertical(bool isFlip)
{
	this->currentAni->FlipVertical(isFlip);
	mIsFlipVertical = isFlip;
}

BoundingBox Enemy::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width / 2;
	b.y = this->y + this->height / 2 - 4;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width / 2;
	b.h = this->height /2;
	return b;
}

void Enemy::changeState()
{
	if (currentAni != destroyedAni)
	{
		Sound::getInstance()->play("enemy_destroy", false, 1);
		currentAni = destroyedAni;
	}

	isDead = true;
}
void Enemy::resetState()
{
	currentAni = moveAni;
	isDead = false;
}

void Enemy::Update(float dt)
{
	if (currentAni)
	{
		dx = vx * dt;
		dy = vy * dt;
		if (currentAni == destroyedAni)
		{
			if (s < 0.2f)
			{
				SetPosition(x - dx, y - dy);
				s += dt;
			}
			else
			{
				s = 0;
				isActive = false;
				Ninja::GetInstance()->AddScore(scored);
			}
			currentAni->Update(dt);
			if(isFrozenEnemies)
				SetPosition(x + dx, y + dy);
		}
		
		if (!isFrozenEnemies)
			currentAni->Update(dt);			
	}
}
bool Enemy::detectGroundA(vector<BoundingBox> grounds)
{
	return false;
}
void Enemy::OnCollisionWithGroundA(vector<BoundingBox> grounds)
{

}