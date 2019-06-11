#pragma once
#include "Holder.h"

class Butterfly : public Holder
{
public:
	Butterfly();
	~Butterfly();
	int getType()
	{
		return BUTTERFLY_TYPE;
	}
};

