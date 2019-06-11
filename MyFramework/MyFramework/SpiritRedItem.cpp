#include "SpiritRedItem.h"



SpiritRedItem::SpiritRedItem()
{
	ani = new Animation("Resources/Items/spirit_strength_red.png", 1, 1, 1);
	type = Object::SpiritRed;
}


SpiritRedItem::~SpiritRedItem()
{
}
