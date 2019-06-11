#pragma once
#include "Holder.h"
class Bird :
	public Holder
{
public:
	Bird();
	~Bird();
	int getType()
	{
		return BIRD_TYPE;
	}
};

