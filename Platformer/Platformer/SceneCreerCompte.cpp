#include "SceneCreerCompte.h"
#include "Controleur.h"

using namespace platformer;

SceneCreerCompte::SceneCreerCompte()
{

}

SceneCreerCompte::~SceneCreerCompte()
{

}

Scene::scenes SceneCreerCompte::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneCreerCompte::init(RenderWindow * const window)
{
	if (!ecranCreerCompteT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranCreerCompte.setTexture(ecranCreerCompteT);

	textboxNickName.init(480, 24, Vector2f(650, 240), font);
	textboxPassword.init(480, 24, Vector2f(650, 280), font);
	textboxName.init(480, 24, Vector2f(650, 320), font);
	textboxFirstName.init(480, 24, Vector2f(650, 360), font);
	textboxEmail.init(480, 24, Vector2f(650, 400), font);


	this->mainWin = window;
	isRunning = true;
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(150, 10);
	instruction.setString("Entrer un nickname, mot de passe, nom, prenom et email \nEntrer M pour revenir au menu");

	nickname.setFont(font);
	nickname.setColor(Color::White);
	nickname.setPosition(200, 216);
	nickname.setString("nickname");

	password.setFont(font);
	password.setColor(Color::White);
	password.setPosition(200, 256);
	password.setString("password");

	name.setFont(font);
	name.setColor(Color::White);
	name.setPosition(200, 296);
	name.setString("name");

	firstname.setFont(font);
	firstname.setColor(Color::White);
	firstname.setPosition(200, 336);
	firstname.setString("firstname");

	email.setFont(font);
	email.setColor(Color::White);
	email.setPosition(200, 376);
	email.setString("email");

	return true;
}

void SceneCreerCompte::getInputs()
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
			textboxName.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxNickName; //Ce textbox devient actif
			textboxNickName.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else if (textboxPassword.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxName.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxPassword; //Ce textbox devient actif
			textboxPassword.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else if (textboxName.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxPassword.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxName; //Ce textbox devient actif
			textboxName.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else if (textboxFirstName.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxPassword.deSelectionner();
			textboxName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxFirstName; //Ce textbox devient actif
			textboxFirstName.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else if (textboxEmail.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxPassword.deSelectionner();
			textboxName.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxActif = &textboxEmail; //Ce textbox devient actif
			textboxEmail.selectionner();  //on l'affiche comme étant sélectionné
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis ça fait clean si on fait un nouvel essai)
		}

		else
		{
			//Sinon aucun textbox actif
			//Ce else devrait être dans toutes vos fenêtres où il n'y a pas de textbox.
			textboxActif = nullptr;
			textboxPassword.deSelectionner();
			textboxNickName.deSelectionner();
			textboxName.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxEmail.deSelectionner();
		}
		
		if (event.type == Event::KeyPressed && textboxActif == nullptr)
		{
			isRunning = false;
			sceneActive1 = Controleur::getInstance()->requeteChangementScene();
			transitionVersScene = sceneActive1;
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
				if (!Controleur::getInstance()->requeteCreerCompte(textboxNickName,textboxPassword,textboxName, textboxFirstName, textboxEmail))
				{
					sceneActive1 = Scene::scenes::CREER;
					transitionVersScene = sceneActive1;
				}
				else
				{
					transitionVersScene = Scene::scenes::MENUPRINCIPALE;
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

void SceneCreerCompte::update()
{

}

void SceneCreerCompte::draw()
{
	mainWin->clear();
	mainWin->draw(ecranCreerCompte);
	mainWin->draw(instruction);
	mainWin->draw(nickname);
	mainWin->draw(password);
	mainWin->draw(name);
	mainWin->draw(firstname);
	mainWin->draw(email);
	textboxNickName.dessiner(mainWin);
	textboxPassword.dessiner(mainWin);
	textboxName.dessiner(mainWin);
	textboxFirstName.dessiner(mainWin);
	textboxEmail.dessiner(mainWin);
	textboxErreur.dessiner(mainWin);
	mainWin->display();
}



