#include "WindmillStarItem.h"



WindmillStarItem::WindmillStarItem()
{
	ani = new Animation("Resources/Items/windmill_star.png", 1, 1, 1);
	type = Object::WindmillStar;
}


WindmillStarItem::~WindmillStarItem()
{
}
