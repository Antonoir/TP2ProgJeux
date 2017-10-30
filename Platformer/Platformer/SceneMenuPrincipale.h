#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Joueur.h"
#include "Textbox.h"

namespace platformer
{
	class SceneMenuPrincipale : public Scene
	{
	public:
		SceneMenuPrincipale();
		~SceneMenuPrincipale();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		Texture ecranMenuT;
		Sprite ecranMenu;
		Textbox textbox;
		Textbox textboxErreur;
		Font font;

		bool backspaceActif = false;
		bool enterActif = false;

		Textbox* textboxActif = nullptr;
	};
}