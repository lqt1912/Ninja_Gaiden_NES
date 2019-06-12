#include "Holder.h"



Holder::Holder()
{
	Tag = Object::eHolder;
	SetWidth(HOLDER_WIDTH);
	SetHeight(HOLDER_HEIGHT);
}


Holder::~Holder()
{
}
void Holder::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	Camera::getInstance()->ConvertFromViewportToWorldport(position);
	currentAni->SetPosition(position);
	currentAni->Draw(position);
}
void Holder::Update(float dt)
{
	if(isFrozenEnemies==false)
		currentAni->Update(dt);
}
void Holder::setFlipVertical(bool isFlip)
{
	this->currentAni->FlipVertical(isFlip);
}

BoundingBox Holder::GetBoundingBox()
{
	BoundingBox b;
	b.x = this->x - this->width;
	b.y = this->y + this->height/2 ;
	b.vx = this->dx;
	b.vy = this->dy;
	b.w = this->width;
	b.h = this->height;
	return b;
}

void Holder::setItemType(int i)
{
	itemType = ItemTypes(i);
}
Object::ItemTypes Holder::getItemType()
{
	return itemType;
}