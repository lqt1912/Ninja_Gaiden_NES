
#include "Star.h"
class WindmillStar :
	public Star
{
public:
	WindmillStar();
	~WindmillStar();
	void Update(float dt, vector<Object*> handleObject, Grid* grid);
	bool rightToLeft;
	float s;
	D3DXVECTOR2 temp;
};
