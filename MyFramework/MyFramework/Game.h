#pragma once

#include "GameGlobal.h"




class Game
{
public:
	Game(int fps = GAME_FPS);
	~Game();
	//Direct Input
	LPDIRECTINPUT di;										//direct input
	LPDIRECTINPUTDEVICE didv;								//direct device
	BYTE KeyState[256];										//keyboard state buffer
	DIDEVICEOBJECTDATA keyEvents[1024];		//buffer data
											//Direct input execute 
	void InitKeyboard();
	int IsKeyDown(int KeyCode);
	void Processkeyboard();

	//Key state 
	void KeyStates(BYTE*  state);
	void OnKeyUp(int KeyCode);
	void OnKeyDown(int KeyCode);
protected:
	PDIRECT3DSURFACE9 background, backbufer;
	int width, height;

	static int isDone;
	float fps;

	void InitLoop();
	void GameRender();
	void Update(float dt);
};

