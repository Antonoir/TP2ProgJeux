#pragma once
#include "Enemy.h"

class UsineEnemy
{
public:
	virtual Enemy* fabriquerEnemy(int x, int y, const int type) = 0;
	static enum enemies { MOBILE,INVADERS };
private:
	const float vitessePiegeMobile = 5;
	const float vitesseAborigene = 5;
};