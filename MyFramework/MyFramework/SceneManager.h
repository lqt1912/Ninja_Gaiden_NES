#pragma once
#include "Scene.h"
class SceneManager
{
public:
	~SceneManager();
	static SceneManager* GetInstance();
	Scene* GetCurrentScene();
	void Update(float dt);
	void ReplaceScene(Scene* scene);
private:
	SceneManager();
	static SceneManager*  instance;
	Scene*				  currentScene;
};

	