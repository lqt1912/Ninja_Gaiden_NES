#include "EnemyGreenGun.h"



EnemyGreenGun::EnemyGreenGun()
{

	enemyAni = new Animation("Resources/Enemy1/green_enemy_with_gun_walk.png", 2, 1, 2);
}


EnemyGreenGun::~EnemyGreenGun()
{
}
void EnemyGreenGun::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	//EnemyGreenGunAniAni->FlipVertical(true);
	enemyAni->SetPosition(this->GetPosition());
	enemyAni->Draw(D3DXVECTOR3(x, y, 0), RECT(), D3DXVECTOR2(), transform);

}
void EnemyGreenGun::Update(float dt)
{
	//DebugOut((wchar_t*)L"dt = %f \n", dt);
	/*float dxx = this->getX() -50;
	float dyy = this->getY() - 100;
	float length = sqrt(dxx*dxx + dyy * dyy);
	dxx /= length;
	dyy /= length;
	dxx *= 20;
	dyy *= 20;
	this->SetVx(dxx);*/
	//this->SetVy(dyy);
	enemyAni->Update(dt);
	Object::Update(dt);
}

RECT EnemyGreenGun::GetBound()
{
	RECT rect;
	rect.left = this->x - enemyAni->GetWidth() / 2;
	rect.right = rect.left + enemyAni->GetWidth();
	rect.top = this->y - enemyAni->GetHeight() / 2;
	rect.bottom = rect.top + enemyAni->GetHeight();

	return rect;
}