#pragma once
#include "GameGlobal.h"
#include "Game.h"
#include "Sprite.h"
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include "Camera.h"
using namespace std;

typedef vector<vector<int>>matrix;
typedef vector<vector<bool>>boolmat;
typedef vector<vector<Sprite* >> matrixSprite;
typedef vector<int> row;

class TiledMap
{
	 matrix mat;
	vector<Sprite*>tiles;

public:
	void LoadMatrix(const char* filepath);

	void LoadTileSet(const char* tilesLocation);

	   // ma trận kết quả đọc file txt

	int number_of_row; //số cột
	int number_of_column; //số dòng 
	int NumberOfTiles;  //số tile khác nhau
	int mWidth, mHeight;  //dài, 
	int tilesetWidth, tilesetHeight;  // dài rộng cùa từng ô, mặc định 16 - 16

	LPCWSTR location;   //cái này không dùng
	//nordered_map<int, Sprite*> tiles;
	  //cái để đọc file png dài thòng lòng, lưu vào. 

	TiledMap(const char * filePath);
	int getWidth();
	int getHeight();
	int getTileWidth();
	int getTileheight();
	void Render();
	void Render(const char* filePath);

	~TiledMap();


	bool isContain(RECT rect1, RECT rect2);

	Camera* camera;
	void SetCamera(Camera* camera);
};

//việc cần làm :
//1 - Thêm thuộc tính bool isvisible, xét vị trí tile, nằm ngoài Camera Bound thì đéo load. 
//Như vậy sẽ giảm thiểu số hình cần load trong 1 frame. 
// Cơ chế load: 
//B1- Đọc ma trận từ file .txt lưu vào một mảng có trước(mảng mat)
//B2- Đọc tileset, load từng sprite + id tương ứng và lưu vào vector tiles.
//B3- Render: Duyệt mảng có trước, lấy vị trí i, j, load Sprite có id tương ứng. 
//Nguyên tắc load: Nằm ngoài camera bound sẽ không load (tức ngoài vùng biên của camera).  
//Khi camera chưa hoàn thiện thì map sẽ load không ổn, vì lượng sprite render lên quá nhiều. Khi có điều kiện sẽ giảm
//bớt lượng sprite cần load. NV sẽ ổn hơn. 
//tilemap được load trong Scene Demo

