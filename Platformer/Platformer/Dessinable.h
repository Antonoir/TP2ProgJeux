#pragma once
#include <SFML/Graphics.hpp>
class Tuile;

class Dessinable
{
public:
	sf::Vector2f GetPosition();
	void SetSpawnPosition(sf::Vector2i);
	void Draw(sf::RenderWindow&, sf::Sprite&, const sf::IntRect);
	bool SurfaceCollider(Tuile* tableTuile);

protected:
	Dessinable(int x, int y);
	void Move(int x, int y);

private:
	sf::Vector2f position;
	void AssignSpritePosition(sf::Sprite&);
};