#pragma once
#include "GameGlobal.h"
#include "Object.h"
#include "Camera.h"
#include <vector>
#include <unordered_set>
using namespace std;


class Cell
{
public:

	D3DXVECTOR2 position;
	D3DXVECTOR2 getPosition();
	void setPosition(D3DXVECTOR2 vt);

	int width = CELL_WIDTH;
	int height = CELL_HEIGHT;
	int getWidth();
	int getHeight();
	RECT getBound();

	unordered_set<Object* > listObject;

	
	unordered_set<Object* > getlstObject();

	void addObject(Object* obj);
	void removeObject(Object* obj);
	int getNumberEnemies();

	void Render(D3DXVECTOR2 trans);
	void Update(float dt, Camera* camera);

	bool CheckContain(Object* obj);
	int isCollision(RECT r1, RECT r2);


	void RespawnEnemies(Camera* camera);
	unordered_set<Object* > getAliveEnemies();
	bool isContain(RECT rect, D3DXVECTOR2 position);
	Cell();
	~Cell();
};

