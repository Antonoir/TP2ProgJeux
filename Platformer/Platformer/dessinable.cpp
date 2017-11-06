#include "Dessinable.h"

using namespace sf;

Dessinable::Dessinable(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Dessinable::Draw(RenderWindow& window, Sprite& sprite)
{
	AssignSpritePosition(sprite);
	window.draw(sprite);
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

const bool Dessinable::SurfaceCollider(Tuile* tableTuile[])
{
	return false;
}