#include "deplaceable.h"

Deplaceable::Deplaceable(int x, int y, float vitesse)
	: Dessinable(x, y)
	, vitesse(vitesse)
{
}

void Deplaceable::ActivateAriborn()
{
	isAirborn = true;
	inAirCounter = 0;
}

bool Deplaceable::GetAirborn()
{
	if (isAirborn)
		return true;
	return false;
}

void Deplaceable::MoveLeft()
{
	Move(-vitesse, 0);
}

void Deplaceable::MoveRight()
{
	Move(vitesse, 0);
}

//effectue l'action de sauter vérifier si isAirborn est on avant
//de call
void Deplaceable::Jump()
{	
	if (inAirCounter < 60)
		Move(0, -vitesse*.5f); //MODIFIER NE PEUT (RESET LA POSITION NE LINCRÉMENTE PAS)
	else if (inAirCounter < 120)
		Move(0, vitesse*.5f);
	else
	{
		isAirborn = false;
		inAirCounter = -1;
	}
	++inAirCounter;
}

