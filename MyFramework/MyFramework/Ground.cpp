#include "Ground.h"



void Ground::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	Camera::getInstance()->ConvertFromViewportToWorldport(position);
	mGround->SetPosition(position);
	mGround->Draw(position);
	Tag = Object::eGround;
}

Ground::Ground(const char* filePath)
{
	mGround = new Animation(filePath, 1, 1, 1);
	this->SetWidth(mGround->GetWidth());
	this->SetHeight(mGround->GetHeight());
}




Ground::~Ground()
{
}
