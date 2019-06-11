#include "Collision.h"


Collision* Collision::instance = NULL;
Collision* Collision::GetInstance()
{
	if (instance == NULL)
		instance = new Collision();
	return instance;
}
Collision::Collision()
{
}


Collision::~Collision()
{
}
bool Collision::isCollision(RECT rect1, RECT rect2)
{

	if (rect1.left > rect2.right || rect1.right < rect2.left || rect1.top < rect2.bottom || rect1.bottom > rect2.top)
	{
		return false;
	}
	return true;
}
bool Collision::CollisionAABB(BoundingBox b1, BoundingBox b2)
{
	return !(b1.x + b1.w < b2.x || b1.x > b2.x + b2.w || b1.y + b1.h < b2.y || b1.y > b2.y + b2.h);
}

Object::ResultCollision Collision::CollisionSweptAABB(BoundingBox b1, BoundingBox b2)
{
	//DebugOut(L"b1 %f %f %f %f %f %f \n", b1.x, b1.y, b1.h, b1.w, b1.vx, b1.vy);
	//DebugOut(L"b2 %f %f %f %f %f %f \n", b2.x, b2.y, b2.h, b2.w, b2.vx, b2.vy);

	//=============Khoi tao gia tri mac dinh la khong va cham===========
	Object::ResultCollision r;
	r.isCollision = false;
	r.t = 1;
	r.nx = r.ny = 0;

	vx = (b1.vx - b2.vx);
	vy =( b1.vy - b2.vy);

	//==================broadphase======================================
	BoundingBox btemp;
	btemp.x = b1.vx > 0 ? b1.x : b1.x + b1.vx;
	btemp.y = b1.vy > 0 ? b1.y : b1.y + b1.vy;
	btemp.w = b1.vx > 0 ? b1.vx + b1.w : b1.w - b1.vx;
	btemp.h = b1.vy > 0 ? b1.vy + b1.h : b1.h - b1.vy;

	if (!CollisionAABB(btemp, b2))
	{
		return r;
	}

	//==================quang duong va cham va ket thuc

	if (vx > 0.0f)
	{
		xInvEntry = b2.x - (b1.x + b1.w);
		xInvExit = (b2.x + b2.w) - b1.x;
	}
	else
	{
		xInvEntry = (b2.x + b2.w) - b1.x;
		xInvExit = b2.x - (b1.x + b1.w);
	}

	//Theo y
	if (vy > 0.0f)
	{
		yInvEntry = b2.y - (b1.y + b1.h);
		yInvExit = (b2.y + b2.h) - b1.y;
	}
	else
	{
		yInvEntry = (b2.y + b2.h) - b1.y;
		yInvExit = b2.y - (b1.y + b1.h);
	}

	//===========Xác định thời gian va chạm==============================
	//Theo x
	if (vx == 0.0f)
	{
		//Trường hợp vận tốc = 0 thì các giá trị vô cực ( không va chạm )
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		//Khoảng thời gian bắt đầu va chạm theo x
		xEntry = xInvEntry / (vx);
		//Khoảng thời gian kết thúc va chạm
		xExit = xInvExit / (vx);
	}

	//Theo y
	if (vy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / (vy);
		yExit = yInvExit / (vy);
	}

	//Tính thời gian bắt đầu va chạm và kết thúc va chạm
	entryTime = max(xEntry, yEntry);
	exitTime = min(xExit, yExit);

	//Nếu không có va chạm
	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		return r;
	}
	else
	{

		//DebugOut(L"%f %f %f %f \n \n ", entryTime, exitTime, xEntry, yEntry);
		r.isCollision = true;
		r.t = entryTime;


		if (xEntry > yEntry)
		{
			r.ny = 0.0f;
			if (xInvEntry > 0)
			{
				r.nx = -1.0f;
				r.side = Object::Right;
			}
			else
			{
				r.nx = 1.0f;
				r.side = Object::Left;
			}
		}
		else
		{
			r.nx = 0.0f;
			if (yInvEntry > 0)
			{
				r.ny = -1.0f;
				r.side = Object::Top;
			}
			else
			{
				r.side = Object::Bottom;
				r.ny = 1.0f;
			}
		}
		// Trả về thời gian bắt đầu va chạm
		//DebugOut(L"Time %f", r.t);
		return r;
	}
}