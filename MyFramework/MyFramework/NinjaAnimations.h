#pragma once
#include <unordered_map>
#include "Animation.h"
class NinjaAnimations
{
public:
	NinjaAnimations();
	~NinjaAnimations();

	enum eNinjaStates
	{
		Idling,
		Jumping,
		Running,
		Attacking,
		Falling,
		Sitting,
		Attack_Sitting,
		Darting,
	};

	void AddAnimation(eNinjaStates state,const char* filePath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey = NULL);
	NinjaAnimations* GetInstance();
	unordered_map<eNinjaStates, Animation*> mAni;
	//int x = 0;
private:

	static NinjaAnimations *instance ;
	
};

