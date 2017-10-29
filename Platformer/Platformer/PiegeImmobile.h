#pragma once
#include "Enemy.h"

class PiegeImmobile: public Enemy
{
public:
	PiegeImmobile(const float posX, const float posY, const int type);
	~PiegeImmobile();
};