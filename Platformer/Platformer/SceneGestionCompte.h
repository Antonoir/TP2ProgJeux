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

		Textbox textbox;
		Textbox textboxErreur;
		Font font;
		Text instruction;

		bool backspaceActif = false;
		bool enterActif = false;

		Textbox* textboxActif = nullptr;
	};
}

