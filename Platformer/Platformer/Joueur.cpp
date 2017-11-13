#include "Joueur.h"

using namespace platformer;
using namespace sf;

Joueur::Joueur() :
	Deplaceable(64, 64, 3)//la vraie position est attribuée dans le Init() de la scene.
					 /*la vitesse du joueur du joueur est hardcode car il ne voulait rien savoir d'une constante privée(ne fonctionnait pas apres plusieurs
					 minute des test et un define ne semblait pas fonctionner jai donc préféré respecter l'encaspsulation plutot qu'une constante)*/
{
	//initialisation tableau de IntRect
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			//Dans l'ordre :: marche1 || marche2 || marche3 || marche4 || preparationSaut || DebutSaut || Airborn
			rectTab[i][j] = IntRect(i * 32, j * 32, TAILLE_RECT, TAILLE_RECT);
		}
	}

	//initialiser JumpCharger
	jumpCharger = 0;
	leftCtr = 0;
	rightCtr = 0;
	currentRectPos1 = 0;
	currentRectPos2 = 0;
}

Joueur::~Joueur()
{
}

void Joueur::Update(bool spaceButton, bool rightButton, bool leftButton)
{
	if (spaceButton)
		if (jumpCharger < 60)
			++jumpCharger;

	if (rightButton && !leftButton)
	{
		MoveRight();
		++rightCtr;


		currentRectPos1 = 0;
		if (rightCtr == FRAME_BY_ANIMATION_STEP)
		{
			rightCtr = 0;
			++currentRectPos2;
			if (currentRectPos2 == 4)
				currentRectPos2 = 0;
		}
	}
	else
		rightCtr = 0;

	if (!rightButton && leftButton)
	{
		MoveLeft();
		++leftCtr;
		currentRectPos1 = 1;
		if (leftCtr == FRAME_BY_ANIMATION_STEP)
		{
			leftCtr = 0;
			++currentRectPos2; 
			if(currentRectPos2 == 4)
				currentRectPos2 = 0;
		}
	}
	else
		leftCtr = 0;


	if (!spaceButton && jumpCharger > 0)
	{
		Jump(jumpCharger);
		jumpCharger = 0;
	}
}

void Joueur::Jump(int charged)
{

}


const IntRect Joueur::GetIntRect()
{
	return rectTab[currentRectPos2][currentRectPos1];
}


const bool Joueur::EntityCollider(Vector2f enemyPosition)
{
	float ligneX = GetPosition().x - enemyPosition.x;
	float ligneY = GetPosition().y - enemyPosition.y;

	float distance = sqrt(ligneX * ligneX + ligneY * ligneY);

	if (distance < 2 * RADIUS_32x32)
	{
		return true;
	}
	return false;
}