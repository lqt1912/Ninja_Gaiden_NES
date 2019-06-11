#include "SpiritBlueItem.h"



SpiritBlueItem::SpiritBlueItem()
{
	ani = new Animation("Resources/Items/spirit_strength_blue.png", 1, 1, 1);
	type = Object::SpiritBlue;
}


SpiritBlueItem::~SpiritBlueItem()
{
}
