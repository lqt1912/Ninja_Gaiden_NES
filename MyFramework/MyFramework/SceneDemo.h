#pragma once
#include "Scene.h"
#include <math.h>
#include <vector>
#include "GameGlobal.h"
#include "Sprite.h"
#include "Animation.h"
#include "TiledMap.h"
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

	 Camera* getCamera();
protected:
	vector<Sprite* > sprites;
	Ninja *ninja;

	float mTimeCounter;
	int key;
	std::map<int, bool> keys;
	Camera* mCamera;
};

