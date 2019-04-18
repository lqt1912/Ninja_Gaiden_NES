
#include "Object.h"


Object::Object()
{
	Tag = None;
}
Object::~Object()
{

}

D3DXVECTOR3 Object::GetPosition()
{
	return D3DXVECTOR3(x, y, 0);
}

RECT Object::GetBound()
{
	RECT bound;

	bound.left = x - width / 2;
	bound.right = x + width / 2;
	bound.top = y - height / 2;
	bound.bottom = y + height / 2;

	return bound;
}

void Object::OnSetPosition(D3DXVECTOR3 pos)
{

}

void Object::Update(float dt)
{
	//velocity = pixel / s
	float dx = vx * dt;
	float dy = vy * dt;
	/*DebugOut((wchar_t*)L"\nvx = %f, dx = %f   dt= %F ", vx, dx ,dt);
	DebugOut((wchar_t*)L"\ndy = %f, vy = %f ", dy, vy);*/
	this->x += dx;
	this->y += dy;
//	this->SetPosition(2+x,2+y);
	
}

void Object::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR2(x, y));
}

void Object::SetPosition(D3DXVECTOR2 pos)
{
	SetPosition(D3DXVECTOR3(pos.x, pos.y, 0));
}

void Object::SetPosition(D3DXVECTOR3 pos)
{
	this->x = pos.x;
	this->y = pos.y;

	OnSetPosition(pos);
}

void Object::AddPosition(D3DXVECTOR3 pos)
{
	this->SetPosition(this->GetPosition() + pos);
}

void Object::AddPosition(D3DXVECTOR2 pos)
{
	AddPosition(D3DXVECTOR3(pos));
}

void Object::AddPosition(float x, float y)
{
	AddPosition(D3DXVECTOR3(x, y, 0));
}

void Object::SetWidth(int width)
{
	this->width = width;
}

int Object::GetWidth()
{
	return width;
}

void Object::SetHeight(int height)
{
	this->height = height;
}

int Object::GetHeight()
{
	return height;
}

float Object::GetVx()
{
	return vx;
}

void Object::SetVx(float vx)
{
	this->vx = vx;
}

void Object::AddVx(float vx)
{
	this->vx += vx;
}

float Object::GetVy()
{
	return vy;
}

void Object::SetVy(float vy)
{
	this->vy = vy;
}

void Object::AddVy(float vy)
{
	this->vy += vy;
}
