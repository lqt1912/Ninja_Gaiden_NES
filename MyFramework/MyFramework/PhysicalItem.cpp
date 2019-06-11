#include "PhysicalItem.h"



PhysicalItem::PhysicalItem()
{
	ani = new Animation("Resources/Items/physical_strength.png", 1, 1, 1);
	type = Object::Physical;
}


PhysicalItem::~PhysicalItem()
{
}
