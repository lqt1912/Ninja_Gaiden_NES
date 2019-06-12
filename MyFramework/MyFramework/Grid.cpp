#include "Grid.h"
#include "BrownBoss.h"

void Grid::addObject(Object* obj)
{
	this->lstEnemies.push_back(obj);
}
BaseObjectList Grid::getBaseEnemiesList()
{
	return this->lstEnemies;
}


void Grid::Init(int row, int column)
{
	setRow(row);
	setColumn(column);
	listGridA = new Cell * *[row];
	for (int i = 0; i < row; i++)
	{
		listGridA[i] = new Cell * [column];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			listGridA[i][j] = new Cell();
			listGridA[i][j]->setPosition(D3DXVECTOR2(j * CELL_WIDTH + CELL_WIDTH/2, i * CELL_HEIGHT + CELL_HEIGHT/2));
		}
	}

}


BaseObjectList Grid::getHandlingObjectA(Camera * camera)
{
	return this->getAliveObjectA(camera);
}


GGrid Grid::getHandlingCellA(Camera * camera)
{
	GGrid cellHandling;
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			if (isCollision(camera->GetBound(), listGridA[i][j]->getBound()))
				cellHandling.push_back(listGridA[i][j]);
		}
	}
	return cellHandling;
}

BaseObjectList Grid::getAliveObjectA(Camera * camera)
{
	BaseObjectList objectAliving;
	
	for (auto cell : getHandlingCellA(camera))
	{
		for (auto a : cell->getAliveEnemies())
		{
			RECT cameraBound = camera->GetBound();
			//if (a->getType() == 7)
				//MessageBox(NULL, L"đeos", L"Đeos", 1);
			cameraBound.left = cameraBound.left - 10;
			if (isContain(cameraBound, a->GetPosition()) == true )
				objectAliving.push_back(a);
			else
				a->Respawn();
		}
	}
	return objectAliving;
}

void Grid::RespawnEnemies(Camera * camera)
{
	for (auto cell : this->getHandlingCellA(camera))
	{
		cell->RespawnEnemies(camera);
	}
}

void Grid::LoadResources()
{

}

void Grid::setRow(int row)
{
	this->number_of_rows = row;
}

void Grid::setColumn(int column)
{
	this->number_of_columns = column;
}

void Grid::setNumberOfCell(int num)
{
	this->number_of_cell = num;
}

int Grid::getColumn()
{
	return number_of_columns;
}

int Grid::getRow()
{
	return number_of_rows;
}

int Grid::getIndex(Cell * cell)
{
	for (int i = 0; i < listGrid.size(); i++)
		if (listGrid[i] == cell)
			return i;

}

Cell * Grid::getCellA(int row, int column)
{
	return listGridA[row][column];
}

