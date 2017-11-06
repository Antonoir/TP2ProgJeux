#pragma once
#include "Dessinable.h"
#include "Enemy.h"

class Movable : public Dessinable
{
protected:
	Movable(int x, int y, float vitesse);
	void SetPosition(int x, int y);
	void Rotate(float);
	void jump();
	const bool EntityCollider(Enemy& enemy);
private:
	bool isAirborn;
	float vitesse;
};