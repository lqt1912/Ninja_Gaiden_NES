#include "Game.h"
#include "SceneManager.h"
#include "GameTime.h"
#include "SceneDemo.h"



Game::Game(int fps)
{
	this->fps = fps;
	SceneManager::GetInstance()->ReplaceScene(new SceneDemo());
	InitKeyboard();
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
			Processkeyboard();
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
	
	device->Clear(0, NULL, D3DCLEAR_TARGET, scene->GetBackColor(), 0.0f, 0);
	(device->BeginScene());
	
		
		//bat dau ve
		GameGlobal::getSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
		//draw here
		scene->Draw();
		//ket thuc ve
		GameGlobal::getSpriteHandler()->End();

		device->EndScene();
	
	device->Present(0, 0, 0, 0);
}

void Game::Update(float dt)
{
	SceneManager::GetInstance()->GetCurrentScene()->Update(dt);
	GameRender();
}
void Game::InitKeyboard()
{
	HRESULT hr = DirectInput8Create
	(
		(HINSTANCE)GetWindowLong(GameGlobal::getHWND(), GWLP_HINSTANCE ),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8, (VOID**)&di, NULL
	);

	if (hr != DI_OK)
	{
		//	DebugOut((wchar_t*)L"[ERROR] DirectInput8Create failed!\n");
		return;
	}

	hr = di->CreateDevice(GUID_SysKeyboard, &didv, NULL);

	// TO-DO: put in exception handling
	if (hr != DI_OK)
	{
		//DebugOut((wchar_t*)L"[ERROR] CreateDevice failed!\n");
		return;
	}

	// Set the data format to "keyboard format" - a predefined data format 
	//
	// A data format specifies which controls on a device we
	// are interested in, and how they should be reported.
	//
	// This tells DirectInput that we will be passing an array
	// of 256 bytes to IDirectInputDevice::GetDeviceState.

	hr = didv->SetDataFormat(&c_dfDIKeyboard);

	hr = didv->SetCooperativeLevel(GameGlobal::getHWND(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);


	// IMPORTANT STEP TO USE BUFFERED DEVICE DATA!
	//
	// DirectInput uses unbuffered I/O (buffer size = 0) by default.
	// If you want to read buffered data, you need to set a nonzero
	// buffer size.
	//
	// Set the buffer size to DINPUT_BUFFERSIZE (defined above) elements.
	//
	// The buffer size is a DWORD property associated with the device.
	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	hr = didv->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	hr = didv->Acquire();
	if (hr != DI_OK)
	{
		//DebugOut((wchar_t*)L"[ERROR] DINPUT8::Acquire failed!\n");
		return;
	}
	//DebugOut((wchar_t*)L"[INFO] Keyboard has been initialized successfully\n");

}


int Game::IsKeyDown(int KeyCode)
{
	return (this->KeyState[KeyCode] & 0x80) > 0;
}

void Game::Processkeyboard()
{
	HRESULT hr;

	// Collect all key states first
	hr = didv->GetDeviceState(sizeof(this->KeyState), this->KeyState);
	if (FAILED(hr))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			HRESULT h = didv->Acquire();
			/*if (h == DI_OK)
			{
			DebugOut((wchar_t*)L"[INFO] Keyboard re-acquired!\n");
			}
			else return;*/
		}
		else
		{
			//DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
			return;
		}
	}

	this->KeyStates((BYTE*)&this->KeyState);

	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	hr = didv->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
	if (FAILED(hr))
	{
		//DebugOut(L"[ERROR] DINPUT::GetDeviceData failed. Error: %d\n", hr);
		return;
	}

	// Scan through all buffered events, check if the key is pressed or released
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = keyEvents[i].dwOfs;

		int	KeyState1 = keyEvents[i].dwData;
		if ((KeyState1 & 0x80) > 0)
			OnKeyDown(KeyCode);
		else
			OnKeyUp(KeyCode);
	}
}

void Game::KeyStates(BYTE*  state)
{
	
}
void Game::OnKeyUp(int KeyCode)
{
	KeyState[KeyCode] = false;
	SceneManager::GetInstance()->GetCurrentScene()->OnKeyUp(KeyCode);
}
void Game::OnKeyDown(int KeyCode)
{
	//KeyState[KeyCode] = true;
	SceneManager::GetInstance()->GetCurrentScene()->OnKeyDown(KeyCode);
}