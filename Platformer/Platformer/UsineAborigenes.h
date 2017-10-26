#pragma once
#include "Aborigenes.h"
#include "UsineEnemy.h"

class UsineAborigenes : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy()
	{
		return new Aborigenes();
	}
};