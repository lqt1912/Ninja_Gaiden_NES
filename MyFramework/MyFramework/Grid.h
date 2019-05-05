#pragma once
#include "Cell.h"
#include "GameGlobal.h"
#include "Debug.h"
#include "Butterfly.h"
#include "Bird2.h"
#include "LeoPard.h"
#include "EnemyPinkWalk.h"
#include "Camera.h"
using namespace std;

typedef vector<Cell*>GGrid;

class Grid
{
	int number_of_columns;
	int number_of_rows;
	int number_of_cell;
	GGrid listGrid;

	Camera* camera;
public:

	void LoadResources();
	void setRow(int row);
	void setColumn(int column);
	void setNumberOfCell(int num);

	int getColumn();
	int getRow();

	void AddCell(Cell* cell);
	Cell* getCell(int id);
	void Render(D3DXVECTOR2 trans, Camera* camera);

	void Update(float dt, Camera* camera);

	Grid();
	~Grid();

	int isCollision(RECT r1, RECT r2)
	{
		RECT dest;
		return IntersectRect(&dest, &r1, &r2);
	}
};

