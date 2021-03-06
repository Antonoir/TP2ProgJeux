#include "Controleur.h"
#include "SceneModifierCompte.h"

using namespace platformer;

SceneModifierCompte::SceneModifierCompte()
{

}

SceneModifierCompte::~SceneModifierCompte()
{

}

Scene::scenes SceneModifierCompte::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneModifierCompte::init(RenderWindow * const window)
{
	if (!ecranModifierCompteT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranModifierCompte.setTexture(ecranModifierCompteT);

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
	instruction.setString("Entrer un nickname et un mot de passe valide \nEntrer M pour revenir au menu");

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

void SceneModifierCompte::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fen�tre ne mettrait pas n�cessairement 
			//fin � l'application
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
			textboxNickName.selectionner();  //on l'affiche comme �tant s�lectionn�
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis �a fait clean si on fait un nouvel essai)
		}

		else if (textboxPassword.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxName.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxPassword; //Ce textbox devient actif
			textboxPassword.selectionner();  //on l'affiche comme �tant s�lectionn�
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis �a fait clean si on fait un nouvel essai)
		}

		else if (textboxName.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxPassword.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxName; //Ce textbox devient actif
			textboxName.selectionner();  //on l'affiche comme �tant s�lectionn�
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis �a fait clean si on fait un nouvel essai)
		}

		else if (textboxFirstName.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxPassword.deSelectionner();
			textboxName.deSelectionner();
			textboxEmail.deSelectionner();
			textboxActif = &textboxFirstName; //Ce textbox devient actif
			textboxFirstName.selectionner();  //on l'affiche comme �tant s�lectionn�
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis �a fait clean si on fait un nouvel essai)
		}

		else if (textboxEmail.touche(Mouse::getPosition(*mainWin)))
		{
			textboxNickName.deSelectionner();
			textboxPassword.deSelectionner();
			textboxName.deSelectionner();
			textboxFirstName.deSelectionner();
			textboxActif = &textboxEmail; //Ce textbox devient actif
			textboxEmail.selectionner();  //on l'affiche comme �tant s�lectionn�
			textboxErreur.insererTexte(""); //on efface le message d'erreur (optionnel, amis �a fait clean si on fait un nouvel essai)
		}

		else
		{
			//Sinon aucun textbox actif
			//Ce else devrait �tre dans toutes vos fen�tres o� il n'y a pas de textbox.
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
			transitionVersScene = Controleur::getInstance()->requeteChangementScene();
		}

		if (event.type == Event::KeyPressed && textboxActif != nullptr)
		{
			//ON VA SE SERVIR DE ENTER PARTOUT DANS LE TP POUR VALIDER LES INFOS DANS TOUS
			//LES TEXTBOX D'UNE SC�NE (Vous pouviez vous codez un bouton si �a vous amuse,
			//Mais vous pouvez aussi garder les choses simples.
			if (event.key.code == Keyboard::Return)
			{
				enterActif = true; //Pour s'assurer que enter n'est pas saisie comme caract�re
				isRunning = false;
				if (!Controleur::getInstance()->requeteUserName(textboxNickName,textboxPassword) && Controleur::getInstance()->requeteNickNameCompte(textboxNickName) && Controleur::getInstance()->requetePasswordCompte(textboxPassword))
				{
					transitionVersScene = Scene::scenes::MODIFIER;
				}

				else if(Controleur::getInstance()->requeteModifCompte(textboxNickName, textboxPassword, textboxName, textboxFirstName, textboxEmail))
				{
					compteValide = true;
					transitionVersScene = Scene::scenes::MODIFINFO;
					
				}

			}
			else if (event.key.code == Keyboard::BackSpace)
			{
				textboxActif->retirerChar();
				backspaceActif = true;  //Pour s'assurer que backspace n'est pas saisie comme caract�re
			}
		}

		//Attention : TextEntered est diff�rent de KeyPressed
		//Voir ici pour l'explication: https://www.sfml-dev.org/tutorials/2.4/window-events-fr.php
		if (!backspaceActif && !enterActif && textboxActif != nullptr && (event.type == Event::TextEntered))
		{
			if (event.text.unicode < 128) //Travailler en unicode n'est pas simple en C++; on peut vivre avec du simple
			{                             //ascii pour ce tp (libre � vous d'aller plus loin si vous voulez)
				textboxActif->ajouterChar((char)event.text.unicode);
			}
		}
	}

	enterActif = false;
	backspaceActif = false;
}

void SceneModifierCompte::update()
{

}

void SceneModifierCompte::draw()
{
	mainWin->clear();
	mainWin->draw(ecranModifierCompte);
	mainWin->draw(instruction);
	mainWin->draw(nickname);
	mainWin->draw(password);
	if (compteValide)
	{
		mainWin->draw(name);
		mainWin->draw(firstname);
		mainWin->draw(email);
		textboxName.dessiner(mainWin);
		textboxFirstName.dessiner(mainWin);
		textboxEmail.dessiner(mainWin);
	}
	
	textboxNickName.dessiner(mainWin);
	textboxPassword.dessiner(mainWin);
	textboxErreur.dessiner(mainWin);
	mainWin->display();
}