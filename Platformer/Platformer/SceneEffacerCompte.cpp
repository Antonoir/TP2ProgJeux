#include "SceneEffacerCompte.h"
#include "Controleur.h"

using namespace platformer;

SceneEffacerCompte::SceneEffacerCompte()
{

}

SceneEffacerCompte::~SceneEffacerCompte()
{

}

Scene::scenes SceneEffacerCompte::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneEffacerCompte::init(RenderWindow * const window)
{
	if (!ecranEffacerCompteT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranEffacerCompte.setTexture(ecranEffacerCompteT);

	textboxNickName.init(480, 24, Vector2f(650, 240), font);
	textboxPassword.init(480, 24, Vector2f(650, 280), font);

	this->mainWin = window;
	isRunning = true;
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(150, 10);
	instruction.setString("Entrer un nickname et un mot de passe valide \nEntrer M pour revenir au menu");

	nickname.setFont(font);
	nickname.setColor(Color::White);
	nickname.setPosition(200, 216);
	nickname.setString("nickname");

	password.setFont(font);
	password.setColor(Color::White);
	password.setPosition(200, 256);
	password.setString("password");

	return true;
	//test
}

void SceneEffacerCompte::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fenêtre ne mettrait pas nécessairement 
			//fin à l'application
			isRunning = false;
			transitionVersScene = Scene::scenes::SORTIE;
		}

		if (textboxNickName.touche(Mouse::getPosition(*mainWin)))
		{
			textboxPassword.deSelectionner();
			textboxActif = &textboxNickName; //Ce textbox devient actif
			textboxNickName.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else if (textboxPassword.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxActif = &textboxPassword; //Ce textbox devient actif
			textboxPassword.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else
		{
			//Sinon aucun textbox actif
			//Ce else devrait être dans toutes vos fenêtres où il n'y a pas de textbox.
			textboxActif = nullptr;
			textboxPassword.deSelectionner();
			textboxNickName.deSelectionner();
		}

		if (event.type == Event::KeyPressed && textboxActif == nullptr)
		{
			isRunning = false;
			sceneActive = Controleur::getInstance()->requeteChangementScene();
			transitionVersScene = sceneActive;
		}

		if (event.type == Event::KeyPressed && textboxActif != nullptr)
		{
			//ON VA SE SERVIR DE ENTER PARTOUT DANS LE TP POUR VALIDER LES INFOS DANS TOUS
			//LES TEXTBOX D'UNE SCÈNE (Vous pouviez vous codez un bouton si ça vous amuse,
			//Mais vous pouvez aussi garder les choses simples.
			if (event.key.code == Keyboard::Return)
			{
				enterActif = true; //Pour s'assurer que enter n'est pas saisie comme caractère
				isRunning = false;
				if (Controleur::getInstance()->requeteUserName(textboxNickName,textboxPassword) && Controleur::getInstance()->requeteNickNameCompte(textboxNickName) && Controleur::getInstance()->requetePasswordCompte(textboxPassword))
				{
					infoValide = true;
					Controleur::getInstance()->requeteSupprimerCompte(textboxNickName, textboxPassword);
					transitionVersScene = Scene::scenes::MENUPRINCIPALE;
				}

				else
				{
					//On affiche notre erreur.
					transitionVersScene = Scene::scenes::MENUPRINCIPALE;
					textboxErreur.insererTexte("Mauvais nickname ou mot de passe entrez-en un bon!");
				}

			}
			else if (event.key.code == Keyboard::BackSpace)
			{
				textboxActif->retirerChar();
				backspaceActif = true;  //Pour s'assurer que backspace n'est pas saisie comme caractère
			}
		}

		//Attention : TextEntered est différent de KeyPressed
		//Voir ici pour l'explication: https://www.sfml-dev.org/tutorials/2.4/window-events-fr.php
		if (!backspaceActif && !enterActif && textboxActif != nullptr && (event.type == Event::TextEntered))
		{
			if (event.text.unicode < 128) //Travailler en unicode n'est pas simple en C++; on peut vivre avec du simple
			{                             //ascii pour ce tp (libre à vous d'aller plus loin si vous voulez)
				textboxActif->ajouterChar((char)event.text.unicode);
			}
		}
	}

	enterActif = false;
	backspaceActif = false;
}

void SceneEffacerCompte::update()
{

}

void SceneEffacerCompte::draw()
{
	mainWin->clear();
	mainWin->draw(ecranEffacerCompte);
	mainWin->draw(instruction);
	mainWin->draw(nickname);
	mainWin->draw(password);
	textboxNickName.dessiner(mainWin);
	textboxPassword.dessiner(mainWin);
	textboxErreur.dessiner(mainWin);
	mainWin->display();
}