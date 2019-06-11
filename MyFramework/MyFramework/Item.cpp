#include "Item.h"

Item::Item()
{
	Tag = Object::eItem;
	existTime = ITEM_EXIST_TIME;
	SetHeight(ITEM_HEIGHT);
	SetWidth(ITEM_WIDTH);
	vy = -ITEM_VX;
	vx = 0;
}
Item::~Item()
{

}
void Item::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	Camera::getInstance()->ConvertFromViewportToWorldport(position);
	ani->SetPosition(position);
	ani->Draw(position);
}

void Item::DetectGround(vector<Object*> listGround)
{
	BoundingBox b;
	for (auto g : listGround)
	{
		b = g->GetBoundingBox();
		b.h = b.h /4;
		if (Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(),b))
		{
			boundGround = g->GetBoundingBox();
			return;
		}
	}
}
void Item::DetectGroundA(vector<BoundingBox> listGround)
{
	BoundingBox b = this->GetBoundingBox();

	for (auto g : listGround)
	{
		g.y -= 8;
		if (Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), g))
		{
			boundGround = g;
			return;
		}
	}
}
void Item::Update(float dt)
{	
	if (Collision::GetInstance()->CollisionAABB(this->GetBoundingBox(), boundGround))
	{
		this->vy = 0;
		this->dy = 0;
	}
	else this->dy = vy * dt;

	existTime -= dt;

	if (existTime <= 0)
	{
		this->isActive = false;
	}
	y += dy;
}
Object::ItemTypes Item::getTypeItem()
{
	return type;
}
BoundingBox Item::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width;
	b.y = this->y + this->height;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width;
	b.h = this->height;
	return b;
}
