#include "Dart.h"



Dart::Dart()
{
	this->vx = 50.0f;
	
	dartAni = new Animation("Resources/Ninja/dart.png",2,1,2,0.167f, D3DCOLOR_XRGB(0,0,0));
	dartAni->SetScale(D3DXVECTOR2(-5.0f,5.0f));
}


Dart::~Dart()
{
	delete dartAni;
}

void Dart::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	//dartAni->FlipVertical(true);
	dartAni->SetPosition(this->GetPosition());
	dartAni->Draw(D3DXVECTOR3(x, y, 0));
}
void Dart::Update(float dt)
{
	//DebugOut((wchar_t*)L"dt = %f \n", dt);

	dartAni->Update(dt);
	Object::Update(dt);
}

RECT Dart::GetBound()
{
	RECT rect;
	rect.left = this->x - dartAni->GetWidth() / 2;
	rect.right = rect.left + dartAni->GetWidth();
	rect.top = this->y - dartAni->GetHeight() / 2;
	rect.bottom = rect.top + dartAni->GetHeight();

	return rect;
}