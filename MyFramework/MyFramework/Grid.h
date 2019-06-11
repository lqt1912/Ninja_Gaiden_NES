#pragma once
#include "Cell.h"
#include "GameGlobal.h"
#include "Debug.h"
#include "Butterfly.h"
#include "Bird2.h"
#include "LeoPard.h"
#include "EnemyPinkWalk.h"
#include "EnemyBrownKnife.h"
#include "EnemyGreenGun.h"
#include "EnemyGreenBazooka.h"
#include "Bird.h"
#include "EnemyGreenWalk.h"
#include "Bat2.h"
#include "Camera.h"
#include <fstream>
#include <string>
#include "GameDebugDraw.h"
#include "Ground.h"
using namespace std;

typedef vector<Cell*>GGrid;
typedef Cell*** ArrGRID;
typedef vector<Object*> BaseObjectList;
class Grid
{
	int number_of_columns;
	int number_of_rows;
	int number_of_cell;
	GGrid listGrid;


	BaseObjectList lstEnemies;

	BaseObjectList lstGround;


	Camera* camera;

public:
	ArrGRID  listGridA;
	vector<BoundingBox> lstGroundA;
	vector<BoundingBox> lstLadder;
	vector<BoundingBox> lstWall;
	void addObject(Object* obj);
	BaseObjectList getBaseEnemiesList();



	void Init(int row, int column);
	void InitGroundObjectA_3_2(const char* filePath);
	BaseObjectList getHandlingObjectA(Camera* camera);

	GGrid			getHandlingCellA(Camera* camera);

	BaseObjectList getAliveObjectA(Camera* camera);

	void RespawnEnemies(Camera* camera);

	void LoadResources();
	void setRow(int row);
	void setColumn(int column);
	void setNumberOfCell(int num);

	int getColumn();
	int getRow();

	int getIndex(Cell* cell);

	Cell* getCellA(int row, int column);

	void InitEnemiesObject(const char* filePath);
	void InitEnemiesObjectA(const char* filePath);

	void InitGroundObjectA(const char* filePath);

	void RenderA(D3DXVECTOR2 trans, Camera* camera);

	void UpdateA(float dt, Camera* camera);

	void ResetGrid();

	Grid();
	~Grid();

	int isCollision(RECT rect1, RECT rect2);

	void MovetoA(Object* obj, float posX, float posY);

	bool isContain(Cell* cell, D3DXVECTOR3 position);
	bool isContain(RECT rect, D3DXVECTOR3 position);

};

