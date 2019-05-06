#include "Butterfly.h"



Butterfly::Butterfly()
{
	butterflyAni = new Animation("Resources/Enemy1/butterfly.png", 2, 1, 2,0.2);
}


Butterfly::~Butterfly()
{
}
void Butterfly::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	//ButterflyAni->FlipVertical(true);
	butterflyAni->SetPosition(this->GetPosition());
	butterflyAni->Draw(D3DXVECTOR3(x, y, 0), RECT(),D3DXVECTOR2(), transform);
 
}
void Butterfly::Update(float dt)
{
	//DebugOut((wchar_t*)L"dt = %f \n", dt);

	butterflyAni->Update(dt);
	Object::Update(dt);
}

RECT Butterfly::GetBound()
{
	RECT rect;
	rect.left = this->x - butterflyAni->GetWidth() / 2;
	rect.right = rect.left + butterflyAni->GetWidth();
	rect.top = this->y - butterflyAni->GetHeight() / 2;
	rect.bottom = rect.top + butterflyAni->GetHeight();

	return rect;
}