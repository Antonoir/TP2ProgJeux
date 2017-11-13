#include "SceneNiveau1.h"
#include <string.h>
#include "PiegeMobile.h"
#include "SpaceInvaders.h"

using namespace platformer;
using namespace std;

SceneNiveau1::SceneNiveau1()
{

}

SceneNiveau1::~SceneNiveau1()
{
	for (int i = 0; i < NOMBRE_TUILES_X * NOMBRE_TUILES_Y; ++i)
		delete terrainTuile[i];
	for (int i = 0; i < 4; ++i)
		delete tabEnemy[i];
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
	
	if (!SceneNiveau1::Create(1))
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
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			//Attention, ici simplement fermer la fen�tre ne mettrait pas n�cessairement 
			//fin � l'application
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

	//M�thode binaire: appuyer � gauche et � droite sumultan�ment va donner 3, et le personnage ne se d�palcera alors pas.
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

//cr�er la map � partir d'un fichier texte grace � un talbeau de tuile.
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

bool SceneNiveau1::CreateEnemy()
{
	int i = 0;
	std::ifstream enemy("Assets\\Maps\\EnnemieMap1.txt");
	if (!enemy.is_open())
	{
		return false;
	}
	std::string line;
	while (std::getline(enemy, line))
	{
		int posx;
		int posy;
		int type;
		std::stringstream elem(line);

		elem >> posx >> posy >> type;
		if (type == 0)
		{
			tabEnemy[i] = new PiegeMobile(posx, posy,0);
			i++;
	    }
		if (type == 1)
		{
			tabEnemy[i] = new SpaceInvaders(posx, posy, 1);
		}
		return true;
	}
	return false;
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