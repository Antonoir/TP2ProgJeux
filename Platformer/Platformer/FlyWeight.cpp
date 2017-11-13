#include "FlyWeight.h"

using namespace sf;

FlyWeight::FlyWeight()
{
	if (terrainTexture.loadFromFile("Assets\\Sprites\\Terrain.png"))
		terrainSprite.setTexture(terrainTexture);
	if (enemyTexture.loadFromFile("Assets\\Sprites\\Enemy.png"))
		enemySprite.setTexture(enemyTexture);
	if (joueurTexture.loadFromFile("Assets\\Sprites\\Joueur.png"))
		joueurSprite.setTexture(joueurTexture);
	if (collectibleTexture.loadFromFile("Assets\\Sprites\\Collectible.png"))
		collectibleSprite.setTexture(collectibleTexture);
}

Sprite& FlyWeight::GetTerrainSprite()
{
	return terrainSprite;
}
Sprite& FlyWeight::GetEnemySprite()
{
	return enemySprite;
}
Sprite& FlyWeight::GetJoueurSprite()
{
	return joueurSprite;
}
Sprite& FlyWeight::GetCollectibleSprite()
{
	return collectibleSprite;
}