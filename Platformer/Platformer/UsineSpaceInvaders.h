#pragma once
#include "SpaceInvaders.h"
#include "UsineEnemy.h"

class UsineSpaceInvaders : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy(int x, int y, const int type)
	{
		Enemy* aborigenes = new SpaceInvaders(x, y, INVADERS);
	}
};