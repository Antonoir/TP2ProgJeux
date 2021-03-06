#pragma once
#include <SFML/Graphics.hpp>
#include "deplaceable.h"

class Enemy: public Deplaceable
{
private:
	const int type;
	int posX;
	int posY;
public:
	Enemy(int posX, int posY, const int type);
	~Enemy();
};