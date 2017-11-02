#include "SceneMenuPrincipale.h"
#include "Controleur.h"
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

	this->mainWin = window;
	isRunning = true;
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(25, 10);
	instruction.setString("A-LogIn B-Gestion de Compte C-Meilleur Scores");
	return true;
}

void SceneMenuPrincipale::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			isRunning = false;
			transitionVersScene = Scene::scenes::SORTIE;
		}


		if (event.type == Event::KeyPressed)
		{
			isRunning = false;
			sceneActive = Controleur::getInstance()->requeteChangementScene();
			transitionVersScene = sceneActive;
		}
	}
}

void SceneMenuPrincipale::update()
{

}

void SceneMenuPrincipale::draw()
{
	mainWin->clear();
	mainWin->draw(ecranMenu);
	mainWin->draw(instruction);
	mainWin->display();
}