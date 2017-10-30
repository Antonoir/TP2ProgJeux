#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Point.h"

class Map
{
public:
	Map();
	~Map();
	bool Create(int mapNumber);
	void Draw(sf::RenderWindow &mainWin);
private:
	blocType getType(int codeType);
	sf::RectangleShape blueSquare;
	sf::RectangleShape greenSquare;
	Point* pointTable[1125];
};