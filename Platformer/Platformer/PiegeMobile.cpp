#include "PiegeMobile.h"

PiegeMobile::PiegeMobile(int posX,int posY, const int type)
	:Enemy(posX, posY,type)
{

}
PiegeMobile::~PiegeMobile()
{

}

void PiegeMobile::Update()
{
	if (this->GetPosition().x >= 0 && this->GetPosition().x <= 1280-32)
	{
		MoveLeft();
		if (this->GetPosition().x == this->GetPosition().x-100)
		{
			MoveRight();
		}
		if (this->GetPosition().x == this->GetPosition().x+100)
		{
			MoveLeft();
		}

	}
}