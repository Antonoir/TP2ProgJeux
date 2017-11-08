#pragma once
#include "Enemy.h"

class PiegeMobile: public Enemy
{
public:
	PiegeMobile(int posX, int posY, const int type);
	~PiegeMobile();
};