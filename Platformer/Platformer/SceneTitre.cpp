#include "SceneTitre.h"
#include "Controleur.h"
using namespace platformer;

SceneTitre::SceneTitre()
{
	
}

SceneTitre::~SceneTitre()
{
}

Scene::scenes SceneTitre::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneTitre::init(RenderWindow * const window)
{
	if (!ecranTitreT.loadFromFile("Ressources\\Sprites\\Title.png"))
	{
		return false;
	}

	if (!font.loadFromFile("Ressources\\Fonts\\Peric.ttf"))
	{
		return false;
	}

	ecranTitre.setTexture(ecranTitreT);

	//Les positions sont arbitraires, obtenus par essai et erreur.
	//par rapport au fond d'�cran
	textboxUserName.init(480, 24, Vector2f(430, 320), font);
	textboxPassword.init(480, 24, Vector2f(430, 360), font);

	this->mainWin = window;
	isRunning = true;
	instruction.setFont(font);
	instruction.setColor(Color::White);
	instruction.setPosition(150, 10);
	instruction.setString("M-Retourner au menu principal");

	return true;
}

void SceneTitre::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fen�tre ne mettrait pas n�cessairement 
			//fin � l'application
			isRunning = false;
			transitionVersScene = Scene::scenes::SORTIE;
		}

		//Si on a un �v�nement de click de souris
		if (event.type == Event::MouseButtonPressed)
		{
			//Si on touche � la textbox avec la souris
			if (textboxUserName.touche(Mouse::getPosition(*mainWin)))
			{
				textboxPassword.deSelectionner();
				textboxActif = &textboxUserName; //Ce textbox devient actif
				textboxUserName.selectionner();  //on l'affiche comme �tant s�lectionn�
			}

			else if (textboxPassword.touche(Mouse::getPosition(*mainWin)))
			{
				textboxUserName.deSelectionner();
				textboxActif = &textboxPassword; //Ce textbox devient actif
				textboxPassword.selectionner();  //on l'affiche comme �tant s�lectionn�
			}
			else
			{
				//Sinon aucun textbox actif
				//Ce else devrait �tre dans toutes vos fen�tres o� il n'y a pas de textbox.
				textboxActif = nullptr;
				textboxPassword.deSelectionner();
				textboxUserName.deSelectionner();
			}

		}

		//Un �v�nement de touche de clavier AVEC un textobx actif
		if (event.type == Event::KeyPressed && textboxActif ==nullptr)
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
				if (Controleur::getInstance()->requeteUserName(textboxUserName,textboxPassword))
				{
					transitionVersScene = Scene::scenes::NIVEAU1;
				}
				
				else if(Controleur::getInstance()->requeteUserName(textboxUserName,textboxPassword)==false)
				{
					//On affiche notre erreur.	
					sceneActive = Scene::scenes::TITRE;
					transitionVersScene = sceneActive;
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

	//Dans tous les cas on netoie ces conditions apr�s chaque boucle.
	enterActif = false;
	backspaceActif = false;
}

void SceneTitre::update()
{
}

void SceneTitre::draw()
{
	mainWin->clear();
	mainWin->draw(ecranTitre);
	mainWin->draw(instruction);
	textboxUserName.dessiner(mainWin);
	textboxPassword.dessiner(mainWin);	
	mainWin->display();
}