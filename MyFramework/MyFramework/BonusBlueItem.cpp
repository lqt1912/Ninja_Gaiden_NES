#include "BonusBlueItem.h"



BonusBlueItem::BonusBlueItem()
{
	ani = new Animation("Resources/Items/bonus_blue.png",1,1,1);
	type = Object::BonusBlue;
}


BonusBlueItem::~BonusBlueItem()
{
}
