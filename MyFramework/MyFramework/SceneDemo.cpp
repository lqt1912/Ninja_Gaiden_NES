#include "SceneDemo.h"
#include "SceneManager.h"
#include "Scene_3_2.h"
#include "BrownBoss.h"
#include "BulletBoss.h"
#include "GameSound.h"
SceneDemo::SceneDemo(int level)
{
	currentLevel = level;
	GameWin = new Animation("Resources/UI/GameWin.png", 1, 1, 1);
	GameOver = new Animation("Resources/UI/GameOver.png", 1, 1, 1);
	timer = 300;
	mCamera = Camera::getInstance();
	//Game's parameters
	mTimeCounter = 0x0;
	backcolor = 0x999;

	//Ninja's instance call
	ninja = Ninja::GetInstance();
	ninja->SetPosition((D3DXVECTOR3(100, 200, 0)));

	grid = new Grid();
	//Load map with level 

#pragma region  SoundLoad
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Background_Sound_3_1.wav", "Sound_3_1");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Background_Sound_3_2.wav", "Sound_3_2");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Background_Sound_3_3.wav", "Sound_3_3");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Ninja_Attack.wav", "ninja_attack");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Ninja_Collided_Anemy.wav", "ninja_collided_enemy");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Enemy_Destroy.wav", "enemy_destroy");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Ninja_Jump.wav", "ninja_jump");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/bossdie.wav", "Boss_Die");
	Sound::getInstance()->loadSound((char*)"Resources/Sound/Ninja_Pick_Item.wav", "Pick_Item");
#pragma endregion  SoundLoad

	switch (level)
	{
	case 1:
		{
			map = new TiledMap("Resources/Map/3_1.txt");
			map->LoadTileSet("Resources/Map/3_1.png");
			map->SetCamera(Camera::getInstance());
			Sound::getInstance()->play("Sound_3_1", true, 0);
			Sound::getInstance()->setVolume(90.0f,"Sound_3_1");

			grid->InitEnemiesObject("Resources/Enemy1/Enemies_3_1.txt");
			grid->InitGroundObjectA_3_2("Resources/Ground/game_ground_3_1.txt");
			break;
		}
	case 2:
		{
			map = new TiledMap("Resources/Map/3_2.txt");
			map->LoadTileSet("Resources/Map/3_2.png");
			map->SetCamera(Camera::getInstance());

			Sound::getInstance()->stop("Sound_3_1");
			Sound::getInstance()->play("Sound_3_2", true, 0);
			Sound::getInstance()->setVolume(90.0f, "Sound_3_2");
			grid->InitEnemiesObject("Resources/Enemy1/Enemies_3_2.txt");
			grid->InitGroundObjectA_3_2("Resources/Ground/game_ground_3_2.txt");
			break;
		}
	case 3:
	{
		map = new TiledMap("Resources/Map/3_3.txt");
		map->LoadTileSet("Resources/Map/3_3.png");
		map->SetCamera(Camera::getInstance());

		Sound::getInstance()->stop("Sound_3_2");
		Sound::getInstance()->play("Sound_3_3", true, 0);
		Sound::getInstance()->setVolume(90.0f, "Sound_3_3");
		grid->InitEnemiesObject("Resources/Enemy1/Enemies_3_3.txt");
		grid->InitGroundObjectA_3_2("Resources/Ground/game_ground_3_3.txt");
		break;
	}
	}

	gui = Game_UI::getInstance();
	gui->InitTimer(timer);
	gui->setStage(3, level);
	gui->setLife(ninja->life);
	gui->setSpirit(ninja->spirit);
}

