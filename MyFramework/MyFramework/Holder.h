#pragma once
#include "Object.h"
class Holder :
	public Object
{

public:
	Holder();
	~Holder();
	virtual void setFlipVertical(bool isFlip);
	virtual int getType() { return 0; }
	virtual void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	virtual void Update(float);
	virtual	BoundingBox GetBoundingBox();
	virtual void setItemType(int i);
	virtual ItemTypes getItemType();
protected:
	ItemTypes itemType;
	Animation* currentAni;
};

