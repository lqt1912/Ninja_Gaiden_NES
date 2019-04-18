#include "SceneDemo.h"
#include "SceneManager.h"


SceneDemo::SceneDemo()
{
	LoadMap();
	LoadContent();

}


SceneDemo::~SceneDemo()
{
}

void SceneDemo::Update(float dt)
{
	this->ninja->HandleKeyboard(keys);
	this->ninja->Update(dt);
	
	int leftBound = GameGlobal::getWidth() / 2;  //biên trái
	int rightBound = map->getWidth() - leftBound;  //biên phái

	float ninX = ninja->getX();
	float ninY = ninja->getY();

	//khi ninja ở giữa 2 biên => Camera di chuyển, ninja đứng yên 
	if (ninja->getX() >= leftBound-4 && ninja->getX() <= rightBound )
	{
		if (ninja->GetVx() > 0)
		{
			mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(ninja->GetVx()*dt, 0, 0)); //Khóa camera biên trái 
			ninja->setX(GameGlobal::getWidth() / 2);
		}
		if (ninja->GetVx() < 0)
		{
			mCamera->SetPosition(mCamera->GetPosition() + D3DXVECTOR3(ninja->GetVx()*dt, 0, 0));
			ninja->setX(GameGlobal::getWidth() / 2);
		}	
	} 
	DebugOut((wchar_t*)L"x :%f , vx : %f \n", (float)ninja->getX(), (float)ninja->GetVx());
	//Xử lý ở biên phải 
	if (mCamera->GetPosition().x>rightBound )
	{

			//khóa camera lại ở biên phải 

			mCamera->SetPosition(rightBound, mCamera->GetPosition().y);
			
			//di chuyển ninja 
			ninja->setX(ninX + ninja->GetVx()*dt);
			
			if (ninja->GetVx() < 0)
			{
				
				ninja->setX(ninX + ninja->GetVx()*dt);
				
			}
	}
	
	//xử lý ở biên trái 
	if (mCamera->GetPosition().x < leftBound-4)
	{
		mCamera->SetPosition(leftBound, mCamera->GetPosition().y);
		ninja->setX(ninX + ninja->GetVx()*dt);
	}

	if (ninja->getX() < 0)
	{
		ninja->setX(0);
	}
	
	if (ninja->getX() >= GameGlobal::getWidth())
	{
		ninja->setX(GameGlobal::getWidth());
	}
}

void SceneDemo::LoadContent()
{
	mTimeCounter = 0x0;

	backcolor =0x0;
	ninja = new Ninja();
	ninja->SetPosition(50,150);

	mCamera = new Camera(GameGlobal::getWidth(), GameGlobal::getHeight());

	//vị trí camera là ở trung tâm màn hình 
	mCamera->SetPosition(GameGlobal::getWidth() / 2, map->getHeight()-GameGlobal::getHeight() / 2);
	
	map->SetCamera(mCamera);
}

void SceneDemo::Draw()
{
	map->Render();
	ninja->Draw();	
}
void SceneDemo::OnKeyDown(int KeyCode)
{
	keys[KeyCode] = true;
	ninja->OnKeyPressed(KeyCode);
	


}
void SceneDemo::OnKeyUp(int KeyCode)
{
	
	keys[KeyCode] = false;
	ninja->allowJump = true;
}

void SceneDemo::LoadMap()
{
	map = new TiledMap("Resources/Map/3_1.txt");
	//map->LoadMatrix("Resources/Map/3_1.txt");
	map->LoadTileSet("Resources/Map/3_1.png");
	
}

Camera * SceneDemo::getCamera()
{
	return mCamera;
}