SceneDemo::~SceneDemo()
{
	if(grid)
		delete grid;	
}
float s1 = 0;
void SceneDemo::Update(float dt)
{

	if(s1 >= 1.0f)
	{
		timer--;
		gui->InitTimer(timer);
		s1 = 0;
	}
	else s1 = s1 + dt;

	if (isFrozenEnemies)
	{
		if (frozenTime > 0)
			frozenTime -= dt;
		else
		{
			frozenTime = FROZEN_TIME;
			isFrozenEnemies = false;
		}
	}

	if (ninja->getY() < 0)
		grid->ResetGrid(); //reset item

	// get list object isactive
	lstColiableObject = grid->getHandlingObjectA(mCamera);

	for (auto obj : grid->getBaseEnemiesList())
	{
		if (obj->getObjectType() == Object::eItem)
		{
			auto i = (Item*)obj;
			i->DetectGroundA(grid->lstGroundA);
		}
		else if (obj->type == LEOPARD_TYPE)
		{
			auto l = (LeoPard*)obj;
			l->OnCollisionWithGroundA(grid->lstGroundA);
		}
		else if (obj->type == GREEN_WALK_TYPE)
		{
			auto l = (EnemyGreenWalk*)obj;
			l->OnCollisionWithGroundA(grid->lstGroundA);
		}
	}

	// weapon update
	this->UpdateWeapon(dt);

	// check ground 
	if (grid->lstGroundA.size() > 0)
		if (ninja->GetVy() <= 0 && ninja->GetState() != NinjaAnimations::Idling)
			ninja->OnCollisionWithGroundA(grid->lstGroundA);

	if (grid->lstWall.size() > 0)
		if (ninja->GetState() == NinjaAnimations::Jumping || ninja->GetState() == NinjaAnimations::Falling)
			ninja->OnCollisionWithWall(grid->lstWall);
		else if (ninja->GetState() == NinjaAnimations::Injuring && !ninja->isOnWall)
			ninja->OnCollisionWithWall(grid->lstWall);

	if (grid->lstLadder.size() > 0)
		if (ninja->GetState() == NinjaAnimations::Jumping || ninja->GetState() == NinjaAnimations::Falling || ninja->GetState() == NinjaAnimations::Running)
			ninja->OnCollisionWithLadder(grid->lstLadder);
		else if (ninja->GetState() == NinjaAnimations::Injuring && !ninja->isOnWall)
			ninja->OnCollisionWithLadder(grid->lstLadder);

	//Handle keyboard's events
	this->ninja->HandleKeyboard(keys);

	//Ninja update 
	this->ninja->Update(dt, lstColiableObject);
	//ninja->Update(dt);

	//Left-bound and Right-bound of camera
	int right = (int)map->getWidth() - GameGlobal::getWidth() / 2;
	int left = (int)GameGlobal::getWidth() / 2;

	//Camera moving toward ninja
	if (ninja->GetPosition().x > left && ninja->GetPosition().x < right)
		Camera::getInstance()->setX(ninja->GetPosition().x - left);

	//Ninja executing at 2 bounds
	if (ninja->getX() < 0)
		ninja->setX(0);
	if (ninja->getX() > map->getWidth())
		ninja->setX(map->getWidth());

	//Grid update
	if (ninja->physical <= 0 || ninja->GetPosition().y < 10)
	{
		if (isFrozenEnemies == true)
			isFrozenEnemies = false;
		grid->ResetGrid();
	}
	else 
		grid->UpdateA(dt, Camera::getInstance());

	// ui update
	gui->setScore(ninja->score);
	gui->setSpirit(ninja->spirit);
	gui->Update(dt);
	gui->setNinjahealth(ninja->physical);
	gui->setLife(ninja->life);

	//Reset khi Physical còn 0, trừ 1 life, physical tăng lại 16
	if (ninja->physical <= 0 || ninja->GetPosition().y < 10)
	{
		isFrozenEnemies = false;
		ninja->physical = 16;
		ninja->life--;
		ninja->Reset();
		for (auto e : grid->getBaseEnemiesList())
			e->Reset(e->getInitPosition());
		mCamera->SetPosition(0, 208);
	}

	switch (currentLevel)
	{
	case 1:
	{
		if (ninja->getX() +80> CHECKPOINT_1)
		{
		

			delete map;
			
			SceneDemo* scene = new SceneDemo(2);
			SceneManager::GetInstance()->ReplaceScene(scene);
			Camera::getInstance()->SetPosition(0, 208);
			Ninja::GetInstance()->SetVx(0);
			Ninja::GetInstance()->SetPosition(50, 100);
		}
		break;
	}
	case 2:
	{
		if (ninja->getX() +80> CHECKPOINT_2)
		{
			SceneDemo* scene = new SceneDemo(3);
			SceneManager::GetInstance()->ReplaceScene(scene);
			Camera::getInstance()->SetPosition(0, 208);
			Ninja::GetInstance()->SetVx(0);
			Ninja::GetInstance()->SetPosition(50, 100);
		}
		break;
	}
	}
}


