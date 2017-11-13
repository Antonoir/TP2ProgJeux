#include "Joueur.h"

using namespace platformer;
using namespace sf;

Joueur::Joueur() : Deplaceable(INT16_MAX, INT16_MAX, vitesse)//la vraie position est attribuée dans le Init() de la scene.
{
	persoRect = IntRect(0, 0, TAILLE_RECT, TAILLE_RECT);
}

Joueur::~Joueur()
{
}

IntRect Joueur::GetCurrentRect()
{
	return IntRect(0,0, TAILLE_RECT, TAILLE_RECT);
}

void Joueur::Update(const bool spaceButton, const bool rightButton, const bool leftButton)
{
	//frameCtr++;
}

const bool Joueur::EntityCollider(Vector2f enemyPosition)
{
	float ligneX = GetPosition().x - enemyPosition.x;
	float ligneY = GetPosition().y - enemyPosition.y;

	float distance = sqrt(ligneX * ligneX + ligneY * ligneY);

	if (distance < 2 * radius32x32)
	{
		return true;
	}
	return false;
}