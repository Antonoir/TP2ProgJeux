#pragma once
#include "Aborigenes.h"
#include "UsineEnemy.h"

class UsineAborigenes : public UsineEnemy
{
public:
	Enemy* fabriquerEnemy()
	{
		Enemy* aborigenes = new Aborigenes(position.x, position.y, ABORIGENES);
	}
private:
	Vector2f position;
};