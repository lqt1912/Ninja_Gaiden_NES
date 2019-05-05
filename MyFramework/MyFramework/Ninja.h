#pragma once
#include "Object.h"
#include "NinjaAnimations.h"
#include "NinjaData.h"
#include "NinjaState.h"
#include "Dart.h"
class Ninja: public Object 
{


public:
	enum eMoveDirection
	{
		MoveToLeft, //chay tu phai sang trai
		MoveToRight, //chay tu trai sang phai
		None //dung im
	};
	Ninja();
	~Ninja();
	void Update(float dt);

	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	void SetState(NinjaState *newState);

	eMoveDirection GetMoveDirection();

	RECT GetBound();

	NinjaAnimations::eNinjaStates GetState();

	//xu ly input

	void HandleKeyboard(std::map<int, bool> keys);

	void OnKeyPressed(int key);

	void OnKeyUp(int key);
	int getX()
	{
		return x;
	}

	void setY(int y);
	void setX(int x);
	int getY()
	{
		return y;
	}

	//true thi se lat nguoc anh theo truc y
	void SetReverse(bool flag);
	bool allowJump = true,
		mCurrentReverse,
		allowDart = true,
		isDarting = false,
		allowAttack = true,
		allowSitAttack = true,
		allowRunAttack = true;

	NinjaAnimations* listAni;
	Dart* dart;
protected:
	
	NinjaData * ninjaData;

	

	NinjaAnimations::eNinjaStates  currentState;
	  
	void ChangeAnimation(NinjaAnimations::eNinjaStates state);


	//chi cho phep jump khi nhan nhim space, muon nhay lai phai tha phim space roi nhan lai


};