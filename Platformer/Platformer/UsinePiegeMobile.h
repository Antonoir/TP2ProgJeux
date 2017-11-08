#pragma once
#include "PiegeMobile.h"
#include "UsineEnemy.h"

class UsinePiegeMobile : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy(int x, int y, const int type)
	{
		Enemy* mobile = new PiegeMobile(x,y,MOBILE);
	}
	
};