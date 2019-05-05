#include "Bird2.h"



Bird2::Bird2()
{
	birdAni = new Animation("Resources/Enemy1/bird-2.png", 2, 1, 2);
}


Bird2::~Bird2()
{
}
void Bird2::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	
	birdAni->SetPosition(this->GetPosition());
	birdAni->Draw(D3DXVECTOR3(x, y, 0), RECT(), D3DXVECTOR2(), transform);

}
void Bird2::Update(float dt)
{
	////DebugOut((wchar_t*)L"dt = %f \n", dt);
	//float dxx = this->getX() + 200;
	//float dyy = this->getY() - 100;
	//float length = sqrt(dxx*dxx + dyy * dyy);
	//dxx /= length;
	//dyy /= length;
	//dxx *= 20;
	//dyy *= 20;
	//this->SetVx(dxx);
	//this->SetVy(dyy);
	birdAni->Update(dt);
	Object::Update(dt);
}

RECT Bird2::GetBound()
{
	RECT rect;
	rect.left = this->x - birdAni->GetWidth() / 2;
	rect.right = rect.left + birdAni->GetWidth();
	rect.top = this->y - birdAni->GetHeight() / 2;
	rect.bottom = rect.top + birdAni->GetHeight();

	return rect;
}