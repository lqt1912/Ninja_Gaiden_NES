#include "StarItem.h"



StarItem::StarItem()
{
	ani = new Animation("Resources/Items/star.png", 1, 1, 1);
	type = Object::Star;
}


StarItem::~StarItem()
{
}
