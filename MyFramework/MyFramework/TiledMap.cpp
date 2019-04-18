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
	 number_of_column * 16;
	return number_of_column * 16;
}

int TiledMap::getHeight()
{
	mHeight = number_of_row * 16;
	return number_of_row * 16;
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
	D3DXVECTOR2 trans = D3DXVECTOR2((int)(GameGlobal::getWidth()/2  - camera->GetPosition().x),
									(int)(GameGlobal::getHeight()/2 - camera->GetPosition().y));
	//WTF

	Sprite* t = new Sprite();

	RECT r = camera->GetBound();
	int count = 0;
	for (int i = 0; i < number_of_row; i++)  //Số dòng của Map tile
	{
		for (int j = 0; j < number_of_column; j++)  //số cột 
		{
			D3DXVECTOR3  posi = D3DXVECTOR3(j * 16 + 8, i * 16+ 8, 0);
			if (camera != NULL)
			{
				RECT objRECT;
				objRECT.left = posi.x - 8;
				objRECT.top = posi.y - 8;
				objRECT.right = objRECT.left + 16;
				objRECT.bottom = objRECT.top + 16;
				//DebugOut((wchar_t*)L"\n left = %d , top = %d, right = %d, bottom = %d ", objRECT.left, objRECT.top, objRECT.right, objRECT.bottom);
				//neu nam ngoai camera thi khong Draw
				if (isContain(r, objRECT) == false)
				{
					continue;
					//BoolMat[i][j] = true;
				}
			}

			int tileID = mat[i][j];
			t = tiles[tileID];
			//DebugOut((wchar_t*)L"\n  temp = %d ", tileID);
			int y = tileID / 16;
			int x = tileID - y * 16;

			

			RECT sourceRECT =t->getSourceRect();
			
			D3DXVECTOR2 scale = D3DXVECTOR2(1,1);
			D3DXVECTOR2 transform = t->GetTranslation();
			float angle = 1;
			D3DXVECTOR2 rotationCenter = t->GetRotationCenter();
			D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 0, 255);

			
			
			t->Draw(posi, sourceRECT, scale, trans, angle, rotationCenter, colorKey);
			//DebugOut((wchar_t*)L"\nDrawed %d ", count++);
		}
	}
	//DebugOut((wchar_t*)L"\n\n\n\n\n\n\n Map height and width %d %d ", getHeight(), getWidth());
	//ket thuc ve
	t = NULL;

	delete t;
}

void TiledMap::Render(const char * filePath)
{
	HRESULT result;
	//Thông tin tileset
	D3DXIMAGE_INFO info;
	//Lấy thông tin texture từ đường dẫn file
	result = D3DXGetImageInfoFromFileA(filePath, &info);

	if (result != D3D_OK)
	{
		DebugOut((wchar_t*)L"[ERROR] Load Map Tileset failed: %s\n", filePath);
		return;
	}

	this->tilesetWidth = info.Width;
	this->tilesetHeight = info.Height;
	Sprite* t =new Sprite();
	D3DXVECTOR2 trans = D3DXVECTOR2(GameGlobal::getWidth() / 2 - camera->GetPosition().x, GameGlobal::getHeight() / 2 - camera->GetPosition().y);
	RECT r = camera->GetBound();


	for (int i = 0; i < this->tilesetWidth; i += 16)
	{
		RECT rect;
		rect.left = i;
		rect.right = i + 16;
		rect.top = 0;
		rect.bottom = 16;
		DebugOut((wchar_t*)L"\n left = %d, top = %d ", rect.left, rect.top);
		t = new Sprite(filePath, rect, D3DCOLOR_XRGB(255, 0, 255));

		//MessageBox(NULL, L"ERROR", L"ERROR", 1);
		if (t != NULL)
			this->tiles.push_back(t);
	}

	for (int i = 0; i < number_of_row; i++)  //Số dòng của Map tile
	{
		for (int j = 0; j <number_of_column; j++)  //số cột 
		{
			int tileID = mat[i][j];
			t = tiles[tileID];
			DebugOut((wchar_t*)L"\n  temp = %d ", tileID);
			int y = tileID / 16;
			int x = tileID - y * 16;
			D3DXVECTOR3  posi = D3DXVECTOR3(j * 16 + 8, i * 16 + 8, 0);

			RECT sourceRECT;

			sourceRECT.top = y * 16;
			sourceRECT.bottom = sourceRECT.top + 16;
			sourceRECT.left = x * mWidth;
			sourceRECT.right = sourceRECT.left + mWidth;

			D3DXVECTOR2 scale = D3DXVECTOR2(1, 1);
			D3DXVECTOR2 transform = t->GetTranslation();
			float angle = 1;
			D3DXVECTOR2 rotationCenter = t->GetRotationCenter();
			D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 0, 255);

			if (camera != NULL)
			{
				RECT objRECT;
				objRECT.left = posi.x - 8;
				objRECT.top = posi.y - 8;
				objRECT.right = objRECT.left + 16;
				objRECT.bottom = objRECT.top + 16;
				//DebugOut((wchar_t*)L"\n left = %d , top = %d, right = %d, bottom = %d ", objRECT.left, objRECT.top, objRECT.right, objRECT.bottom);
				//neu nam ngoai camera thi khong Draw
				if (isContain(objRECT, r) == false)
					continue;
			}

				t->Draw(posi, sourceRECT, scale, trans, angle, rotationCenter, colorKey);

			
		}
	}
	//ket thuc ve
	t = NULL;
	delete t;

}

TiledMap::~TiledMap()
{
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
	//DebugOut((wchar_t*)L"\n \n \n \n \n Number of tiles = %d ", this->NumberOfTiles);
	this->number_of_row = mapInfo[1];
	//DebugOut((wchar_t*)L"\n \n \n \n Number of rows = %d ", this->number_of_row);
	this->number_of_column = mapInfo[2];
	//DebugOut((wchar_t*)L"\n \n \n \n Number of column  = %d ", this->number_of_column);
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
		//MessageBox(NULL, L"Error", L"Cannot open map file ", 1);
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
	
	//DebugOut((wchar_t*)L"\n tileset Height = %d, tileset Width = %d ", tilesetHeight, tilesetWidth);
	for (int i = 0; i < this->tilesetWidth; i += 16)
	{
		RECT rect;
		rect.left = i;
		rect.right = i + 16;
		rect.top = 0;
		rect.bottom = 16;
		//DebugOut((wchar_t*)L"\n left = %d, top = %d ", rect.left, rect.top);
		tile = new Sprite(tilesLocation, rect, D3DCOLOR_XRGB(255, 0, 255));
		tile->SetScale(D3DXVECTOR2(1,1));
		tile->SetHeight(32);
		tile->SetWidth(32);

		//MessageBox(NULL, L"ERROR", L"ERROR", 1);
		if (tile != NULL)
			this->tiles.push_back(tile);	
	}
	tile = NULL;
	delete tile;
}





bool TiledMap::isContain(RECT rect1, RECT rect2)
{
	if (rect1.left >= rect2.right || rect1.right <= rect2.left-16 || rect1.top > rect2.bottom || rect1.bottom < rect2.top)
	{
		return false;
	}
	return true;
}