void Grid::InitEnemiesObject(const char* filePath)
{
	fstream fileInput(filePath, ios::in);
	if (fileInput.fail())
		MessageBox(NULL, L"Error", L"Cannot open enemies file ", 1);

	//Lấy dòng, cột

	char tmp1[50];
	fileInput.getline(tmp1, 50);
	string strtmp1 = tmp1;

	string rowstr = strtmp1.substr(0, strtmp1.find(','));
	int row = stoi(rowstr);
	strtmp1.erase(0, strtmp1.find(',') + 1);

	string columnstr = strtmp1.substr(0, strtmp1.find(','));
	int column = stoi(columnstr);
	strtmp1.erase(0, strtmp1.find(',') + 1);
	this->Init(row, column);

	Object* obj = new Object();
	while (!fileInput.eof())
	{
		char tmp1[50];
		fileInput.getline(tmp1, 50);
		string strtmp1 = tmp1;

		int EnemiesTag = stoi(strtmp1.substr(0, strtmp1.find(',')));

		switch (EnemiesTag)
		{
		case 1:
			obj = new Bat2();
			break;
		case 2:
			obj = new Bird2();
			break;
		case 3:
			obj = new Butterfly();
			break;
		case 4:
			obj = new EnemyBrownKnife();
			break;
		case 6:
			obj = new EnemyPinkWalk();
			break;
		case 5:
			obj = new EnemyGreenGun();
			break;
		case 7:
			obj = new LeoPard();
			break;
		case 8:
			obj = new Bird();
			break;
		case 9:
			obj = new EnemyGreenBazooka();
			break;
		case 10:
			obj = new EnemyGreenWalk();
			break;
		case 11:
			obj = new BrownBoss();
			break;
		default:
			MessageBox(NULL, L"Error ", L"Error enemies tag not found!", 1);
			break;
		}
		strtmp1.erase(0, strtmp1.find(',') + 1);

		//Lấy vị trí
		string token1 = strtmp1.substr(0, strtmp1.find(','));
		int PosiX = stoi(token1);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token2 = strtmp1.substr(0, strtmp1.find(','));
		int PosiY = stoi(token2);
		strtmp1.erase(0, strtmp1.find(',') + 1);
		obj->setInitPosition(PosiX, PosiY);
		obj->SetPosition(PosiX, PosiY);

		//Lấy Flip
		string token3 = strtmp1.substr(0, strtmp1.find(','));
		int Flip = stoi(token3);
		obj->isFlip = Flip;
		obj->setInitFlip(Flip);
		obj->setFlipVertical(Flip);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		//Lấy quỹ đạo di chuyển (đường thẳng)
		string token4 = strtmp1.substr(0, strtmp1.find(','));
		int firstOrbitX = stoi(token4);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token5 = strtmp1.substr(0, strtmp1.find(','));
		int lastOrbitX = stoi(token5);
		strtmp1.erase(0, strtmp1.find(',') + 1);
		obj->firstPositionx = firstOrbitX;
		obj->lastPositionX = lastOrbitX;

		//Nếu là Holder thì xét thêm 1 tham số
		if (obj->getObjectType() == Object::eHolder)
		{
			string token6 = strtmp1.substr(0, strtmp1.find(','));
			int id = stoi(token6);
			auto h = (Holder*)obj;
			h->setItemType(id);
			obj = h;			
			strtmp1.erase(0, strtmp1.find(',') + 1);
		}

		//Lấy vị trí
		string j = strtmp1.substr(0, strtmp1.find(','));
		int cellj = stoi(j);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string i = strtmp1.substr(0, strtmp1.find(','));
		int celli = stoi(i);
		strtmp1.erase(0, strtmp1.find(',') + 1);
		listGridA[cellj][celli]->addObject(obj);

		this->lstEnemies.push_back(obj);
	
	}
	obj = NULL;
	delete obj;
}

void Grid::InitEnemiesObjectA(const char* filePath)
{
	InitEnemiesObject(filePath);
}

void Grid::InitGroundObjectA(const char* filePath)
{
	fstream fileInput(filePath, ios::in);
	if (fileInput.fail())
		MessageBox(NULL, L"Error", L"Cannot open enemies file ", 1);

	//Object* obj = new Object();

	while (!fileInput.eof())
	{
		BoundingBox box;
		char tmp1[50];
		fileInput.getline(tmp1, 50);
		string strtmp1 = tmp1;

		int GroundTag = stoi(strtmp1.substr(0, strtmp1.find(',')));

		switch (GroundTag)
		{
		case 1:
		case 2:
		case 3:
		case 4:		
		case 5:
		case 6:
		case 7:
		case 8:
		{
			box.w = 200;
			box.h = 16;
			break;
		}
		case 9:
		{
			box.w = 16;
			box.h = 32;
			break;
		}

		default:
			MessageBox(NULL, L"Error ", L"Error rground tag not found!", 1);
			break;
		}

		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token1 = strtmp1.substr(0, strtmp1.find(','));
		int PosiX = stoi(token1);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token2 = strtmp1.substr(0, strtmp1.find(','));
		int PosiY = stoi(token2);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		box.x = PosiX;
		box.y = PosiY - box.h;



		this->lstGroundA.push_back(box);
		
	}

}

