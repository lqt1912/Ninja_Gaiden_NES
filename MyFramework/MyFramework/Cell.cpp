#include "Cell.h"



Cell::Cell()
{
}


Cell::~Cell()
{
}



void Cell::Render(D3DXVECTOR2 trans)
{
	for (int i = 0; i < listObject.size(); i++)
		listObject[i]->Draw(D3DXVECTOR3(), RECT(), D3DXVECTOR2(), trans);
}

void Cell::Update(float dt, Camera* camera)
{
	for (int i = 0; i < listObject.size(); i++)
	{
		if(isCollision(camera->GetBound(), listObject[i]->GetBound())==1)
			listObject[i]->Update(dt);
	}
}

D3DXVECTOR2 Cell::getPosition()
{
	return this->position;
}

void Cell::setPosition(D3DXVECTOR2 vt)
{
	this->position = vt;
}

void Cell::addObject(Object* obj)
{
	listObject.push_back(obj);
}

RECT Cell::getBound()
{
	RECT bound;

	bound.left = position.x - width / 2;
	//DebugOut((wchar_t*)L"left= %d ", bound.left);
	bound.right = bound.left + width;
	bound.top = position.y - height / 2;
	//DebugOut((wchar_t*)L"top = %d ", bound.top);
	bound.bottom = bound.top + height;
	//DebugOut((wchar_t*)L"bot = %d ", bound.bottom);
	return bound;
}

int Cell::getWidth()
{
	return this->width;
}

int Cell::getHeight()
{
	return this->height;
}

int Cell::isCollision(RECT r1, RECT r2)
{
	RECT dest;
	return IntersectRect(&dest, &r1, &r2);
}

