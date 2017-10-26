#pragma once
#include "Enemy.h"

class UsineEnemy
{
public:
	virtual Enemy* fabriquerEnemy() = 0;
};