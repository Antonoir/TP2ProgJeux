#include "Enemy.h"

Enemy::Enemy(const float posX, const float posY, const int type)
	:type(type)
{
	position.x = posX;
	position.y = posY;
}

Enemy::~Enemy()
{

}
