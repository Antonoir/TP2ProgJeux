#pragma once
#include "PiegeMobile.h"
#include "UsineEnemy.h"

class UsinePiegeMobile : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy()
	{
		Enemy* mobile = new PiegeMobile(position.x, position.y, MOBILE);
	}
private:
	Vector2f position;
};