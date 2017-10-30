#include "Point.h"

using namespace sf;

Point::Point(int posX, int posY, blocType typet)
{
	position.x = posX;
	position.y = posY;
	type = typet;
}

blocType Point::GetType() const
{
	return type;
}

int Point::GetX() const
{
	return position.x;
}

int Point::GetY() const
{
	return position.y;
}