void SceneDemo::Draw()
{

	//Translate vector
	D3DXVECTOR2 trans = D3DXVECTOR2((int)(-Camera::getInstance()->GetPosition().x), 0);


	//Background rendering
	map->Render();

	//Game's UI rendering
	gui->Draw(D3DXVECTOR3(145, 16, 0));
	//Weapon rendering

	if (knife != NULL)
		GameDebugDraw::getInstance()->DrawRect(knife->GetBound(), mCamera);

	//Ninja rendering 
	ninja->Draw(ninja->GetPosition());
	//GameDebugDraw::getInstance()->DrawRect(ninja->GetBound(), mCamera);


	for (auto e : lstWeaponEnemy)
	{

		if (e->getActive())
		{
			e->Draw(e->GetPosition());
		}
		else
		{
			e = nullptr;
		}
	}
	//Grid rendering
	grid->RenderA(trans, mCamera);



	for (auto a : grid->lstGroundA)
		GameDebugDraw::getInstance()->DrawRect(BoxToRect(a), mCamera);

	if (weapon && ninja->getSpirit() + weapon->limitSpirit >= weapon->limitSpirit)
		weapon->Draw(weapon->GetPosition());



	//Endgame
	if (ninja->life <= 0 || timer <= 0)
	{
		timer = 300;
		GameOver->Draw(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));
			switch (currentLevel)
			{
			case 1:
			{
				Sound::getInstance()->stop("Sound_3_1");
				break;
			}
			case 2:
			{
				Sound::getInstance()->stop("Sound_3_2");
				break;
			}
			case 3:
			{
				Sound::getInstance()->stop("Sound_3_3");
				
				break;
			}
		}
	}
	if (isWin)
	{
		GameWin->Draw(D3DXVECTOR3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));
		Sound::getInstance()->stop("Boss_Die");
	}


}
void SceneDemo::OnKeyDown(int KeyCode)
{
	keys[KeyCode] = true;
	ninja->OnKeyPressed(KeyCode);
	if (KeyCode == DIK_F)
	{
		isFrozenEnemies = true;
		frozenTime = 2000;
	}
}

void SceneDemo::OnKeyUp(int KeyCode)
{

	keys[KeyCode] = false;
	ninja->OnKeyUp(KeyCode);

}


bool SceneDemo::isCollision(RECT rect1, RECT rect2)
{
	if (rect1.left > rect2.right || rect1.right < rect2.left || rect1.top < rect2.bottom || rect1.bottom > rect2.top)
	{
		return false;
	}
	return true;
}


