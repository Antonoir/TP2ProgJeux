#pragma once
#include <fstream>
#include <sstream>
#include "Scene.h"
#include "Tuile.h"
#include "Joueur.h"
#include "Game.h"
#include "FlyWeight.h"

namespace platformer
{
	class SceneNiveau1 : public Scene
	{
	public:
		SceneNiveau1();
		~SceneNiveau1();



		scenes run();
		bool init(RenderWindow * const window);
		bool Create(int mapNumber);
		void getInputs();
		void update();
		void draw();
		Tuile* terrainTuile[NOMBRE_TUILES_X*NOMBRE_TUILES_Y];

	private:
		FlyWeight sprites;
		sf::Vector2i positionEntrance;
		blocType getType(int codeType);
		Joueur joueur;

		bool createMapInit;
		bool isSpacePressed;
		bool isRightPressed;
		bool isLeftPressed;
	};
}