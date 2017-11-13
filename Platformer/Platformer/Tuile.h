#pragma once
#include "Dessinable.h"

enum blocType
{
	sky,
	grass,
	dirt,
	entrance,
	lowerFlag,
	upperFlag,
};

class Tuile : public Dessinable
{
public:
	Tuile(int posX, int posY, blocType typet);
	blocType GetType();
	sf::IntRect GetIntRect() const;
private:
	blocType type;
};