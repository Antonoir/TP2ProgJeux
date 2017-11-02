#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include "Scene.h"
#include "Tuile.h"
#include "Joueur.h"

using namespace sf;

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

	private:
		static const int NOMBRE_TUILES_X = 40;
		static const int NOMBRE_TUILES_Y = 25;
		static const int TAILLE_TUILES = 32;
		Joueur joueur;

		sf::Texture spritesheetTexture;
		sf::Sprite spritesheet;
		blocType getType(int codeType);
		Tuile* tableTuile[NOMBRE_TUILES_X*NOMBRE_TUILES_Y];

		int interfaceCommande;
	};
}