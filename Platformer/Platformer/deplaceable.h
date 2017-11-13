#pragma once
#include "Dessinable.h"

class Enemy;

class Deplaceable : public Dessinable
{
protected:
	Deplaceable(int x, int y, float vitesse);
	void MoveLeft();
	void MoveRight();

private:
	float vitesse;
};