#pragma once
#include "GameGlobal.h"
#include "Ninja.h"
class Scene
{
public:
	virtual void Update(float dt);
	virtual void LoadContent();
	virtual void Draw();

	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	//virtual void OnMouseDown(float x, float y);

	D3DCOLOR GetBackColor();

	~Scene();
protected:
	Scene();
	D3DCOLOR backcolor;
};