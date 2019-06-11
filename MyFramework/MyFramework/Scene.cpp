#include "Scene.h"

void Scene::Update(float dt)
{
}

void Scene::LoadContent()
{
}

void Scene::Draw()
{
}

void Scene::OnKeyDown(int KeyCode)
{

}

void Scene::OnKeyUp(int KeyCode)
{
}


D3DCOLOR Scene::GetBackColor()
{
	return backcolor;
}

Scene::~Scene()
{
}

Scene::Scene()
{
	backcolor = 0x4866ff;
	LoadContent();
}
