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

	//cell - 4 
	eBird = new Bird2();
	eBird->setFlipVertical(true);
	eBird->SetPosition(grid->getCell(4)->getPosition());
	grid->getCell(4)->addObject(eBird);

	//cell - 5
	eBird = new Bird2();
	eBird->setFlipVertical(true);
	eBird->SetPosition(grid->getCell(5)->getPosition()+ D3DXVECTOR2(GameGlobal::getWidth()/8,0));
	grid->getCell(5)->addObject(eBird);

	//cell - 6 
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(6)->getPosition() + D3DXVECTOR2(-GameGlobal::getWidth() / 8-20, 50));
	grid->getCell(6)->addObject(eButterfly);

	//cell - 7
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(7)->getPosition() - D3DXVECTOR2(GameGlobal::getWidth() / 8+10, -10));
	grid->getCell(7)->addObject(eButterfly);

	eLeopard = new LeoPard();
	eLeopard->SetPosition(grid->getCell(7)->getPosition() + D3DXVECTOR2(0, GameGlobal::getHeight() / 4-15));
	grid->getCell(7)->addObject(eLeopard);

	eLeopard = new LeoPard();
	eLeopard->setFlipVertical(true);
	eLeopard->SetPosition(grid->getCell(7)->getPosition() + D3DXVECTOR2(-40, GameGlobal::getHeight() / 4 - 15));
	grid->getCell(7)->addObject(eLeopard);

	//cell - 8
	eBird = new Bird2();
	eBird->SetPosition(grid->getCell(8)->getPosition() + D3DXVECTOR2(0, GameGlobal::getHeight() / 8));
	grid->getCell(8)->addObject(eBird);

	//cell - 9 
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(9)->getPosition() );
	grid->getCell(9)->addObject(eButterfly);

	ePinkWalk = new EnemyPinkWalk();
	ePinkWalk->setFlipVertical(true);
	ePinkWalk->SetPosition(grid->getCell(9)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 8, GameGlobal::getHeight() / 8));
	grid->getCell(9)->addObject(ePinkWalk);

	//cell- 10
	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(10)->getPosition() + D3DXVECTOR2(-GameGlobal::getWidth() / 8, GameGlobal::getHeight() / 8));
	grid->getCell(10)->addObject(eBrownKnife);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(10)->getPosition());
	grid->getCell(10)->addObject(eButterfly);

	//cell - 11 
	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(11)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 8-20, GameGlobal::getHeight() / 8));
	grid->getCell(11)->addObject(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(11)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 8 +10, 0));
	grid->getCell(11)->addObject(eBrownKnife);

	//cell -12 
	eBird = new Bird2();
	eBird->SetPosition(grid->getCell(12)->getPosition() + D3DXVECTOR2(0, GameGlobal::getHeight() / 8));
	grid->getCell(12)->addObject(eBird);


	//cell -13
	eBird = new Bird2();
	eBird->setFlipVertical(true);
	eBird->SetPosition(grid->getCell(13)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 8 - 10, 0));
	grid->getCell(13)->addObject(eBird);

	//cell -14
	eBird = new Bird2();
	eBird->setFlipVertical(true);
	eBird->SetPosition(grid->getCell(14)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 4 , 0));
	grid->getCell(14)->addObject(eBird);

	//cell - 18
	eLeopard = new LeoPard();
	eLeopard->SetPosition(grid->getCell(18)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 8, 0));
	grid->getCell(18)->addObject(eLeopard);

	//cell - 19 
	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(19)->getPosition() );
	grid->getCell(19)->addObject(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(19)->getPosition()+ D3DXVECTOR2(GameGlobal::getWidth() / 6, 0));
	grid->getCell(19)->addObject(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(19)->getPosition()+ D3DXVECTOR2(-GameGlobal::getWidth() / 6, 0));
	grid->getCell(19)->addObject(eBrownKnife);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(19)->getPosition() + D3DXVECTOR2(30,-30));
	grid->getCell(19)->addObject(eButterfly);

	//cell - 20 

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(20)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 6 -20, 0));
	grid->getCell(20)->addObject(eBrownKnife);

	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(20)->getPosition() + D3DXVECTOR2(10, -30));
	grid->getCell(20)->addObject(eButterfly);
	
	//cell - 21 
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(21)->getPosition() + D3DXVECTOR2(10, -30));
	grid->getCell(21)->addObject(eButterfly);

	//cell - 22
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(22)->getPosition() + D3DXVECTOR2(-50,-40));
	grid->getCell(22)->addObject(eButterfly);

	//còn thiếu 1 con dơi ở đây 
	eBat = new Bat2();
	eBat->SetPosition(grid->getCell(22)->getPosition() + D3DXVECTOR2(-60,-10));
	grid->getCell(22)->addObject(eBat);
	//cell - 23 
	ePinkWalk = new EnemyPinkWalk();
	ePinkWalk->setFlipVertical(true);
	ePinkWalk->SetPosition(grid->getCell(23)->getPosition() + D3DXVECTOR2(-5, -GameGlobal::getHeight() / 6));
	grid->getCell(23)->addObject(ePinkWalk);

	//cell - 26
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(26)->getPosition() + D3DXVECTOR2(-40, -30));
	grid->getCell(26)->addObject(eButterfly);

	//cell - 27 
	eLeopard = new LeoPard();
	eLeopard->setFlipVertical(true);
	eLeopard->SetPosition(grid->getCell(27)->getPosition() + D3DXVECTOR2(-GameGlobal::getHeight() / 6, 0));
	grid->getCell(27)->addObject(eLeopard);

	//còn 1 con enemi xanh lá chưa có ở đây 
	eGreenGun = new EnemyGreenGun();
	eGreenGun->setFlipVertical(true);
	eGreenGun->SetPosition(grid->getCell(27)->getPosition() + D3DXVECTOR2(GameGlobal::getHeight()/4,0));
	grid->getCell(27)->addObject(eGreenGun);
	//cell - 30
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(30)->getPosition() + D3DXVECTOR2(-40, -30));
	grid->getCell(30)->addObject(eButterfly);

	//cell - 31
	eButterfly = new Butterfly();
	eButterfly->SetPosition(grid->getCell(31)->getPosition() + D3DXVECTOR2(40, -30));
	grid->getCell(31)->addObject(eButterfly);

	//cell - 32 
	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(32)->getPosition() + D3DXVECTOR2(GameGlobal::getWidth() / 6, 0));
	grid->getCell(32)->addObject(eBrownKnife);

	eBrownKnife = new EnemyBrownKnife();
	eBrownKnife->SetPosition(grid->getCell(32)->getPosition() + D3DXVECTOR2(-GameGlobal::getWidth() / 4, 0));
	grid->getCell(32)->addObject(eBrownKnife);

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
