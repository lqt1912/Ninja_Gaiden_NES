#pragma once
#include "Ninja.h"
class Grid;

class Weapon: public Object
{
protected:
	Animation* ani;
public:
	bool flag = false;
	bool isOnScreen;
	Object::WeaponTypes type;
	int limitSpirit;
	bool isBack;
	Weapon();
	~Weapon();
	virtual int getType();
	virtual void Update(float dt);
	virtual void Update(float dt,vector<Object*> handleObject,Grid *grid);
	virtual void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	
};

