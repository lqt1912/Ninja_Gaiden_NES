#include "Weapon.h"
#include "BonusBlueItem.h"
#include "BonusRedItem.h"
#include "FireWheelItem.h"
#include "PhysicalItem.h"
#include "SpiritBlueItem.h"
#include "SpiritRedItem.h"
#include "StarItem.h"
#include "WindmillStarItem.h"
#include "TimeFreezeItem.h"
#include "Game_UI.h"
#include "BrownBoss.h"

Weapon::Weapon()
{
	this->Tag = Object::eWeapon;
	this->type = Object::NoneWeapon;
	setActive(true);
}


Weapon::~Weapon()
{
	if (ani)
		delete ani;
}

void Weapon::Update(float dt)
{

}

void Weapon::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	Camera::getInstance()->ConvertFromViewportToWorldport(position);
	ani->SetPosition(position);
	ani->Draw(position);
}
void Weapon::Update(float dt, vector<Object*> handleObject, Grid* grid)
{
	/*this->UpdateDistance(dt);
	this->posX += dx;
	this->posY += dy;*/

	//ani->isReverse = this->isReverse;
	if (ani)
		ani->Update(dt);
	Object* obj = new Object();
	for (auto obj : handleObject)
	{
		if (Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), obj->GetBoundingBox()))
		{
			if (obj->getObjectType() == Object::eEnemy)
			{
				
				if (obj->type == BROWN_BOSS_TYPE)
				{
					auto b = (BrownBoss*)obj;
					flag = true;
					if (b->blood < 1)
					{
						b->changeState();
						//Sound::getInstance()->play("Boss_Die", false, 10);
					}
				}
				else if (obj->type != BROWN_BOSS_TYPE)
				{
					auto e = (Enemy*)obj;
					e->changeState();
					
				}
			}

			if (obj->getObjectType() == Object::eHolder)
			{

				auto h = (Holder*)obj;
				h->setActive(false);
				switch (h->getItemType())
				{

				case SpiritBlue:
					obj = new SpiritBlueItem();
					break;
				case SpiritRed:
					obj = new SpiritRedItem();
					break;
				case FireWheel:
					obj = new FireWheelItem();
					break;
				case Star:
					obj = new StarItem();
					break;
				case WindmillStar:
					obj = new WindmillStarItem();
					break;
				case Physical:
					obj = new PhysicalItem();
					break;
				case BonusBlue:
					obj = new BonusBlueItem();
					break;
				case BonusRed:
					obj = new BonusRedItem();
					break;
				case TimeFreeze:
					obj = new TimeFreezeItem();
					break;
				default:
					return;
				}
				obj->SetPosition(h->GetPosition());
				obj->setActive(true);

				grid->addObject(obj);

				// add item into cell

				for (auto e : grid->getBaseEnemiesList())
				{
					if (e->getObjectType() == Object::eItem)

						for (int i = 0; i < grid->getRow(); i++)
						{
							for (int j = 0; j < grid->getColumn(); j++)
							{
								if (Collision::GetInstance()->isCollision(grid->getCellA(i, j)->getBound(), e->GetBound()) == true && e->getVisible() == 1)
								{
									grid->getCellA(i, j)->addObject(e);
									e->setVisible(false);
								}
							}
						}
				}
				obj = NULL;
				delete obj;
			}
			if (type == Object::eWindStar)
				isBack = true;
			else
				this->isActive = false;
		}
			
	}

}
int Weapon::getType()
{
	return type;
}
