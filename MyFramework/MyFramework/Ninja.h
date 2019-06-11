#pragma once
#include "Object.h"
#include "NinjaAnimations.h"
#include "NinjaData.h"
#include "NinjaState.h"
#include "Collision.h"
#include "Game_UI.h"
class Ninja : public Object
{


public:

	enum eMoveDirection
	{
		MoveToLeft, //chay tu phai sang trai
		MoveToRight, //chay tu trai sang phai
		None //dung im
	};

	~Ninja();

	static Ninja* GetInstance();

	void Update(float dt);
	void Update(float dt, vector<Object*> handleObject);
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	void SetState(NinjaState* newState);

	eMoveDirection GetMoveDirection();

	RECT GetBound();

	NinjaAnimations::eNinjaStates GetState();

	//xu ly input

	void HandleKeyboard(std::map<int, bool> keys);

	void OnKeyPressed(int key);

	void OnKeyUp(int key);


	void setY(int y);
	void setX(int x);

	// when ninja die 
	void Reset();

	//true thi se lat nguoc anh theo truc y
	void SetReverse(bool flag);

	bool detectGround(vector<Object*> grounds);
	void OnCOllisionWithGround(vector<Object*> grounds);

	bool detectGroundA(vector<BoundingBox> grounds);
	void OnCollisionWithGroundA(vector<BoundingBox> grounds);
	void OnCollisionWithWall(vector<BoundingBox> walls);
	void OnCollisionWithLadder(vector<BoundingBox> ladders);
	void OnCollisionWithWallA(vector<BoundingBox> walls);
	BoundingBox GetBoundingBox();

	void AddPhysical(int a);
	int getPhysical();
	void AddSpirit(int a);
	int getSpirit();
	void AddScore(long a);
	long getScore();
	void AddLife(int a);
	int getLife();

	bool allowJump = true,
		mCurrentReverse,
		allowDart = true,
		allowAttack = true,
		allowSitAttack = true,
		allowRunAttack = true,
		allowRun = true,
		allowClimb = false;

	bool isAttacking = false,
		isDarting = false,
		isWindDarting = false,
		isFiring = false,
		isSitting = false,
		isInjuring = false,
		isClimbing = false;

	bool isOnGround;
	bool isOnWall = false;
	float noCollision = 0;
	bool allowMoveLeft;
	bool allowMoveRight;

	Object::WeaponTypes specialWeapon = Object::NoneWeapon;
	NinjaData* ninjaData;
	NinjaAnimations* listAni;
	BoundingBox curGround;

	float limitUp, limitDown;
	int spirit = 90;
	long score;
	int life = MAX_NINJA_SOULS;
	int physical =16;
protected:

	NinjaAnimations::eNinjaStates  currentState;
	
	void ChangeAnimation(NinjaAnimations::eNinjaStates state);

private:
	// thuoc tinh cua ninja 

	


	Ninja();
	static Ninja* instance;
};