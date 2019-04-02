#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>

class GameGlobal
{
 public:
	GameGlobal();
	~GameGlobal();
	static HINSTANCE getHINSTANCE();
	static HWND getHWND();

	static void setHINSTANCE(HINSTANCE h);
	static void setHWND(HWND hwnd);

	static LPD3DXSPRITE getSpriteHandler();
	static void setSpriteHandler(LPD3DXSPRITE sprite);

	static LPDIRECT3DDEVICE9 getDevice();
	static void setDevice(LPDIRECT3DDEVICE9 device);


	static void setWidth(int width);
	static int getWidth();

	static void setHeight(int height);
	static int getHeight();

	static LPDIRECT3DSURFACE9 backSurface;

	static bool isRunning;
private:

	static HINSTANCE hInstance;
	static HWND hWnd;
	static LPD3DXSPRITE spriteHandler;
	static int screenwidth, screenheight;
	static LPDIRECT3DDEVICE9 d3ddv;


};

