#pragma once
#include <SFML/Graphics.hpp>

class FlyWeight
{
public:
	FlyWeight();
	sf::Sprite& GetTerrainSprite();
	sf::Sprite& GetEnemySprite();
	sf::Sprite& GetJoueurSprite();
	sf::Sprite& GetCollectibleSprite();
private:
	sf::Texture terrainTexture;
	sf::Texture enemyTexture;
	sf::Texture joueurTexture;
	sf::Texture collectibleTexture;
	sf::Sprite terrainSprite;
	sf::Sprite enemySprite;
	sf::Sprite joueurSprite;
	sf::Sprite collectibleSprite;
};