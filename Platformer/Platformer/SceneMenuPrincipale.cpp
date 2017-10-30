#include "SceneMenuPrincipale.h"

using namespace platformer;
SceneMenuPrincipale::SceneMenuPrincipale()
{

}

SceneMenuPrincipale::~SceneMenuPrincipale()
{

}

SceneMenuPrincipale::scenes SceneMenuPrincipale::run()
{
	while(isRunning)
	{
		getInputs();
		update();
		draw();
	}
	return transitionVersScene;
}

bool SceneMenuPrincipale::init(RenderWindow * const window)
{
	if (ecranMenuT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	ecranMenu.setTexture(ecranMenuT);

	this->mainWin = window;
	isRunning = true;
	return true;
}