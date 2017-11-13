#include "Tuile.h"

using namespace sf;

Tuile::Tuile(int posX, int posY, blocType typet) :Dessinable(posX, posY)
{
	type = typet;
}

blocType Tuile::GetType()
{
	return type;
}

IntRect Tuile::GetIntRect() const
{
	switch (type)
	{
	case blocType::sky:
		return IntRect(32, 0, 32, 32);
	case blocType::grass:
		return IntRect(0, 0, 32, 32);
	case blocType::dirt:
		return IntRect(64, 0, 32, 32);
	case blocType::entrance:
		return IntRect(0, 32, 32, 32);
	case blocType::lowerFlag:
		return IntRect(64, 32, 32, 32);
	case blocType::upperFlag:
		return IntRect(32, 32, 32, 32);
	}
}