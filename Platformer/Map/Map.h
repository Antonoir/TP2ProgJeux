#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map();
	void Create(int mapNumber);
	void Draw(sf::RenderWindow mainWin);
private:
	sf::Texture spriteSheetTexture;
	sf::Sprite spriteSheet;
};