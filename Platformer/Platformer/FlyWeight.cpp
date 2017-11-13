#include "FlyWeight.h"

FlyWeight::FlyWeight()
{
	if(terrainTexture.loadFromFile("Assets\\Sprites\\.png"))
		terrainTextureSprite.setTexture(terrainTexture);
	if (enemyTexture.loadFromFile("Assets\\Sprites\\.png"))
		enemyTextureSprite.setTexture(enemyTexture);
	if (joueurTexture.loadFromFile("Assets\\Sprites\\.png"))
		joueurTextureSprite.setTexture(joueurTexture);
	if (collectibleTexture.loadFromFile("Assets\\Sprites\\.png"))
		collectibleTextureSprite.setTexture(collectibleTexture);
}