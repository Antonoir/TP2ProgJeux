#pragma once
#include "Enemy.h"

class SpaceInvaders: public Enemy
{
public:
	SpaceInvaders(int posX, int posY, const int type);
	~SpaceInvaders();
	void tirer();
	void Update();
private:
	float vitesse;
	bool canShoot = false;
};