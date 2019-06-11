#include "FireWheelItem.h"



FireWheelItem::FireWheelItem()
{
	ani = new Animation("Resources/Items/fire_wheel.png", 1, 1, 1);
	type = Object::FireWheel;
}


FireWheelItem::~FireWheelItem()
{
}
