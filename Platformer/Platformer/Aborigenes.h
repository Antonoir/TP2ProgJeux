#pragma once
#include "Enemy.h"

class Aborigenes: public Enemy
{
public:
	Aborigenes(const float posX, const float posY, const int type);
	~Aborigenes();
private:
	float vitesse;
};