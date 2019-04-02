#include "Game.h"
#include "SceneManager.h"
#include "GameTime.h"
#include "SceneDemo.h"



Game::Game(int fps)
{
	this->fps = fps;
	SceneManager::GetInstance()->ReplaceScene(new SceneDemo());
	InitLoop();
}

Game::~Game()
{
}

void Game::InitLoop()
{
	MSG msg;

	float tickPerFrame = 1.0f / fps, fdelta = 0;

	while (GameGlobal::isRunning)
	{
		GameTime::getInstance()->startCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		fdelta += GameTime::getInstance()->getCounter();

		if (fdelta >= tickPerFrame)
		{
			Update((fdelta));
			fdelta = 0;
		}
		else
		{
			Sleep(tickPerFrame - fdelta);
			fdelta = tickPerFrame;
		}
	}
}

void Game::GameRender()
{
	auto device = GameGlobal::getDevice();
	auto scene = SceneManager::GetInstance()->GetCurrentScene();
	device->Clear(0, NULL, D3DCLEAR_TARGET, 0x4866ff, 0.0f, 0);

	if (device->BeginScene())
	{
		//bat dau ve
		GameGlobal::getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		//draw here
		scene->Draw();
		//ket thuc ve
		GameGlobal::getSpriteHandler()->End();


		device->EndScene();
	}

	device->Present(0, 0, 0, 0);
}

void Game::Update(float dt)
{
	SceneManager::GetInstance()->GetCurrentScene()->Update(dt);
	GameRender();
}
