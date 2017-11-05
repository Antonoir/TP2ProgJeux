#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include "Scene.h"
#include "Tuile.h"
#include "Joueur.h"
#include "Game.h"

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
		Tuile* tableTuile[NOMBRE_TUILES_X*NOMBRE_TUILES_Y];

	private:
		Joueur joueur;

		sf::Texture spritesheetTexture;
		sf::Sprite spritesheet;
		blocType getType(int codeType);

		int interfaceCommande;
	};
}