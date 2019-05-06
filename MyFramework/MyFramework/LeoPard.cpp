#include "LeoPard.h"



LeoPard::LeoPard()
{
	
	leopardAni = new Animation("Resources/Enemy1/leopard.png",2,1,2,0.2);
}


LeoPard::~LeoPard()
{
}
void LeoPard::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	//leopardAniAni->FlipVertical(true);
	leopardAni->SetPosition(this->GetPosition());
	leopardAni->Draw(D3DXVECTOR3(x, y, 0), RECT(),D3DXVECTOR2(),transform);

}
void LeoPard::Update(float dt)
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
	leopardAni->Update(dt);
	Object::Update(dt);
}

RECT LeoPard::GetBound()
{
	RECT rect;
	rect.left = this->x - leopardAni->GetWidth() / 2;
	rect.right = rect.left + leopardAni->GetWidth();
	rect.top = this->y - leopardAni->GetHeight() / 2;
	rect.bottom = rect.top + leopardAni->GetHeight();

	return rect;
}