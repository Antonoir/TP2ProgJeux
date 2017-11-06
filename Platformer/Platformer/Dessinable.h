#pragma once
#include <SFML/Graphics.hpp>
#include "Tuile.h"

class Dessinable
{
protected:
	Dessinable(int x, int y);
	void Draw(sf::RenderWindow&, sf::Sprite&);
	void Move(int x, int y);
	sf::Vector2f GetPosition();
	const bool SurfaceCollider(Tuile* tableTuile[]); //TODO

private:
	sf::Vector2f position;
	void AssignSpritePosition(sf::Sprite&);
};