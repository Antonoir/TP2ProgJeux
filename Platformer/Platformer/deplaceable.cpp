#include "deplaceable.h"

Deplaceable::Deplaceable(int x, int y, float vitesse)
	: Dessinable(x, y)
	, vitesse(vitesse)
{
}

void Deplaceable::MoveLeft()
{
	Move(-vitesse, 0);
}

void Deplaceable::MoveRight()
{
	Move(vitesse, 0);
}

