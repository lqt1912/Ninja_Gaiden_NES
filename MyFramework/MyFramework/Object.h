#pragma once

#include "Animation.h"
#include "Camera.h"
struct CollisionReturn
{
	bool IsCollided;
	RECT RegionCollision;
};
struct BoundingBox {
	float x, y;
	float w, h;
	float vx, vy; //quang duong di duoc thuc su
};

class Object :public Sprite
{
public:
	Object();
	~Object();

	enum WeaponTypes
	{
		eKnife,
		eDart,
		eFireWheel,
		eBullet,
		eStar,
		eWindStar,
		eSwrodOfPink,
		NoneWeapon,
	};
	enum ItemTypes
	{
		SpiritBlue,
		SpiritRed,
		FireWheel,
		Star,
		WindmillStar,
		Physical,
		BonusBlue,
		BonusRed,
		TimeFreeze,
		NoItem,
	};
	enum SideCollisions
	{
		Left, //0
		Right, //1
		Top, //2
		Bottom, //3
		NotKnow
	};
	struct ResultCollision
	{
		bool isCollision;
		Object::SideCollisions side;
		float nx, ny;
		float t;
	};
	enum ObjectTypes
	{
		eNinja,
		eEnemy,
		eGround,
		eWeapon,
		eHolder,
		eItem,
		None,
	};


	virtual BoundingBox GetBoundingBox();

	virtual void moveTo(Object* des); // object di chuyen  den vi tri cua object khac ( des )

	virtual void moveTo(Object* des, int v);

	virtual void moveTo(float,float);

	virtual void moveTo(float x, float y, float v);
	virtual RECT GetBound();

	virtual void Reset(D3DXVECTOR2 pos);
	virtual void SetPosition(float x, float y);

	virtual void SetPosition(D3DXVECTOR2 pos);

	virtual void SetPosition(D3DXVECTOR3 pos);

	virtual void AddPosition(D3DXVECTOR3 pos);

	virtual void AddPosition(D3DXVECTOR2 pos);

	virtual void AddPosition(float x, float y);

	virtual void SetWidth(int width);

	virtual int GetWidth();

	virtual void SetHeight(int height);

	virtual int GetHeight();

	virtual float GetVx();

	virtual void SetVx(float vx);

	virtual void AddVx(float vx);

	virtual float GetVy();

	virtual void SetVy(float vy);

	virtual void AddVy(float vy);

	virtual D3DXVECTOR3 GetPosition();

	virtual void Update(float dt);


	virtual float getX();

	virtual float getY();

	virtual int getType();

	virtual ObjectTypes getObjectType();

	virtual void setFlipVertical(bool isFlip);

	virtual void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	virtual void setVisible(bool vs);
	virtual int getVisible();

	virtual void OnCollision(Object* impactor, ResultCollision data, SideCollisions side);
	virtual void setInitPosition(float a, float b);
	virtual D3DXVECTOR2 getInitPosition();
	virtual void setInitFlip(bool);
	virtual bool getInitFlip();
	virtual void MoveBetween(float fA, float lA);
	float firstPositionx, lastPositionX;

	virtual int getActive();
	virtual int getDead();
	virtual void setActive(bool b);
	virtual void setDead(bool b);
	virtual void Respawn();
	virtual bool getFlip();
	bool isFlip = false;
	bool isActive = true;
	int type = -1;
protected:
	
	bool isVisible = true;  //Flag to expect if it was rendered on the screen 
	//flag to expect if it was in the camera and  colliable
	bool isDead = false;    //flag to expect if it was killed by ninja

	ObjectTypes Tag; //Tag de nhan dien loai object
	//duoc goi khi set position cua object, dung cho ke thua
	virtual void OnSetPosition(D3DXVECTOR3 pos);


	//vi tri tam position x va y
	float x, y;
	float initPositionX, initPositionY;
	bool initFlip;
	//phan toc vx, vy
	float vx, vy;
	float dx, dy;
	//size cua entity
	float width, height;

	static Camera* camera;
};


