#include "GameTime.h"

GameTime* GameTime::instance = NULL;

GameTime::GameTime()
{
}


void GameTime::startCounter()
{
	if (!QueryPerformanceFrequency(&clockrate))
		return;
	QueryPerformanceCounter(&startTime);
}

float GameTime::getCounter()
{
	QueryPerformanceCounter(&endTime);
	delta.QuadPart = endTime.QuadPart - startTime.QuadPart;
	return ((float)delta.QuadPart/clockrate.QuadPart);
}

GameTime * GameTime::getInstance()
{
	if (!instance)
		instance = new GameTime();
	return instance;
}

GameTime::~GameTime()
{
}
