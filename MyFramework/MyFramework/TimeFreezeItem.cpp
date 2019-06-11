#include "TimeFreezeItem.h"



TimeFreezeItem::TimeFreezeItem()
{
	ani = new Animation("Resources/Items/time_freeze.png", 1, 1, 1);
	type = Object::TimeFreeze;
}


TimeFreezeItem::~TimeFreezeItem()
{
}
