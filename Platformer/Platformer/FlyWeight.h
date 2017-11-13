#pragma once
#include <SFML/Graphics.hpp>

class FlyWeight
{
public:
	FlyWeight();
private:
	sf::Texture terrainTexture;
	sf::Texture enemyTexture;
	sf::Texture joueurTexture;
	sf::Texture collectibleTexture;
	sf::Sprite terrainTextureSprite;
	sf::Sprite enemyTextureSprite;
	sf::Sprite joueurTextureSprite;
	sf::Sprite collectibleTextureSprite;
};