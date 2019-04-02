#include <d3d9.h>
#include <iostream>
#include <sstream>
#include "GameGlobal.h"
#include "GameTime.h"
#include "Game.h"

#include <windowsx.h>

using namespace std;

#define WIN_NAME L"Ninja Gaiden NES"
#define WIN_TITLE L"Ninja Gaiden NES"
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define FPS 60
#define KEYBOARD_BUFFER_SIZE 1024;

LPDIRECT3D9				mDirect3D9;
LPD3DXSPRITE			spriteHandler;
PDIRECT3D9				d3d;
LPDIRECT3DDEVICE9		d3ddv;
HINSTANCE				hInstance;
int						nCmdShow;

int InitWindow(int nCmdShow);
int InitDevice();
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE Instance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iCmdShow)
{
	hInstance = Instance;
	InitWindow(iCmdShow);
	return 0;
}

int InitWindow(int nCmdShow)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WIN_NAME;
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);

	HWND hWnd = CreateWindow(
		WIN_NAME,
		WIN_NAME,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		GameGlobal::getWidth(),
		GameGlobal::getHeight(),
		NULL,
		NULL,
		hInstance,
		NULL);

	GameGlobal::setHINSTANCE(hInstance);
	GameGlobal::setHWND(hWnd);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	if (InitDevice())
		Game* game = new Game(60);
	return 0;

}

int InitDevice()
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	HRESULT result = d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		GameGlobal::getHWND(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv);
	GameGlobal::setDevice(d3ddv);

	D3DXCreateSprite(GameGlobal::getDevice(), &spriteHandler);
	GameGlobal::setSpriteHandler(spriteHandler);

	return 1;
}

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		GameGlobal::isRunning = false;
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:

		break;

	case WM_KEYDOWN:

		break;

	case WM_KEYUP:
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
	
}


