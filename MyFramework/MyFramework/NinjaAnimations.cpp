#include "NinjaAnimations.h"


NinjaAnimations* NinjaAnimations::instance = NULL;

NinjaAnimations::NinjaAnimations()
{

}


NinjaAnimations::~NinjaAnimations()
{

}


void NinjaAnimations::AddAnimation(eNinjaStates state, const char* filePath, int totalFrame, int rows, int columns, float timePerFrame, D3DCOLOR colorKey)
{
	mAni[state] = new Animation(filePath, totalFrame, rows, columns, timePerFrame, colorKey);
}

NinjaAnimations* NinjaAnimations::GetInstance()
{
	if (instance == NULL)
		instance = new NinjaAnimations();
	return instance;
}

