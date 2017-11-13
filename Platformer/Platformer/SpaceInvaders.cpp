#include "SpaceInvaders.h"
#include "Projectile.h"
#include <iostream>
SpaceInvaders::SpaceInvaders(int posX, int posY, const int type)
	:Enemy(posX,posY,type)
{

}
SpaceInvaders::~SpaceInvaders()
{

}

void SpaceInvaders::Update()
{
	if (this->GetPosition().x >= 0 && this->GetPosition().x <= 1280-32)
	{
			MoveLeft();
			if (this->GetPosition().x == 0)
			{
				MoveRight();
			
			}
			if (this->GetPosition().x == 1280)
			{
				MoveLeft();
			}
		
	}	
}

void SpaceInvaders::tirer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		Projectile projectile(this->GetPosition().x, this->GetPosition().y);
		Move(0, vitesse);
	}
}