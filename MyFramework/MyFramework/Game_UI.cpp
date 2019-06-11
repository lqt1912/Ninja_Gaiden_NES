#include "Game_UI.h"


Game_UI* Game_UI::_instance = NULL;

Game_UI::Game_UI()
{

	UIAni = new Animation("Resources/UI/UI_NinjaGaiden.png", 1,1,1);

	baseNumber.push_back(new Animation("Resources/UI/Number/0.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/1.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/2.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/3.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/4.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/5.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/6.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/7.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/8.png", 1, 1, 1));
	baseNumber.push_back(new Animation("Resources/UI/Number/9.png", 1, 1, 1));

	Healths.push_back (new Animation("Resources/UI/Number/health.png", 1, 1, 1));
	Healths.push_back(new Animation("Resources/UI/Number/die.png", 1, 1, 1));

	for (int i = 0; i < 16; i++)
		enemy.push_back(Healths[0]);
	for (int i = 0; i < 16; i++)
		ninja.push_back(Healths[0]);

	for (int i = 0; i < 6; i++)
		score.push_back(baseNumber[0]);

}



void Game_UI::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	UIAni->Draw(position);

	for (int i = 0; i < 6; i++)
	{
		score[i]->Draw(position + D3DXVECTOR3(i * 11 - 85, -11, 0));
	}

	for (int i = 0; i < 3; i++)
	{
		timer[i]->Draw(position + D3DXVECTOR3(i * 11 - 84, 0, 0));
	}

	for (int i = 0; i < 2; i++)
	{
		stage[i]->Draw(position + D3DXVECTOR3(i * 16 + 40, -11, 0));
	}

	for (int i = 0; i < 16; i++)
	{
		enemy[i]->Draw(position + D3DXVECTOR3(i * 4 + 31, 10, 0));
	}

	for (int i = 0; i < 16; i++)
	{
		ninja[i]->Draw(position + D3DXVECTOR3(i * 4 + 31, 0, 0));
	}
	DrawItem();
	for (int i = 0; i < 2; i++)
	{
		spirit[i]->Draw(position + D3DXVECTOR3(i * 10 -73 , +10, 0));
	}

	for (int i = 0; i < 2; i++)
		life[i]->Draw(position + D3DXVECTOR3(i * 10 - 120, +10, 0));
}

float s1 = 0;
void Game_UI::Update(float dt)
{
	if (s1>= 1.0f)
	{	
		MinusTimer();
		s1 = 0;
	}
	else s1 = s1 + dt ;
}
void Game_UI::MinusNinjaHealth()
{
	int a = 0;
	for (auto i : ninja)
	{
		if (i == Healths[0])
			a++;
	}
	ninja.clear();
	for (int i = 0; i < a - 1; i++)
		ninja.push_back(Healths[0]);
	for (int i = a - 1; i < 16; i++)
		ninja.push_back(Healths[1]);
}

void Game_UI::PlusNinjaHealth()
{

}

void Game_UI::ResetHealth()
{
	for (int i = 0; i < 16; i++)
		ninja.push_back(Healths[0]);
}

void Game_UI::MinusEnemyHealth()
{
	int a = 0;
	for (auto i : enemy)
	{
		if (i == Healths[0])
			a++;
	}
	enemy.clear();
	for (int i = 0; i < a - 1; i++)
		enemy.push_back(Healths[0]);
	for (int i = a - 1; i < 16; i++)
		enemy.push_back(Healths[1]);
}

void Game_UI::PlusEnemyHealth()
{
}
void Game_UI::PlusScore(int a)
{
	string str = ConvertTostring(score);
	for (int i = 0; i < a; i++)
	{
		str.insert(0, "1");
		int intstr = stoi(str);
		intstr++;
		str = to_string(intstr);
		str.erase(0, 1);
	}
	score = ConvertToVector(str);
}




void Game_UI::MinusTimer()
{
	string str = ConvertTostring(timer);
	str.insert(0, "1");
	int intstr = stoi(str);
	intstr--;
	str = to_string(intstr);
	str.erase(0, 1);
	timer = ConvertToVector(str);
}

void Game_UI::InitTimer(int time)
{
	int temp = time;

	int a = temp /100;
	int b = (temp - a * 100) / 10;;
	int c = (temp - b * 10-a*100);
	timer.push_back (baseNumber[a]);
	timer.push_back(baseNumber[b]);
	timer.push_back(baseNumber[c]);
	
	
}

void Game_UI::DrawItem()
{
	if (aniItem)
	{
		/*D3DXVECTOR3 position = D3DXVECTOR3(500, 100, 0);
		Camera::getInstance()->ConvertFromViewportToWorldport(position);*/
		
		aniItem->Draw(D3DXVECTOR3(104, 22,0));
	}
	
}

void Game_UI::setItem(Animation* ani)
{
	aniItem = ani;
}

string Game_UI::ConvertTostring(vector<Animation*> vt)
{
	string s = "";
	for (auto ani:vt)
	{
		for (int i = 0; i < 10; i++)
		{
			if (ani == baseNumber[i])
			{
				char c = i + '0';
				s = s + c;			
			}
		}
	}
	return s;
}

vector<Animation*> Game_UI::ConvertToVector(string s)
{
	vector<Animation*> result;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		int a = c - '0';
		result.push_back(baseNumber[a]);
		
	}
	return result;
}

void Game_UI::setStage(int a, int b)
{
	if (stage.size() > 0)
		stage.clear();
	stage.push_back(baseNumber[a]);
	stage.push_back(baseNumber[b]);
}

void Game_UI::setSpirit(int a)
{
	spirit.clear();
	int temp = a;
	int b = temp / 10;
	int c = temp - b * 10;
	spirit.push_back(baseNumber[b]);
	spirit.push_back(baseNumber[c]);
}

Game_UI* Game_UI::getInstance()
{
	if (!_instance)
		_instance = new Game_UI();
	return _instance;
}

void Game_UI::setNinja(int a)
{
	int temp = a;
	int b = temp / 10;
	int c = temp - b * 10;
	ninja.push_back(baseNumber[b]);
	ninja.push_back(baseNumber[c]);
}
void Game_UI::setScore(long a)
{
	score.clear();
	int temp = a;
	a = 0;
	for (int i = 0; i < 6; i++)
	{
		a = (temp % 10) + a*10;
		temp = temp / 10;
	}
	for (int i = 0; i < 6; i++)
	{
		temp = a % 10;
		a = a / 10;
		score.push_back(baseNumber[temp]);
	}

	//int b = temp / 10;
	//int c = temp - b * 10;
	//score.push_back(baseNumber[b]);
	//score.push_back(baseNumber[c]);
}
void Game_UI::setEnemy(int a)
{
	int temp = a;
	int b = temp / 10;
	int c = temp - b * 10;
	enemy.push_back(baseNumber[b]);
	enemy.push_back(baseNumber[c]);
}

void Game_UI::setLife(int a)
{
	life.clear();
	int temp = a;
	int b = temp / 10;
	int c = temp - b * 10;
	life.push_back(baseNumber[b]);
	life.push_back(baseNumber[c]);
}