void Grid::InitGroundObjectA_3_2(const char* filePath)
{
	fstream fileInput(filePath, ios::in);
	if (fileInput.fail())
		MessageBox(NULL, L"Error", L"Cannot open enemies file ", 1);

	//Object* obj = new Object();

	while (!fileInput.eof())
	{
		BoundingBox box;
		char tmp1[50];
		fileInput.getline(tmp1, 50);
		string strtmp1 = tmp1;

		int GroundTag = stoi(strtmp1.substr(0, strtmp1.find(',')));
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token1 = strtmp1.substr(0, strtmp1.find(','));
		int PosiX = stoi(token1) ;
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token2 = strtmp1.substr(0, strtmp1.find(','));
		int PosiY = stoi(token2)  ;
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token3 = strtmp1.substr(0, strtmp1.find(','));
		int iW = stoi(token3);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		string token4 = strtmp1.substr(0, strtmp1.find(','));
		int iH = stoi(token4);
		strtmp1.erase(0, strtmp1.find(',') + 1);

		
		box.x = PosiX - 6;
		box.y = PosiY + 20;
		box.w = iW - 4;
		box.h = iH;
		box.vx = 0;
		box.vy = 0;
		//box.x = PosiX;
		//box.y = PosiY -iH;
		//box.w = iW;
		//box.h = iH;
		//box.vx = 0;
		//box.vy = 0;
		switch (GroundTag)
		{
		case 0:
		{
			//DebugOut((wchar_t*)L"0\n");
			lstGroundA.push_back(box);
			break;
		}
		case 1:
		{
			//DebugOut((wchar_t*)L"1\n");
			lstWall.push_back(box);
			break;
		}
		case 2:
		{
			lstLadder.push_back(box);
			break;
		}
		default:
			MessageBox(NULL, L"Error", L"Cannot find tag ", 1);
		}
	}
}
void Grid::RenderA(D3DXVECTOR2 trans, Camera * camera)
{
	for (auto e : this->getHandlingCellA(camera))
	{
		e->Render(trans);
	}

}


void Grid::UpdateA(float dt, Camera * camera)
{
	BaseObjectList baseobj = getHandlingObjectA(camera);
	for (auto e : baseobj)
	{
		e->Update(dt);
		float dx = e->GetVx() * dt;
		float dy = e->GetVy() * dt;
		MovetoA(e, dx, dy);
	}
	RespawnEnemies(camera);
}

void Grid::ResetGrid()
{
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j < number_of_columns; j++)
		{
			for (auto a : listGridA[i][j]->listObject)
			{
				if (a->getObjectType() == Object::eHolder)
				{
					a->Respawn();
				}
			}
		}
	}
}

Grid::Grid()
{

}


Grid::~Grid()
{
	for (auto e : lstEnemies)
		e = nullptr;
	lstEnemies.clear();
	
	for (int i = 0; i < number_of_rows; i++)
	{
		for (int j = 0; j<number_of_columns; i++)
		{
			listGridA[i][j]->listObject.clear();
			delete listGridA[i][j];
		}
		delete listGridA[i];
	}

	number_of_rows = 0;
	number_of_columns = 0;
}

int Grid::isCollision(RECT rect1, RECT rect2)
{

	if (rect1.left >= rect2.right || rect1.right <= rect2.left-100 || rect1.top <= rect2.bottom || rect1.bottom >= rect2.top)
	{
		return false;
	}
	return true;
}


void Grid::MovetoA(Object * obj, float posX, float posY)
{
	for (int i = 0; i < number_of_rows; i++)
		for (int j = 0; j < number_of_columns; j++)
		{
			if (listGridA[i][j]->CheckContain(obj) == true)
			{
				listGridA[i][j]->removeObject(obj);
			}
		}

	if(isFrozenEnemies ==false)
		obj->AddPosition(posX, posY);

	for (int i = 0; i < number_of_rows; i++)
		for (int j = 0; j < number_of_columns; j++)
		{
			if (isContain(listGridA[i][j]->getBound(), obj->GetPosition()) == 1)
			{
				listGridA[i][j]->addObject(obj);
				obj->setVisible(false);
			}
		}
}

bool Grid::isContain(Cell * cell, D3DXVECTOR3 position)
{

	D3DXVECTOR3 cellPosition(cell->getPosition().x, cell->getPosition().y, 0);

	if (position.x >= cellPosition.x - 62.5f && position.x <= cellPosition.x + 62.5f && position.y >= cellPosition.x - 51.0f && position.y <= cellPosition.y + 51.0f)
		return true;
	return false;
}

bool Grid::isContain(RECT rect, D3DXVECTOR3 position)
{
	if (position.x >= rect.left && position.x <= rect.right && position.y >= rect.bottom && position.y <= rect.top)
		return true;
	return false;
}




