#pragma once
#include "Object.h"
class Bird2 : public Object
{
	
public:
	Bird2();
	~Bird2();	
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	void Update(float);
	RECT GetBound();
	void setFlipVertical(bool isFlip)
	{
		this->birdAni->FlipVertical(isFlip);
	}

	Animation *birdAni;
};

