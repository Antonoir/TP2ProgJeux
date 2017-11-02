#include "SceneNiveau1.h"
#include <string.h>

using namespace platformer;
using namespace std;

SceneNiveau1::SceneNiveau1()
{
}

SceneNiveau1::~SceneNiveau1()
{
	for (int i = 0; i < NOMBRE_TUILES_X * NOMBRE_TUILES_Y; ++i)
		delete tableTuile[i];
}

Scene::scenes SceneNiveau1::run()
{
	while (isRunning)
	{
		getInputs();
		update();
		draw();
	}

	return transitionVersScene;
}

bool SceneNiveau1::init(RenderWindow * const window)
{

	sf::IntRect visionRect(0, 0, 32, 32);
	if (!spritesheetTexture.loadFromFile("Assets\\Sprites\\spritev1.png"))
		return false;
	spritesheet.setTexture(spritesheetTexture);

	if (!joueur.init(0, window->getSize().x, "Ressources\\Sprites\\Player\\Player.png"))
		return false;

	if (!SceneNiveau1::Create(1))
		return false;

	//Position arbitraire pour le joueur en x, pas arbitraire en y (sur le plancher)
	joueur.setPosition(10, 608);

	this->mainWin = window;
	isRunning = true;

	return true;
}

void SceneNiveau1::getInputs()
{
	while (mainWin->pollEvent(event))
	{
		//x sur la fenêtre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fenêtre ne mettrait pas nécessairement 
			//fin à l'application
			isRunning = false;
			transitionVersScene = Scene::scenes::SORTIE;
		}

		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				isRunning = false;
				transitionVersScene = Scene::scenes::MENUPRINCIPALE;
			}
		}
	}

	interfaceCommande = 0;

	//Méthode binaire: appuyer à gauche et à droite sumultanément va donner 3, et le personnage ne se dépalcera alors pas.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		interfaceCommande |= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		interfaceCommande |= 2;
	}
}

//créer la map à partir d'un fichier texte grace à un talbeau de tuile.
bool SceneNiveau1::Create(int mapNumber)
{
	string path = "Assets\\Maps\\Map" + to_string(mapNumber) + ".txt";
	int ctr = 0;
	int ctrPosX = 0;
	int ctrPosY = 0;

	ifstream map(path);
	if (!map.is_open())
		return false;

	string line;
	while (getline(map, line))
	{
		int codeType;
		stringstream elem(line);

		while (elem >> codeType)
		{
			tableTuile[ctr] = new Tuile(ctrPosX, ctrPosY, getType(codeType));
			ctr++;
			if (ctr % NOMBRE_TUILES_X == 0)
			{
				ctrPosY += TAILLE_TUILES;
				ctrPosX = 0;
			}
			else
				ctrPosX += TAILLE_TUILES;
		}
	}

	return true;
}

//return le type de la tuile selon un nombre
blocType SceneNiveau1::getType(int codeType)
{
	switch (codeType)
	{
	case 0: return blocType::sky;
		break;
	case 1: return blocType::grass;
		break;
	case 2: return blocType::dirt;
		break;
	}
}

void SceneNiveau1::update()
{
	if (interfaceCommande == 1)
	{
		joueur.move(-1);
	}
	else if (interfaceCommande == 2)
	{
		joueur.move(1);
	}
}


//grass  (0,0,32,32)
//sky		(32,0,32,32)
//dirt	(64,0,32,32)
void SceneNiveau1::draw()
{
	mainWin->clear();
	for (int i = 0; i < NOMBRE_TUILES_X*NOMBRE_TUILES_Y; ++i)
	{
		switch (tableTuile[i]->GetType())
		{
		case blocType::sky:
			spritesheet.setTextureRect(IntRect(32, 0, 32, 32));
			spritesheet.setPosition(tableTuile[i]->GetX(), tableTuile[i]->GetY());
			mainWin->draw(spritesheet);
			break;
		case blocType::grass:
			spritesheet.setTextureRect(IntRect(0, 0, 32, 32));
			spritesheet.setPosition(tableTuile[i]->GetX(), tableTuile[i]->GetY());
			mainWin->draw(spritesheet);
			break;
		case blocType::dirt:
			spritesheet.setTextureRect(IntRect(64, 0, 32, 32));
			spritesheet.setPosition(tableTuile[i]->GetX(), tableTuile[i]->GetY());
			mainWin->draw(spritesheet);
			break;
		}
	}

	mainWin->draw(joueur);
	mainWin->display();
}

