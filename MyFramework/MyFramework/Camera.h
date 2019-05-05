#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include "Ninja.h"
//#include "TiledMap.h"   include ở đây chi ?

class Camera
{
public:
	Camera(int width, int height);

	//center of camera
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);

	void SetPosition(float x);
	void setX(int x);
	float getX();
	float getY();
	int GetWidth();
	int GetHeight();
	D3DXVECTOR3 GetPosition();
	RECT GetBound();

	~Camera();
	void Update(D3DXVECTOR3);

private:
	int             mWidth, mHeight;

	D3DXVECTOR3     mPosition;

	float vx, vy;

};

