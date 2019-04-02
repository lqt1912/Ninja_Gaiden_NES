#include "SceneManager.h"


SceneManager* SceneManager::instance = NULL;

SceneManager::SceneManager()
{
	currentScene = nullptr;

}


SceneManager::~SceneManager()
{
}

SceneManager * SceneManager::GetInstance()
{
	if (!instance)
		instance = new SceneManager();
	return instance;
}

Scene * SceneManager::GetCurrentScene()
{
	return currentScene;
}

void SceneManager::Update(float dt)
{
	currentScene->Update(dt);
}

void SceneManager::ReplaceScene(Scene * scene)
{
	delete currentScene;
	currentScene = scene;
}
