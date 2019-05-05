#include "Bat2.h"



Bat2::Bat2()
{
	batAni = new Animation("Resources/Enemy1/bat-2.png", 2, 1, 2);
}


Bat2::~Bat2()
{
}
void Bat2::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	batAni->SetPosition(this->GetPosition());
	batAni->Draw(D3DXVECTOR3(x, y, 0), RECT(), D3DXVECTOR2(), transform);

}
void Bat2::Update(float dt)
{

	batAni->Update(dt);
	Object::Update(dt);
}

RECT Bat2::GetBound()
{
	RECT rect;
	rect.left = this->x - batAni->GetWidth() / 2;
	rect.right = rect.left + batAni->GetWidth();
	rect.top = this->y - batAni->GetHeight() / 2;
	rect.bottom = rect.top + batAni->GetHeight();

	return rect;
}