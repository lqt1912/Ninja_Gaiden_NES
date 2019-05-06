#include "EnemyBrownKnife.h"



EnemyBrownKnife::EnemyBrownKnife()
{

	
	enemyAni = new Animation("Resources/Enemy1/enemy_brown_with_knife.png", 2, 1, 2,0.2);
}


EnemyBrownKnife::~EnemyBrownKnife()
{
}
void EnemyBrownKnife::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	enemyAni->FlipVertical(true);
	enemyAni->SetPosition(this->GetPosition());
	enemyAni->Draw(D3DXVECTOR3(x, y, 0), RECT(), D3DXVECTOR2(), transform);

}
void EnemyBrownKnife::Update(float dt)
{
	enemyAni->Update(dt);
	Object::Update(dt);
}

RECT EnemyBrownKnife::GetBound()
{
	RECT rect;
	rect.left = this->x - enemyAni->GetWidth() / 2;
	rect.right = rect.left + enemyAni->GetWidth();
	rect.top = this->y - enemyAni->GetHeight() / 2;
	rect.bottom = rect.top + enemyAni->GetHeight();

	return rect;
}