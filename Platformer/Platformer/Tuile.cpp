#include "Tuile.h"

using namespace sf;

Tuile::Tuile(int posX, int posY, blocType typet)
{
	position.x = posX;
	position.y = posY;
	type = typet;
}

blocType Tuile::GetType() const
{
	return type;
}

int Tuile::GetX() const
{
	return position.x;
}

int Tuile::GetY() const
{
	return position.y;
}