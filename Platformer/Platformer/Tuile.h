#pragma once
#include <SFML/Graphics.hpp>

enum blocType
{
	sky,
	grass,
	dirt,
};

class Tuile
{
public:
	Tuile(int posX, int posY, blocType typet);
	blocType GetType() const;
	int GetX() const;
	int GetY() const;
private:
	sf::Vector2i position;
	blocType type;
};