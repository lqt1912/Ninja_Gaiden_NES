
#include "Object.h"
#include "Ninja.h"
Camera* Object::camera = NULL;

Object::Object()
{
	Tag = None;
	vy = 0;
}
Object::~Object()
{

}

void Object::moveTo(Object* des)
{
	float dxx = this->getX() - des->getX();
	float dyy = this->getY() - des->getY();
	float length = sqrt((dxx * dxx) + (dyy * dyy));
	dxx /= length;
	dyy /= length;
	dxx *= 40; // van toc di chuyen den
	dyy *= 40;
	this->SetVx(-dxx);
	this->SetVy(-dyy);
}
void Object::moveTo(float x, float y)
{
	float dxx = this->getX() - x;
	float dyy = this->getY() - y;
	float length = sqrt((dxx * dxx) + (dyy * dyy));

	this->SetVx(-dxx);
	this->SetVy(-dyy);
}
void Object::moveTo(float x, float y, float v)
{
	float dxx = this->getX() - x;
	float dyy = this->getY() - y;
	float length = sqrt((dxx * dxx) + (dyy * dyy));
	dxx /= length;
	dyy /= length;
	dxx *= v; // van toc di chuyen den des
	dyy *= v / 2;
	this->SetVx(-dxx);
	this->SetVy(-dyy);
}
void Object::moveTo(Object * des, int v)
{
	float dxx = this->getX() - des->getX();
	float dyy = this->getY() - des->getY();
	float length = sqrt((dxx * dxx) + (dyy * dyy));
	dxx /= length;
	dyy /= length;
	dxx *= v; // van toc di chuyen den des
	dyy *= v;
	this->SetVx(-dxx);
	this->SetVy(-dyy);

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
	bound.top = (int)(y + height / 2);
	bound.bottom = (int)(y - height / 2);
	//DebugOut((wchar_t*)L"bound %d %d \n \n ", bound.top, bound.bottom);
	return bound;
}

void Object::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

}



void Object::OnSetPosition(D3DXVECTOR3 pos)
{

}

void Object::Update(float dt)
{
	//velocity = pixel / s
	dx = vx * dt;
	dy = vy * dt;
	/*DebugOut((wchar_t*)L"\nvx = %f, dx = %f   dt= %F ", vx, dx ,dt);
	DebugOut((wchar_t*)L"\ndy = %f, vy = %f ", dy, vy);*/

	this->x += dx;
	this->y += dy;

	//	this->SetPosition(2+x,2+y);

}

void Object::Reset(D3DXVECTOR2 pos)
{
	
	SetPosition(pos);
	setFlipVertical(getInitFlip());
	if (Ninja::GetInstance()->GetPosition().x - this->GetPosition().x >= 0 && this->getType()==4)
	{
		vx = 20;
	}
	else if(Ninja::GetInstance()->GetPosition().x - this->GetPosition().x < 0 && this->getType() == 4)
	{
		vx = -20;

	}
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
void Object::OnCollision(Object * impactor, ResultCollision data, Object::SideCollisions side)
{

}

void Object::setInitPosition(float a, float b)
{
	this->initPositionX = a;
	this->initPositionY = b;
}

D3DXVECTOR2 Object::getInitPosition()
{
	return D3DXVECTOR2(initPositionX, initPositionY);
}
void Object::MoveBetween(float fA, float lA)
{
	if (this->x <= fA || this->x >= lA)
	{
		vx = -vx;
	}
}
int Object::getActive()
{
	return this->isActive;
}
int Object::getDead()
{
	return this->isDead;
}
void Object::setActive(bool b)
{
	this->isActive = b;
}
void Object::setDead(bool b)
{
	this->isDead = b;
}
void Object::Respawn()
{
	if(!isActive)
		isActive = true;
	isDead = false;
	this->Reset(this->getInitPosition());
}
float Object::getX() {
	return x;
}

float Object::getY()
{
	return y;
}

Object::ObjectTypes Object::getObjectType()
{
	return Tag;
}
void Object::setFlipVertical(bool isFlip)
{
	this->isFlip = isFlip;
	this->FlipVertical(isFlip);
}
void Object::setVisible(bool vs)
{
	isVisible = vs;
}
int Object::getVisible()
{
	return this->isVisible;
}
BoundingBox Object::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width/2;
	b.y = this->y + this->height/2;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width;
	b.h = this->height;
	return b;
}
bool Object::getFlip()
{
	return this->isFlip;
}
int Object::getType()
{
	return -1;
}
void Object::setInitFlip(bool isFlip)
{
	this->initFlip = isFlip;
}
bool Object::getInitFlip()
{
	return this->initFlip;
}