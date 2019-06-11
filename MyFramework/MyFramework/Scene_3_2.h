#pragma once
#include "Scene.h"
#include "TiledMap.h"
#include "EnemyBrownKnife.h"
#include "Game_UI.h"
#include "GameDebugDraw.h"
#include "Ninja.h"
#include "Collision.h"
#include "Weapon.h"
#include "Knife.h"
#include "Star.h"
#include "FireWheel.h"
#include "SwordOfPink.h"
#include "BulletBazooka.h"

class Scene_3_2 :public Scene
{
protected:
	//Scene's parameters
	TiledMap* map;
	Grid* grid;
	Game_UI* gui;
	Ninja* ninja;
	Camera* mCamera;
	Weapon* weapon;
	Knife* knife;
	unordered_set<Object*> lstWeaponEnemy;
	vector<Object*> lstColiableObject;
	int timer;
	float mTimeCounter;
	std::map<int, bool> keys;
	vector<Object*> lstEnemies;
public:

	int level;

	Scene_3_2(int level);
	~Scene_3_2();

	//Keyboard handling
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);


	bool isCollision(RECT rect1, RECT rect2);

	//Update
	void Update(float dt);
	void UpdateWeapon(float dt);

	void Draw();

	void InitGrid();

	RECT BoxToRect(BoundingBox b)
	{
		RECT r;
		r.top = b.y +b.h ;
		r.left = b.x;
		r.bottom = b.y;
		r.right = r.left + b.w;
		return r;
	}
};

