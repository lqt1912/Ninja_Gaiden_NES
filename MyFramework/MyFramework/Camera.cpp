#include "Camera.h"
#include "Debug.h"

#include "GameGlobal.h"]
Camera* Camera::_instance = NULL;
Camera::Camera(int width, int height)

{
	mWidth = width;
	mHeight = height;
	mPosition = D3DXVECTOR3(0, 208, 0);
}
Camera* Camera::getInstance()
{
	if (!_instance)
		_instance = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT);
	return _instance;
}
Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::Update(D3DXVECTOR3 dt)
{
	

}

void Camera::ConvertFromViewportToWorldport(D3DXVECTOR3& position)
{
	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._22 = -1;
	mt._41 = -this->GetPosition().x;
	mt._42 = this->GetPosition().y;
	D3DXVECTOR4 vp_pos;

	D3DXVec3Transform(&vp_pos, &position, &mt);
	position = D3DXVECTOR3(vp_pos.x, vp_pos.y, 0);

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

	bound.left = mPosition.x ;
	bound.right = bound.left + mWidth;
	bound.top = mPosition.y ;
	bound.bottom = bound.top - mHeight;

	return bound;
}

void Camera::SetPosition(float x)
{
	this->SetPosition(this->GetPosition() + D3DXVECTOR3(x, 0, 0));
}

void Camera::setX(float x)
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