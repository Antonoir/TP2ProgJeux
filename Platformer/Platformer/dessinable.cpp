#include "Dessinable.h"
#include <math.h>
#include "Tuile.h"

using namespace sf;

Dessinable::Dessinable(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Dessinable::Draw(RenderWindow& window, Sprite& sprite, IntRect rect)
{
	AssignSpritePosition(sprite);
	sprite.setTextureRect(rect);
	window.draw(sprite);
}

void Dessinable::SetSpawnPosition(Vector2i spawnPos)
{
	position.x = spawnPos.x;
	position.y = spawnPos.y;
}

void Dessinable::Move(int x, int y)
{
	position.x += x;
	position.y += y;
}

void Dessinable::AssignSpritePosition(Sprite& sprite)
{
	sprite.setPosition(position);
}

sf::Vector2f Dessinable::GetPosition()
{
	return position;
}


//à l'origine elle aurais du servir à plus que seulement le joueur ici la raison de son placement dans dessonable
//lutilisation de constante aurait été souhaitable
//un fichier txt expliquant la méthode est fournis
bool Dessinable::SurfaceCollider(Tuile* tableTuile)
{
	int coloneMinimum = floor(position.x / 32);
	int coloneMaximum = coloneMinimum + 1;
	int ligneMinimum = floor(position.y / 32);
	int ligneMaximum = ligneMinimum + 1;

	//en Haut à gauche si entre en contact change ma position
	if (tableTuile[40 * ligneMinimum + coloneMinimum].GetType() == blocType::dirt || tableTuile[40 * ligneMinimum + coloneMinimum].GetType() == blocType::grass)
	{
		if (tableTuile[40 * ligneMinimum + coloneMinimum].GetPosition().x + 32 > position.x)
			Move(tableTuile[40 * ligneMinimum + coloneMinimum].GetPosition().x + 32 - position.x, 0);
		if (tableTuile[40 * ligneMinimum + coloneMinimum].GetPosition().y + 32 > position.y)
			Move(0, tableTuile[40 * ligneMinimum + coloneMinimum].GetPosition().y + 32 - position.y);
	}
	//en Haut à droite
	if (tableTuile[40 * ligneMinimum + coloneMaximum].GetType() == blocType::dirt || tableTuile[40 * ligneMinimum + coloneMaximum].GetType() == blocType::grass)
	{
		if(tableTuile[40 * ligneMinimum + coloneMaximum].GetPosition().x < position.x)
			Move(tableTuile[40 * ligneMinimum + coloneMaximum].GetPosition().x - position.x, 0);
		if(tableTuile[40 * ligneMinimum + coloneMaximum].GetPosition().y + 32 > position.y)
			Move(0, tableTuile[40 * ligneMinimum + coloneMaximum].GetPosition().y + 32 - position.y);
	}
	//en Bas à gauche
	if (tableTuile[40 * ligneMaximum + coloneMinimum].GetType() == blocType::dirt || tableTuile[40 * ligneMaximum + coloneMinimum].GetType() == blocType::grass)
	{
		if(tableTuile[40 * ligneMaximum + coloneMinimum].GetPosition().x+32 > position.x)
			Move(tableTuile[40 * ligneMaximum + coloneMinimum].GetPosition().x - 32 - position.x, 0);
		if(tableTuile[40 * ligneMaximum + coloneMinimum].GetPosition().y < position.y)
			Move(0, tableTuile[40 * ligneMaximum + coloneMinimum].GetPosition().y - position.y);
	}
	//en Bas à drette
	if (tableTuile[40 * ligneMaximum + coloneMaximum].GetType() == blocType::dirt || tableTuile[40 * ligneMaximum + coloneMaximum].GetType() == blocType::grass)
	{
		if(tableTuile[40 * ligneMaximum + coloneMaximum].GetPosition().x < position.x)
			Move(tableTuile[40 * ligneMaximum + coloneMaximum].GetPosition().x - position.x, 0);
		if(tableTuile[40 * ligneMaximum + coloneMaximum].GetPosition().y < position.y)
			Move(0, tableTuile[40 * ligneMaximum + coloneMaximum].GetPosition().y - position.y);
	}
	return false;
}