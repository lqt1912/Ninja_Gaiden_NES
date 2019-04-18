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
	};

	void AddAnimation(eNinjaStates state,const char* filePath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey = NULL);
	NinjaAnimations* GetInstance();
	unordered_map<eNinjaStates, Animation*> mAni;
private:

	static NinjaAnimations *instance ;
	
};