void SceneDemo::UpdateWeapon(float dt)
{
	for (auto obj : grid->getBaseEnemiesList())
	{
		if (obj->getObjectType() == Object::eItem)
		{
			auto i = (Item*)obj;
			i->DetectGroundA(grid->lstGroundA);
		}
		else
		{
			switch (obj->type)
			{

			case PINK_WALK_TYPE:
			{
				auto e = (EnemyPinkWalk*)obj;
				if (e->isAttacking && isFrozenEnemies ==false)
				{
					e->isAttacking = false;
					auto swordOfPink = new SwordOfPink();

					swordOfPink->SetPosition(e->GetPosition());
					swordOfPink->limitY = swordOfPink->GetPosition().y + 50;

					if (obj->IsFlipVertical() == true)
						swordOfPink->SetVx(-(abs(ninja->GetPosition().x - obj->GetPosition().x)) + 15);
					else if (obj->IsFlipVertical() == false)
						swordOfPink->SetVx((abs(ninja->GetPosition().x - obj->GetPosition().x)) - 15);

					lstWeaponEnemy.insert(swordOfPink);
				}
				break;
			}
			case GREEN_GUN_TYPE:
			{
				auto e = (EnemyGreenGun*)obj;
				if (e->isAttacking && isFrozenEnemies ==false)
				{
					e->isAttacking = false;
					for (int i = 1; i <= BULLET_PER_TIME; i++)
					{
						auto bullet = new Bullet();
						if (ninja->GetPosition().x - obj->GetPosition().x < 0)
						{
							bullet->setFlipVertical(false);
							bullet->SetPosition(e->GetPosition().x - i * 6, e->GetPosition().y + 5);
							bullet->SetVx(-i * 4);
						}
						else
						{
							bullet->setFlipVertical(true);
							bullet->SetPosition(e->GetPosition().x + i * 6, e->GetPosition().y + 5);
							bullet->SetVx((i * 4));
						}
						lstWeaponEnemy.insert(bullet);
					}
				}
				break;
			}
			case GREEN_BAZOOKA_TYPE:
			{
				auto e = (EnemyGreenBazooka*)obj;
				if (e->isAttacking && isFrozenEnemies == false)
				{
					e->isAttacking = false;

					auto bullet = new BulletBazooka();
					if (ninja->GetPosition().x - obj->GetPosition().x < 0)
					{
						bullet->setFlipVertical(true);
						bullet->SetPosition(e->GetPosition().x - 10, e->GetPosition().y + 6);
						bullet->SetVx(-BULLET_BAZOOKA_SPEED);
					}
					else
					{
						bullet->SetVx(BULLET_BAZOOKA_SPEED);
						bullet->setFlipVertical(false);
						bullet->SetPosition(e->GetPosition().x + 10, e->GetPosition().y + 6);
					}
					lstWeaponEnemy.insert(bullet);

				}
				break;
			}

			case 11:
			{

				auto e = (BrownBoss*)obj;
				if (e->isAttacking && isFrozenEnemies == false)
				{
					e->isAttacking = false;
					for (int i = 1; i <= 3; i++)
					{
						auto bullet = new BulletBoss();
						if (obj->IsFlipVertical())
						{
							bullet->setFlipVertical(true);
							bullet->SetPosition(e->GetPosition().x - i * 3, e->GetPosition().y + i * 20 - 30);
							bullet->SetVx(BULLET_BOSS_SPEED);
						}
						else
						{
							bullet->setFlipVertical(false);
							bullet->SetPosition(e->GetPosition().x + i * 3, e->GetPosition().y + i * 20 - 30);
							bullet->SetVx((-BULLET_BOSS_SPEED));
						}
						lstWeaponEnemy.insert(bullet);
					}
				}
			}
			}
		}
	}

	for (auto e : lstWeaponEnemy)
	{
		if (!e->isActive)
			e = nullptr;
		else
			e->Update(dt);

		if (e!=NULL)
			lstColiableObject.push_back(e);
	}
	// knife weapon
	if (this->ninja->isAttacking)
	{
		if (knife == NULL)
			knife = new Knife();
	}

	if (knife!=NULL)
	{
		if (!ninja->isAttacking)
		{
			if (knife->flag)
			{
				for (auto e : lstColiableObject)
					if (e->getType() == BROWN_BOSS_TYPE)
					{
						auto b = (BrownBoss*)e;
						if(b->blood > 0)
							b->MinusBlood();
					}
				knife->flag = false;
			}
			knife = NULL;
		}
		else
			knife->Update(dt, lstColiableObject, grid);
	}
	// other weapon 

	if (ninja->spirit > 2 && this->ninja->isDarting && weapon == NULL)
	{
		switch (ninja->specialWeapon)
		{
		case Object::eStar:
			weapon = new Star();
			break;
		case Object::eWindStar:
			weapon = new WindmillStar();
			break;
		case Object::eFireWheel:
			weapon = new FireWheel();
			break;
		case Object::NoneWeapon:
			weapon = NULL;
			break;
		default:
			break;
		}
		if (weapon)
		{
			ninja->AddSpirit(-weapon->limitSpirit);
			this->ninja->isDarting = false;
			weapon->SetPosition(ninja->GetPosition());
		}
	}
	if (weapon && ninja->spirit + weapon->limitSpirit >= weapon->limitSpirit)
	{
		weapon->Update(dt, lstColiableObject, grid);
		if (!weapon->isActive)
			weapon = NULL;
	}
}