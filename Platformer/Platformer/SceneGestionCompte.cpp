#include "SceneGestionCompte.h"
#include "Controleur.h"
using namespace platformer;

SceneGestionCompte::SceneGestionCompte()
{

}

SceneGestionCompte::~SceneGestionCompte()
{

}

SceneGestionCompte::scenes SceneGestionCompte::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneGestionCompte::init(RenderWindow * const window)
{
	if (!ecranGestionCompteT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranGestionCompte.setTexture(ecranGestionCompteT);

	//Les positions sont arbitraires, obtenus par essai et erreur.
	//par rapport au fond d'écran

	this->mainWin = window;
	isRunning = true;
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(10, 10);
	instruction.setString("D-EffacerCompte E-CreerCompte \n F-ModifierCompte M-RetourMenu");

	return true;
}

void SceneGestionCompte::getInputs()
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

void SceneGestionCompte::update()
{

}

void SceneGestionCompte::draw()
{
	mainWin->clear();
	mainWin->draw(ecranGestionCompte);
	mainWin->draw(instruction);
	mainWin->display();
}