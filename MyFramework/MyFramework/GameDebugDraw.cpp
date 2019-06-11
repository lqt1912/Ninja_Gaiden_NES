#include "GameDebugDraw.h"
#include "GameGlobal.h"
GameDebugDraw* GameDebugDraw::_instance = NULL;
GameDebugDraw::GameDebugDraw()
{
	mSpriteHandler = GameGlobal::getSpriteHandler();
	mSpriteHandler->GetDevice(&mddv);
	D3DXCreateLine(mddv, &LineDraw);

	//set size cho line
	LineDraw->SetWidth(1);

	//set mau cho line
	mColor = D3DCOLOR_XRGB(255, 0, 0);

}

GameDebugDraw::~GameDebugDraw()
{

}

GameDebugDraw* GameDebugDraw::getInstance()
{
	if (_instance == NULL)
		_instance = new GameDebugDraw();
	return _instance;
}

void GameDebugDraw::Draw()
{

}

void GameDebugDraw::setLineSize(float width)
{
	LineDraw->SetWidth(width);
}

void GameDebugDraw::DrawLine(D3DXVECTOR2 lines[], int count)
{
	LineDraw->Begin();
	LineDraw->Draw(lines, count, mColor);
	LineDraw->End();
}

void GameDebugDraw::DrawRect(RECT rect, Camera * camera)
{

	D3DXVECTOR3 trans = D3DXVECTOR3(0, 0, 0);

	if (camera)
	{
		trans = D3DXVECTOR3(-camera->getX(), 0, 0);
	}

	D3DXVECTOR2 lines[] = { D3DXVECTOR2(rect.left + trans.x, 208 - (rect.top + trans.y)),
							D3DXVECTOR2(rect.right + trans.x,208 - (rect.top + trans.y)),
							D3DXVECTOR2(rect.right + trans.x, 208 - (rect.bottom + trans.y)),
							D3DXVECTOR2(rect.left + trans.x,208 - (rect.bottom + trans.y)),
							D3DXVECTOR2(rect.left + trans.x, 208 - (rect.top + trans.y))
	};

	DrawLine(lines, 5);
}

void GameDebugDraw::DrawRect(Object * obj, D3DXVECTOR2 position)
{
	RECT rect;

	rect.left = position.x - obj->GetWidth() / 2;
	rect.right = rect.left + obj->GetWidth();

	rect.top = position.y + obj->GetHeight() / 2;

	rect.bottom = rect.top - obj->GetHeight();

	D3DXVECTOR2 lines[] = { D3DXVECTOR2(rect.left , rect.top),
							D3DXVECTOR2(rect.right , rect.top),
							D3DXVECTOR2(rect.right , rect.bottom),
							D3DXVECTOR2(rect.left , rect.bottom),
							D3DXVECTOR2(rect.left , rect.top) };

	DrawLine(lines, 5);
}

void GameDebugDraw::setColor(D3DCOLOR color)
{
	mColor = color;
}