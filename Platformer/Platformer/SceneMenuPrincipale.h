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
		Scene::scenes sceneActive;
		Texture ecranMenuT;
		Sprite ecranMenu;
		Font font;
		Text instruction;
	};
}