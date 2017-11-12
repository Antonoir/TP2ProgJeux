#pragma once
#include "Dessinable.h"

class Enemy;

class Deplaceable : public Dessinable
{
protected:
	Deplaceable(int x, int y, float vitesse);
	bool GetAirborn();
	void ActivateAriborn();
	void MoveLeft();
	void MoveRight();
	void Jump();

	

private:
	short inAirCounter;
	bool isAirborn;
	float vitesse;
};