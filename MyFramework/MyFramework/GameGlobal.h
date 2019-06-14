#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <Windows.h>
#include <map>
#include "Debug.h"

#define GAME_FPS 60
#define SCREEN_WIDTH 250
#define SCREEN_HEIGHT 208
#define KEYBOARD_BUFFER_SIZE 1024

#define CELL_WIDTH 125
#define CELL_HEIGHT 104
#define TILE_WIDTH 16
#define TILE_HEIGHT 16

//==== NINJA PARAMETER====

#define NO_COLLISION_TIME 0.6f
//Ninja Health 
#define MAX_NINJA_HEALTH 16
#define MAX_NINJA_SOULS 3
#define NINJA_HITPOINT_PER_COLLIDED 1

//Ninja run
#define NINJA_RUNNING_SPEED 60.0f

//Ninja jump
#define NINJA_JUMP_VX 45.0f
#define NINJA_JUMP_HEIGHT 180.0f
#define NINJA_ACE_X 6.0f
#define NINJA_ACE_Y 6.0f

//Ninja Injure
#define NINJA_INJURING_SPEED_X 80.0f
#define NINJA_INJURING_SPEED_Y 100.0f

//Ninja Climb
#define NINJA_CLIMBING_SPEED 40.0f


//=== Item ===
#define ITEM_HEIGHT 20
#define ITEM_WIDTH 16
#define ITEM_EXIST_TIME 5
#define ITEM_VX 20

#define STAR_LIMIT_SPIRIT 3
#define WINDMILLSTAR_LIMIT_SPIRIT 5
#define FIREWHEEL_LIMIT_SPIRIT 5

#define SPIRIT_BLUE 5
#define SPIRIT_RED 10
#define BONUS_RED 1000
#define BONUS_BLUE 500
#define BONUS_PHYSICAL 6

//===HOLDER & ENEMIES===

#define BAT_TYPE 1
#define BIRD2_TYPE 2
#define BUTTERFLY_TYPE 3
#define BROWN_KNIFE_TYPE 4
#define GREEN_GUN_TYPE 5
#define PINK_WALK_TYPE 6
#define LEOPARD_TYPE 7
#define BIRD_TYPE 8
#define GREEN_BAZOOKA_TYPE 9
#define GREEN_WALK_TYPE 10
#define BROWN_BOSS_TYPE 11

#define HOLDER_WIDTH 16
#define HOLDER_HEIGHT 16
#define ENEMY_WIDTH 32
#define ENEMY_HEIGHT 32
#define BOSS_WIDTH 32
#define BOSS_HEIGHT 48

#define BROWN_KNIFE_SPEED 20.0f

#define GREENGUN_SPEED 10.0f
#define BULLET_PER_TIME 3

#define GREENWALK_SPEED 100.0f
#define PINKWALK_SPEED 20.0f

#define LEOPARD_SPEED 90.0f
#define DISTANCE_APPEAR 70
#define FROZEN_TIME 5

#define BIRD_SPEED 50;

#define CHECKPOINT_1 2100
#define CHECKPOINT_2 3100

#define SCORE_1 100
#define SCORE_2 200
#define SCORE_3 300
#define BULLET_BOSS_SCORE 100
#define BOSS_SCORE 2000

#define BULLET_WIDTH 10
#define BUllET_HEIGHT 12

#define BULLET_BAZOOKA_SPEED 80
#define BULLET_BOSS_SPEED 80

#define DEFAULT_DAMAGE 1
#define BAZOOKA_BULLET_DAMAGE 2

extern bool isFrozenEnemies;
extern float frozenTime;
extern bool isWin;
class GameGlobal
{
 public:
	GameGlobal();
	~GameGlobal();
	static HINSTANCE getHINSTANCE();
	static HWND getHWND();

	static void setHINSTANCE(HINSTANCE h);
	static void setHWND(HWND hwnd);

	static LPD3DXSPRITE getSpriteHandler();
	static void setSpriteHandler(LPD3DXSPRITE sprite);

	static LPDIRECT3DDEVICE9 getDevice();
	static void setDevice(LPDIRECT3DDEVICE9 device);


	static void setWidth(int width);
	static int getWidth();

	static void setHeight(int height);
	static int getHeight();

	static LPDIRECT3DSURFACE9 backSurface;

	static bool isRunning;
private:

	static HINSTANCE hInstance;
	static HWND hWnd;
	static LPD3DXSPRITE spriteHandler;
	static int screenwidth, screenheight;
	static LPDIRECT3DDEVICE9 d3ddv;

};

