#include "SceneDemo.h"
#include "SceneManager.h"


SceneDemo::SceneDemo()
{
	LoadMap();
	LoadContent();


#pragma region LOAD_GRID

	grid = new Grid();
	grid->setColumn((int)map->getWidth() / 120);
	grid->setRow((int)map->getHeight() / 100);
	grid->setNumberOfCell((int)map->getWidth() / 120 * (int)map->getHeight() / 100);
	//định hình vector có số lượng cell là Numberofcell

	for (int i = 0; i < (grid->getColumn()*grid->getRow()); i++)
	{
		Cell* cell = new Cell();
		
		if (i < grid->getColumn())
		{
			cell->setPosition(D3DXVECTOR2(i * GameGlobal::getWidth() / 2 + GameGlobal::getWidth() / 4, 50));
		}
		else if (i >= grid->getColumn())
		{
			cell->setPosition(D3DXVECTOR2((i -17) * GameGlobal::getWidth() / 2 + GameGlobal::getWidth() / 4, 150));
		}
		grid->AddCell(cell);
		cell = NULL;
		delete cell;
		DebugOut((wchar_t*)L"\n Cell posi x = %f, y = %f ", grid->getCell(i)->getPosition().x, grid->getCell(i)->getPosition().y);
	}

	eLeopard = new LeoPard();
	eLeopard->SetPosition(240,161);
	lstEnemies.push_back(eLeopard);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(258,151);
	lstEnemies.push_back(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(308,151);
	lstEnemies.push_back(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(355, 151);
	lstEnemies.push_back(eBrownKnife);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(338,130);
	lstEnemies.push_back(eButterfly);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(435, 130);
	lstEnemies.push_back(eButterfly);


	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(455, 151);
	lstEnemies.push_back(eBrownKnife);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(578, 130);
	lstEnemies.push_back(eButterfly);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(642,114);
	lstEnemies.push_back(eButterfly);

	eBat = new Bat2();
	eBat->SetPosition(631, 149);
	lstEnemies.push_back(eBat);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(769,100);
	lstEnemies.push_back(eButterfly);


	eBird = new Bird2();
	eBird->setFlipVertical(true);
	eBird->SetPosition(563,62);
	lstEnemies.push_back(eBird);

	eBird = new Bird2();
	eBird->setFlipVertical(true);
	eBird->SetPosition(722,63);
	lstEnemies.push_back(eBird);

	ePinkWalk = new EnemyPinkWalk();
	ePinkWalk->setFlipVertical(true);
	ePinkWalk->SetPosition(820, 122);
	lstEnemies.push_back(ePinkWalk);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(898,66);
	lstEnemies.push_back(eButterfly);


	eLeopard = new LeoPard();
	eLeopard->setFlipVertical(true);
	eLeopard->SetPosition(913,98);
	lstEnemies.push_back(eLeopard);

	eLeopard = new LeoPard();
	eLeopard->SetPosition(951, 98);
	lstEnemies.push_back(eLeopard);

	eBird = new Bird2();
	eBird->SetPosition(1061,60);
	lstEnemies.push_back(eBird);


	eButterfly = new Butterfly();
	eButterfly->SetPosition(1155,130);
	lstEnemies.push_back(eButterfly);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(1186,66);
	lstEnemies.push_back(eButterfly);

	ePinkWalk = new EnemyPinkWalk();
	ePinkWalk->setFlipVertical(true);
	ePinkWalk->SetPosition(1230,90);
	lstEnemies.push_back(ePinkWalk);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(1300,90);
	lstEnemies.push_back(eBrownKnife);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(1330, 66);
	lstEnemies.push_back(eButterfly);

	eLeopard = new LeoPard();
	eLeopard->SetPosition(1281,161);
	lstEnemies.push_back(eLeopard);

	//còn 1 con enemi xanh lá chưa có ở đây 
	eGreenGun = new EnemyGreenGun();
	eGreenGun->setFlipVertical(true);
	eGreenGun->SetPosition(1376,152);
	lstEnemies.push_back(eGreenGun);


	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(1458, 90);
	lstEnemies.push_back(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(1491, 55);
	lstEnemies.push_back(eBrownKnife);

	eBird = new Bird2();
	eBird->SetPosition(1574,81);
	lstEnemies.push_back(eBird);


	eButterfly = new Butterfly();
	eButterfly->SetPosition(1666,130);
	lstEnemies.push_back(eButterfly);

	eBird = new Bird2();
	eBird->SetPosition(1730,63);
	lstEnemies.push_back(eBird);

	eBird = new Bird2();
	eBird->SetPosition(1876, 63);
	lstEnemies.push_back(eBird);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(1858, 130);
	lstEnemies.push_back(eButterfly);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(1890, 151);
	lstEnemies.push_back(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(1972, 151);
	lstEnemies.push_back(eBrownKnife);

	for (auto e : lstEnemies)
		e->SetPosition(e->GetPosition() + D3DXVECTOR3(-10, -7, 0));

	for (auto e : lstEnemies)
	{
		for (int i = 0; i < 34; i++)
		{
			if (isCollision(grid->getCell(i)->getBound(), e->GetBound()) == 1)
				grid->getCell(i)->addObject(e);
		}
	}

#pragma endregion

}


SceneDemo::~SceneDemo()
{
}

void SceneDemo::Update(float dt)
{
	this->ninja->HandleKeyboard(keys);
	this->ninja->Update(dt);

	/*but->Update(dt);
	leo->Update(dt);
	enemy1->Update(dt);
	enemy2->Update(dt);*/

#pragma region Camera_Execute

	grid->Update(dt, mCamera);
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
	//DebugOut((wchar_t*)L"x :%f , vx : %f \n", (float)ninja->getX(), (float)ninja->GetVx());
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
#pragma endregion
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

	backcolor =0x999;
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
	//but->Draw();
	//leo->Draw();
	//enemy1->Draw();
	//enemy2->Draw();
	D3DXVECTOR2 trans = D3DXVECTOR2((int)(GameGlobal::getWidth() / 2 - mCamera->GetPosition().x),
		(int)(GameGlobal::getHeight() / 2 - mCamera->GetPosition().y));
	grid->Render(trans,mCamera);
}
void SceneDemo::OnKeyDown(int KeyCode)
{
	keys[KeyCode] = true;
	ninja->OnKeyPressed(KeyCode);
	


}
void SceneDemo::OnKeyUp(int KeyCode)
{
	
	keys[KeyCode] = false;
	//ninja->allowJump = true;
	ninja->OnKeyUp(KeyCode);
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
