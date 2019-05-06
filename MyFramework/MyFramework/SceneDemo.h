#pragma once
#include "Scene.h"
#include <math.h>
#include <vector>
#include "GameGlobal.h"
#include "Sprite.h"
#include "Animation.h"
#include "TiledMap.h"
#include "Dart.h"
#include "Butterfly.h"
#include "LeoPard.h"
#include "EnemyBrownKnife.h"
#include "EnemyPinkWalk.h"
#include "Bat2.h"
#include "EnemyGreenGun.h"
#include "Grid.h"

using namespace std;
class SceneDemo :
	public Scene
{
public:
	SceneDemo();
	~SceneDemo();

	void Update(float dt);
	void LoadContent();
	void Draw();
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	void LoadMap();
	 TiledMap* map;

	 Grid* grid;

	 Camera* getCamera();

	 int isCollision(RECT r1, RECT r2)
	 {
		 RECT dest;
		 return IntersectRect(&dest, &r1, &r2);
	 }

protected:

	vector<Sprite* > sprites;
	Ninja *ninja;
	float mTimeCounter;
	int key;
	std::map<int, bool> keys;
	Camera* mCamera;

	// ENEMY
	Butterfly* eButterfly;
	LeoPard* eLeopard;
	EnemyBrownKnife* eBrownKnife;
	EnemyPinkWalk* ePinkWalk;
	Bird2* eBird;
	Bat2* eBat;
	EnemyGreenGun* eGreenGun;

	vector<Object*> lstEnemies;
};

