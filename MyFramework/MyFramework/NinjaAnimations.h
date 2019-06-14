#pragma once
#include <unordered_map>
#include "Animation.h"
class NinjaAnimations
{
public:

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
		Injuring,
		Impacting,
		Climbing,
		Clinging,
	};

	void AddAnimation(eNinjaStates state, const char* filePath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey = NULL);
	static NinjaAnimations* GetInstance();
	unordered_map<eNinjaStates, Animation*> mAni;

private:
	NinjaAnimations();
	static NinjaAnimations* instance;

};

