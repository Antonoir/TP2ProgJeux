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
		delete terrainTuile[i];
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

	if (!SceneNiveau1::Create(3))
		createMapInit = false;
	joueur.SetSpawnPosition(positionEntrance);

	this->mainWin = window;
	isRunning = true;

	return true;
}

void SceneNiveau1::getInputs()
{
	//reset commande joueur
	isSpacePressed = false;
	isLeftPressed = false;
	isRightPressed = false;

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

	//Méthode binaire: appuyer à gauche et à droite sumultanément va donner 3, et le personnage ne se dépalcera alors pas.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		isLeftPressed = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		isRightPressed = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		isSpacePressed = true;
}

void SceneNiveau1::update()
{
	if (isLeftPressed || isRightPressed || isSpacePressed)
		joueur.Update(isSpacePressed, isRightPressed, isLeftPressed);

	joueur.SurfaceCollider(*terrainTuile);
}


void SceneNiveau1::draw()
{
	//draw la map
	mainWin->clear();


	for (int i = 0; i < NOMBRE_TUILES_X*NOMBRE_TUILES_Y; ++i)
		terrainTuile[i]->Draw(*mainWin, sprites.GetTerrainSprite(), terrainTuile[i]->GetIntRect());

	//draw le joueur
	joueur.Draw(*mainWin, sprites.GetJoueurSprite(), joueur.GetIntRect());


	mainWin->display();
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
			if (codeType == 03)
				positionEntrance = Vector2i(ctrPosX, ctrPosY);
			terrainTuile[ctr] = new Tuile(ctrPosX, ctrPosY, getType(codeType));
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
	case 3: return blocType::entrance;
		break;
	case 4: return blocType::lowerFlag;
		break;
	case 5: return blocType::upperFlag;
		break;
	}
}