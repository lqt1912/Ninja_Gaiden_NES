#pragma once
#include "GameGlobal.h"
#include "Object.h"
#include "Camera.h"
#include <vector>
using namespace std;


class Cell
{
public:

	D3DXVECTOR2 position;
	
	int width = GameGlobal::getWidth()/2;
	int height = GameGlobal::getHeight()/2;
	vector<Object* > listObject;

	void Render(D3DXVECTOR2 trans);

	void Update(float dt, Camera* camera );
	D3DXVECTOR2 getPosition();
	void setPosition(D3DXVECTOR2 vt);
	void addObject(Object* obj);
	RECT getBound();
	int getWidth();
	int getHeight();

	int isCollision(RECT r1, RECT r2);

	Cell();
	~Cell();
};

