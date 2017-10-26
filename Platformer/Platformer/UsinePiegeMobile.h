#pragma once
#include "PiegeMobile.h"
#include "UsineEnemy.h"

class UsinePiegeMobile : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy()
	{
		return new PiegeMobile();
	}
};