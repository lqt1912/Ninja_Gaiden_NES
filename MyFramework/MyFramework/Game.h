#pragma once
#include <dinput.h>
#include "GameGlobal.h"

#define KEYBOARD_BUFFER_SIZE 1024;

class Game
{
public:
	Game(int fps = 60);
	~Game();
protected:
	PDIRECT3DSURFACE9 background, backbufer;
	int width, height;

	static int isDone;
	float fps;

	void InitLoop();
	void GameRender();
	void Update(float dt);
};

