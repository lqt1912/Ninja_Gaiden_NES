#include "SceneDemo.h"



SceneDemo::SceneDemo()
{
	LoadContent();
}


SceneDemo::~SceneDemo()
{
}

void SceneDemo::Update(float dt)
{
	mGoldBlock->Update(dt);
}

void SceneDemo::LoadContent()
{
	mTimeCounter = 0;

	backcolor = 0x54acd2;

	mGoldBlock = new Animation("ninja.png",140, 7, 20, 0.1);
	mGoldBlock->SetPosition(GameGlobal::getWidth() / 2, GameGlobal::getHeight() / 2);
	mGoldBlock->SetScale(D3DXVECTOR2(-2, 2));
}

void SceneDemo::Draw()
{
	mGoldBlock->Draw();
}
