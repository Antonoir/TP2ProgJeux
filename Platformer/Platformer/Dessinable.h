#pragma once
#include <SFML/Graphics.hpp>
#include "Tuile.h"

class Dessinable
{
protected:
	Dessinable(int x, int y);
	void Draw(sf::RenderWindow&, sf::Sprite&);
	const bool SurfaceCollider(Tuile* tableTuile[]);
private:
	sf::Vector2f position;
};