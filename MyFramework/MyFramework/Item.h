#pragma once
#include "Object.h"
#include "Grid.h"
class Item : public Object
{
protected:
	float existTime;
	BoundingBox boundGround;
	ItemTypes type;
public:
	Animation* ani;
	virtual ItemTypes getTypeItem();
	virtual void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	virtual void Update(float);

	virtual void DetectGround(vector<Object*> listGround);
	virtual void DetectGroundA(vector<BoundingBox> listGround);

	BoundingBox GetBoundingBox();
	Item();
	~Item();
};