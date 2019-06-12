#pragma once
#include "Object.h"
#include "Debug.h"
#include <vector>
#include <string>
#include "Item.h"
using namespace std;
class Game_UI :
	public Object
{
public:
	Game_UI();
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));
	void Update(float);

	//Cộng điểm thêm một lượng a bất kì 
	void PlusScore(int a);

	//Đếm giờ 
	void MinusTimer();

	//Khới tạo thời gian  
	void InitTimer(int time);

	void DrawItem();
	
	//Cộng, trừ HP của Ninja
	void MinusNinjaHealth();
	void PlusNinjaHealth();
	void ResetHealth();
	
	//Cộng - trừ HP của boss 
	void MinusEnemyHealth();
	void PlusEnemyHealth();

	void setNinjahealth(int a);
	string ConvertTostring(vector<Animation* > vt);
	vector<Animation* > ConvertToVector(string s);

	void setItem(Animation* ani);
	void setStage(int a, int b);
	void setSpirit(int a);
	void setNinja(int a);
	void setScore(long a);
	void setEnemy(int a);
	void setLife(int a);
	static Game_UI* getInstance();

protected:

	
	Animation* UIAni;
	Animation* aniItem;

	vector<Animation*> Healths;
	vector<Animation*> baseNumber;


	vector<Animation* > score;
	vector<Animation*> timer;
	vector<Animation*> stage;
	vector<Animation*> spirit;
	vector<Animation*> ninja;
	vector<Animation*> enemy;
	vector<Animation*> life;
	static Game_UI* _instance; 
};

