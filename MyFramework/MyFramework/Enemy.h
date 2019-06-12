#pragma once
#include "Object.h"

class Enemy :
	public Object
{
public:
	Enemy();
	~Enemy();
	virtual void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	virtual void Update(float);
	virtual void changeState();
	virtual void resetState();
	virtual void setFlipVertical(bool isFlip);
	virtual int getType() { return 0; }
	BoundingBox curGround;
	virtual bool detectGroundA(vector<BoundingBox> grounds);
	virtual void OnCollisionWithGroundA(vector<BoundingBox> grounds);
	virtual	BoundingBox GetBoundingBox();
	bool isDead;
	int scored;

protected:
	Animation* currentAni, * moveAni, * destroyedAni;
	float s;
	BoundingBox boundGround;
};

