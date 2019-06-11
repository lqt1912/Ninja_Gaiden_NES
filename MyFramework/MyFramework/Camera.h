#pragma once

#include <d3dx9.h>
#include <d3d9.h>



class Camera
{
public:
	
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR3 pos);
	void SetPosition(float x);
	void setX(float x);
	float getX();
	float getY();
	int GetWidth();
	int GetHeight();

	D3DXVECTOR3 GetPosition();
	RECT GetBound();
	~Camera();
	void Update(D3DXVECTOR3);

	static Camera* getInstance();
	void  ConvertFromViewportToWorldport(D3DXVECTOR3 &position);

private:
	Camera(int width, int height);
	Camera();
	int             mWidth, mHeight;

	D3DXVECTOR3     mPosition;

	float vx, vy;
	static Camera* _instance; 

};

