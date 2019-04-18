#pragma once
#include "GameGlobal.h"
class Object
{
public:
	Object();
	~Object();

	enum ObjectTypes
	{
		Ninja,
		Enemy,
		None,
	};

	ObjectTypes Tag; //Tag de nhan dien loai object

	virtual RECT GetBound();

	virtual void SetPosition(float x, float y);

	virtual void SetPosition(D3DXVECTOR2 pos);

	virtual void SetPosition(D3DXVECTOR3 pos);

	virtual void AddPosition(D3DXVECTOR3 pos);

	virtual void AddPosition(D3DXVECTOR2 pos);

	virtual void AddPosition(float x, float y);

	virtual void SetWidth(int width);

	virtual int GetWidth();

	virtual void SetHeight(int height);

	virtual int GetHeight();

	virtual float GetVx();

	virtual void SetVx(float vx);

	virtual void AddVx(float vx);

	virtual float GetVy();

	virtual void SetVy(float vy);

	virtual void AddVy(float vy);

	virtual D3DXVECTOR3 GetPosition();

	virtual void Update(float dt);

	virtual int getX() {
		return 0;
	}

	virtual int getY()
	{
		return 0;
	}
protected:

	//duoc goi khi set position cua object, dung cho ke thua
	virtual void OnSetPosition(D3DXVECTOR3 pos);

	//vi tri tam position x va y
	float x, y;

	//phan toc vx, vy
	float vx, vy;

	//size cua entity
	float width, height;

};

