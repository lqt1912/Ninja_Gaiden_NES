#include "GameGlobal.h"

HINSTANCE GameGlobal::hInstance = NULL;
HWND GameGlobal::hWnd = NULL;
LPD3DXSPRITE GameGlobal::spriteHandler = NULL;
int GameGlobal::screenheight =SCREEN_HEIGHT;
int GameGlobal::screenwidth = SCREEN_WIDTH;
LPDIRECT3DDEVICE9 GameGlobal::d3ddv = nullptr;
bool GameGlobal::isRunning = true;
IDirect3DSurface9* GameGlobal::backSurface = nullptr;

bool isFrozenEnemies = false;
float frozenTime = FROZEN_TIME;
bool isWin = false;
GameGlobal::GameGlobal()
{
}


GameGlobal::~GameGlobal()
{
}

HINSTANCE GameGlobal::getHINSTANCE()
{
	return hInstance;
}

HWND GameGlobal::getHWND()
{
	return hWnd;
}

void GameGlobal::setHINSTANCE(HINSTANCE h)
{
	hInstance = h;
}

void GameGlobal::setHWND(HWND hwnd)
{
	hWnd = hwnd;
}

LPD3DXSPRITE GameGlobal::getSpriteHandler()
{
	return spriteHandler;
}

void GameGlobal::setSpriteHandler(LPD3DXSPRITE sprite)
{
	spriteHandler = sprite;
}

LPDIRECT3DDEVICE9 GameGlobal::getDevice()
{
	return d3ddv;
}

void GameGlobal::setDevice(LPDIRECT3DDEVICE9 device)
{
	d3ddv = device;
}

void GameGlobal::setWidth(int width)
{
	screenwidth = width;
}

int GameGlobal::getWidth()
{
	return screenwidth;
}

void GameGlobal::setHeight(int height)
{
	screenheight = height;
}

int GameGlobal::getHeight()
{
	return screenheight;
}
