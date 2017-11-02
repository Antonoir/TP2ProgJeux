#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

using namespace sf;

namespace platformer
{
	class SceneGestionCompte : public Scene
	{
	public:
		SceneGestionCompte();
		~SceneGestionCompte();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		Texture ecranGestionCompteT;
		Sprite ecranGestionCompte;

		Font font;
		Text instruction;

		Scene::scenes sceneActive;
		bool backspaceActif = false;
		bool enterActif = false;
	};
}

