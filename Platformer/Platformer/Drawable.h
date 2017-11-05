#pragma once
#include <SFML/Graphics.hpp>
#include "Tuile.h"
#include "Enemy.h"


class Drawable
{
public:
	void Draw(sf::RenderWindow&, sf::Sprite&);
	// useless const sf::Vector2f GetPosition() const;
	const bool SurfaceCollider(Tuile* tableTuile[]);
	const bool EntityCollider(Enemy& enemy);

protected:
	Drawable();
	sf::Vector2f position;
	// movable void SetPosition(int x, int y);
	// movable void Rotate(float);
	void AssignSpritePosition(sf::Sprite&);
};