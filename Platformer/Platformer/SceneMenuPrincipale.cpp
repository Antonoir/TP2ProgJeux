#include "SceneMenuPrincipale.h"

using namespace platformer;
SceneMenuPrincipale::SceneMenuPrincipale()
{

}
//Test
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
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(25, 10);
	instruction.setString("1-LogIn 2-Gestion de Compte 3-Meilleur Scores");
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

		if (event.type == Event::MouseButtonPressed)
		{

			if (textbox.touche(Mouse::getPosition(*mainWin)))
			{
				textboxActif = &textbox;
				textbox.selectionner();
				textboxErreur.insererTexte("");
			}
			else
			{
				textboxActif = nullptr;
				textbox.deSelectionner();
			}

		}

		if (event.type == Event::KeyPressed && textboxActif != nullptr)
		{

			if (event.key.code == Keyboard::Return)
			{
				enterActif = true;

				if (textbox.getTexte() == "1")
				{
					isRunning = false;
					transitionVersScene = Scene::scenes::TITRE;
				}
				else if (textbox.getTexte() == "2")
				{
					isRunning = false;
					transitionVersScene = Scene::scenes::GESTIONCOMPTE;
				}
				else if (textbox.getTexte() == "3")
				{
					isRunning = false;
					transitionVersScene = Scene::scenes::SCORE;
				}
				else
				{
					//On affiche notre erreur.
					textboxErreur.insererTexte("Operation impossible, entrez un index possible");
				}
			}
			else if (event.key.code == Keyboard::BackSpace)
			{
				textboxActif->retirerChar();
				backspaceActif = true;  //Pour s'assurer que backspace n'est pas saisie comme caractère
			}
		}
			if (!backspaceActif && !enterActif && textboxActif != nullptr && (event.type == Event::TextEntered))
			{
				if (event.text.unicode < 128) //Travailler en unicode n'est pas simple en C++; on peut vivre avec du simple
				{                             //ascii pour ce tp (libre à vous d'aller plus loin si vous voulez)
					textboxActif->ajouterChar((char)event.text.unicode);
				}
			}
		enterActif = false;
		backspaceActif = false;
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
	textbox.dessiner(mainWin);
	textboxErreur.dessiner(mainWin);
	mainWin->display();
}