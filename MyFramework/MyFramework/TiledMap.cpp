#include "TiledMap.h"
#include <string>
#include "GameGlobal.h"



void TiledMap::SetCamera(Camera * camera)
{
	this->camera = camera;
}
TiledMap::TiledMap(const char * filePath)
{
	LoadMatrix(filePath);
}

int TiledMap::getWidth()
{
	mWidth = number_of_column * TILE_WIDTH;
	return number_of_column * TILE_WIDTH;
}

int TiledMap::getHeight()
{
	mHeight = number_of_row * TILE_HEIGHT;
	return number_of_row * TILE_HEIGHT;
}

int TiledMap::getTileWidth()
{
	return tilesetWidth;
}

int TiledMap::getTileheight()
{
	return tilesetHeight;
}
//vẽ lên 

void TiledMap::Render()
{

	D3DXVECTOR2 trans = D3DXVECTOR2((int)(- Camera::getInstance()->getX()),
									(int)(0));
	Sprite* t = new Sprite();

	RECT r = Camera::getInstance()->GetBound();

	int count = 0;
	for (int i = 0; i < number_of_row; i++)  //Số dòng của Map tile
	{
		for (int j = 0; j < number_of_column; j++)  //số cột 
		{
			D3DXVECTOR3  posi = D3DXVECTOR3(j * TILE_WIDTH + TILE_WIDTH/2,  (i * TILE_HEIGHT+ TILE_HEIGHT/2), 0);
			if (camera != NULL)
			{
				RECT objRECT;
				objRECT.left = posi.x - TILE_WIDTH/2;
				objRECT.top = posi.y - TILE_HEIGHT/2;
				objRECT.right = objRECT.left + TILE_WIDTH;
				objRECT.bottom = objRECT.top + TILE_HEIGHT;

				//neu nam ngoai camera thi khong Draw
				if (isContain(r, objRECT) == false)
				{
					continue;
				}
			}

			int tileID = mat[i][j];
			t = tiles[tileID];
			int y = tileID / TILE_HEIGHT;
			int x = tileID - y * TILE_WIDTH;

			

			RECT sourceRECT =t->getSourceRect();
			
			D3DXVECTOR2 scale = D3DXVECTOR2(1,1);
			D3DXVECTOR2 transform = t->GetTranslation();
			float angle = 1;
			D3DXVECTOR2 rotationCenter = t->GetRotationCenter();
			D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 0, 255);
			
			t->Draw(posi, sourceRECT, scale, trans, angle, rotationCenter, colorKey);
		}
	}
	//ket thuc ve
	t = NULL;

	delete t;
}


TiledMap::~TiledMap()
{
	for (auto tile : tiles)
	{
		tile = nullptr;
		delete tile;
	}
	tiles.clear();
}

// lưu các id tương ứng vào ma trận
void TiledMap::LoadMatrix(const char* filepath)
{
	vector<int> mapInfo;
	fstream fileInput(filepath, ios::in);
	if (fileInput.fail())
		MessageBox(NULL, L"Error", L"Cannot open map file ", 1);

	char tmp[50];
	fileInput.getline(tmp, 50);
	string line = tmp;
	int pos = 0;
	while (((pos = line.find(',')) != string::npos))
	{

		string token = line.substr(0, pos);
		int temp = stoi(token);
		mapInfo.push_back((temp));
		line.erase(0, pos + 1);
	}
	this->NumberOfTiles = mapInfo[0];
	
	this->number_of_row = mapInfo[1];
	
	this->number_of_column = mapInfo[2];
	
	mapInfo.clear();

	int index = 0;

	// Đọc từng dòng của ma trận  
	while (!fileInput.eof())
	{
		char tmp1[1000];
		
		fileInput.getline(tmp1, 1000);
		
		string line1 = tmp1;
		pos = 0;
		while (((pos = line1.find(',')) != string::npos))
		{
			string token1 = line1.substr(0, pos);
			int temp1 = stoi(token1);
			mapInfo.push_back((temp1));
			line1.erase(0, pos + 1);
		}

		mat.push_back(mapInfo);
		mapInfo.clear();
	}
	
}


//Load các ảnh nhỏ xinh vào trong 1 vector với id tương ứng 
void TiledMap::LoadTileSet(const char* tilesLocation)
{
	HRESULT result;
	//Thông tin tileset
	D3DXIMAGE_INFO info;
	//Lấy thông tin texture từ đường dẫn file
	result = D3DXGetImageInfoFromFileA(tilesLocation, &info);

	if (result != D3D_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] Load Map Tileset failed: %s\n", tilesLocation);
		return;
	}

	this->tilesetWidth = info.Width;
	this->tilesetHeight = info.Height;
	Sprite* tile;
	
	for (int i = 0; i < this->tilesetWidth; i += 16)
	{
		RECT rect;
		rect.left = i;
		rect.right = i + TILE_WIDTH;
		rect.top = 0;
		rect.bottom = TILE_HEIGHT;
	
		tile = new Sprite(tilesLocation, rect, D3DCOLOR_XRGB(255, 0, 255));
		tile->SetScale(D3DXVECTOR2(1,1));
		tile->SetHeight(TILE_HEIGHT);
		tile->SetWidth(TILE_WIDTH);

		if (tile != NULL)
			this->tiles.push_back(tile);	
	}
	tile = NULL;
	delete tile;
}





bool TiledMap::isContain(RECT rect1, RECT rect2)
{
	if (rect1.left >= rect2.right || rect1.right <= rect2.left-16 || rect1.top < rect2.bottom -32|| rect1.bottom > rect2.top)
	{
		return false;
	}
	return true;
}
