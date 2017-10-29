#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy
{
private:
	Vector2f position;
	const int type;
public:
	Enemy(const float posX, const float posY, const int type);
	~Enemy();
	
	
};