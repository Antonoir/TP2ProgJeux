#pragma once
#include <SFML/Graphics.hpp>

enum blocType
{
	sky,
	grass,
};

class Point
{
public:
	Point(int posX, int posY, blocType typet);
	blocType GetType() const;
	int GetX() const;
	int GetY() const;
private:
	sf::Vector2i position;
	blocType type;
};