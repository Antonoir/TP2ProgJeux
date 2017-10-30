#include "SceneMenuPrincipale.h"

using namespace platformer;
SceneMenuPrincipale::SceneMenuPrincipale()
{

}

SceneMenuPrincipale::~SceneMenuPrincipale()
{

}

Scene::scenes SceneMenuPrincipale::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneMenuPrincipale::init(RenderWindow * const window)
{
	if (!ecranMenuT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranMenu.setTexture(ecranMenuT);
	
	textbox.init(480, 24, Vector2f(430, 320), font);
	textboxErreur.initInfo(Vector2f(430, 290), font, true);

	this->mainWin = window;
	isRunning = true;

	return true;
}
