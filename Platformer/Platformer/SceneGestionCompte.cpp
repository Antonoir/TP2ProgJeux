#include "SceneGestionCompte.h"

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
	textbox.init(480, 24, Vector2f(430, 320), font);
	textboxErreur.initInfo(Vector2f(430, 290), font, true);

	this->mainWin = window;
	isRunning = true;
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(10, 10);
	instruction.setString("1-EffacerCompte 2-CreerCompte \n 3-ModifierCompte 4-RetourMenu");

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
					transitionVersScene = Scene::scenes::EFFACER;
				}
				else if (textbox.getTexte() == "2")
				{
					isRunning = false;
					transitionVersScene = Scene::scenes::CREER;
				}
				else if (textbox.getTexte() == "3")
				{
					isRunning = false;
					transitionVersScene = Scene::scenes::MODIFIER;
				}
				else if (textbox.getTexte() == "4")
				{
					isRunning = false;
					transitionVersScene = Scene::scenes::MENUPRINCIPALE;
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

void SceneGestionCompte::update()
{

}

void SceneGestionCompte::draw()
{
	mainWin->clear();
	mainWin->draw(ecranGestionCompte);
	mainWin->draw(instruction);
	textbox.dessiner(mainWin);
	textboxErreur.dessiner(mainWin);
	mainWin->display();
}