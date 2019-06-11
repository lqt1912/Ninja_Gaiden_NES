#include "Butterfly.h"



Butterfly::Butterfly()
{
	currentAni = new Animation("Resources/Enemy1/butterfly.png", 2, 1, 2,0.1);
	type = BUTTERFLY_TYPE;
}


Butterfly::~Butterfly()
{
}
