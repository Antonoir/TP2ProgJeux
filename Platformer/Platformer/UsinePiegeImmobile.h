#pragma once
#include "UsineEnemy.h"
#include "PiegeImmobile.h"

class UsinePiegeImmobile : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy()
	{
		return new PiegeImmobile();
	}
};