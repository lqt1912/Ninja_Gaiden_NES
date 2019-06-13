#pragma once
#include "Scene.h"
#include <math.h>
#include <vector>
#include "GameGlobal.h"
#include "Animation.h"
#include "TiledMap.h"
#include "EnemyBrownKnife.h"
#include "Game_UI.h"
#include "GameDebugDraw.h"
#include "Ninja.h"
#include "Collision.h"
#include "Weapon.h"
#include "Knife.h"
#include "Star.h"
#include "WindmillStar.h"
#include "FireWheel.h"
#include "SwordOfPink.h"
#include "Bullet.h"
using namespace std;


class SceneDemo :
	public Scene
{
public:

	//Keyboard handling
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);

	 bool isCollision(RECT rect1, RECT rect2);

	 //Update
	 void Update(float dt);
	 void UpdateWeapon(float dt);

	 void Draw();

	 RECT BoxToRect(BoundingBox b)
	 {
		 RECT r;
		 r.top = b.y + b.h;
		 r.left = b.x;
		 r.bottom = b.y;
		 r.right = r.left + b.w;
		 return r;
	 }
	 
	 SceneDemo(int level);
	 ~SceneDemo();
	 int currentLevel = 1;
protected:

	//Scene's parameters
	TiledMap* map;
	Grid* grid;
	Game_UI* gui;
	Ninja *ninja;
	Camera* mCamera;
	Weapon* weapon;
	Knife* knife;
	unordered_set<Object*> lstWeaponEnemy;
	vector<Object*> lstColiableObject;
	int timer;
	float mTimeCounter;
	std::map<int, bool> keys;
	vector<Object*> lstEnemies;

	Animation* GameOver;
	Animation* GameWin;
};

