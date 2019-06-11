#include "Bird.h"



Bird::Bird()
{
	currentAni = new Animation("Resources/Enemy1/bird.png", 2, 1, 2, 0.1);
	type = BIRD_TYPE;
}


Bird::~Bird()
{
}
