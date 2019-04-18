#include "Camera.h"
#include "Debug.h"

Camera::Camera(int width, int height)
{
	mWidth = width;
	mHeight = height;
	mPosition = D3DXVECTOR3(0, 0, 0);
}


Camera::~Camera()
{

}

void Camera::Update(D3DXVECTOR3 dt)
{
	

}



void Camera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}

void Camera::SetPosition(D3DXVECTOR3 pos)
{
	mPosition = pos;
}

D3DXVECTOR3 Camera::GetPosition()
{
	return mPosition;
}

RECT Camera::GetBound()
{
	RECT bound;

	bound.left = mPosition.x - mWidth / 2;
	//DebugOut((wchar_t*)L"left= %d ", bound.left);
	bound.right = bound.left + mWidth;
	bound.top = mPosition.y - mHeight / 2;
	//DebugOut((wchar_t*)L"top = %d ", bound.top);
	bound.bottom = bound.top + mHeight;
	//DebugOut((wchar_t*)L"bot = %d ", bound.bottom);

	return bound;
}

void Camera::SetPosition(float x)
{
	this->SetPosition(this->GetPosition() + D3DXVECTOR3(x, 0, 0));
}

void Camera::setX(int x)
{
	this->mPosition.x = x;
}

float Camera::getX()
{
	return this->GetPosition().x;
}

float Camera::getY()
{
	return this->GetPosition().y;
}

int Camera::GetWidth()
{
	return mWidth;
}

int Camera::GetHeight()
{
	return mHeight;
}