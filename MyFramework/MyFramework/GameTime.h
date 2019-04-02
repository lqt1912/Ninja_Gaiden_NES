#pragma once
#include <Windows.h>



class GameTime
{
public:
	void startCounter();
	float getCounter();
	static GameTime* getInstance();


	~GameTime();

private:
	GameTime();
	LARGE_INTEGER startTime, endTime, delta, clockrate;
	static GameTime* instance;
};

