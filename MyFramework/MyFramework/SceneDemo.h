#pragma once
#include "Scene.h"
#include <math.h>
#include <vector>
#include "GameGlobal.h"
#include "Sprite.h"
#include "Animation.h"
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

protected:
	vector<Sprite* > sprites;
	Animation* mGoldBlock;
	float mTimeCounter;
};

