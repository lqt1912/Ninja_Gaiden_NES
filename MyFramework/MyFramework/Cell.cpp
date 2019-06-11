#include "Cell.h"
#include "Enemy.h"

void Cell::RespawnEnemies(Camera* camera)
{
	for (auto enemy : listObject)
	{
		if (isContain(camera->GetBound(), enemy->getInitPosition())==false && enemy->getActive() == false)
		{
			if (enemy->getObjectType() == Object::eEnemy)
			{
				auto e = (Enemy*)enemy;
				e->resetState();
				e->Respawn();
			}
		}
	}
}

unordered_set<Object*> Cell::getAliveEnemies()
{
	unordered_set<Object*> listActiveEnemies;
	for (auto enemy : listObject)
	{
		if (enemy->getActive() == 1 )
			listActiveEnemies.insert(enemy);
	}
	return listActiveEnemies;
}

Cell::Cell()
{
}


Cell::~Cell()
{
	for (auto enemy : listObject)
		enemy = nullptr;
	listObject.clear();

}





unordered_set<Object*> Cell::getlstObject()
{
	return this->listObject;
}

void Cell::Render(D3DXVECTOR2 trans)
{

	for (auto e : this->getAliveEnemies())
	{
		e->Draw(e->GetPosition(), RECT(), D3DXVECTOR2());
	}
}



void Cell::Update(float dt, Camera * camera)
{
	for (auto e : this->getAliveEnemies())
	{
		if (isCollision(camera->GetBound(), e->GetBound()) == 1 )
			e->Update(dt);
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

void Cell::addObject(Object * obj)
{
	//listObject.push_back(obj);
	listObject.insert(obj);
}


RECT Cell::getBound()
{
	RECT bound;

	bound.left = position.x - width / 2;

	bound.right = bound.left + width;
	bound.top = position.y + height / 2;
	bound.bottom = bound.top - height;
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

bool Cell::CheckContain(Object * obj)
{
	if (listObject.find(obj) != listObject.end())
		return true;
	return false;
}

int Cell::isCollision(RECT rect1, RECT rect2)
{
	if (rect1.left >= rect2.right || rect1.right <= rect2.left || rect1.top < rect2.bottom || rect1.bottom > rect2.top)
	{
		return false;
	}
	return true;
}

void Cell::removeObject(Object * obj)
{
	listObject.erase(listObject.find(obj));
}

int Cell::getNumberEnemies()
{
	return this->listObject.size();
}

bool Cell::isContain(RECT rect, D3DXVECTOR2 position)
{
	if (position.x >= rect.left && position.x <= rect.right && position.y >= rect.bottom && position.y <= rect.top)
		return true;
	return false;
}