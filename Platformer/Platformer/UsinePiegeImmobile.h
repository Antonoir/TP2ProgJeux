#pragma once
#include "UsineEnemy.h"
#include "PiegeImmobile.h"

class UsinePiegeImmobile : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy()
	{
		Enemy* immobile = new PiegeImmobile(position.x, position.y, IMMOBILE);
	}
private:
	Vector2f position;
};