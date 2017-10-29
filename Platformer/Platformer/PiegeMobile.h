#pragma once
#include "Enemy.h"

class PiegeMobile: public Enemy
{
public:
	PiegeMobile(const float posX, const float posY, const int type);
	~PiegeMobile();
private:
	float vitesse;
};