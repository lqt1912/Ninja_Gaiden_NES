#include "BonusRedItem.h"



BonusRedItem::BonusRedItem()
{
	ani = new Animation("Resources/Items/bonus_red.png", 1, 1, 1);
	type = Object::BonusRed;
}


BonusRedItem::~BonusRedItem()
{
}
