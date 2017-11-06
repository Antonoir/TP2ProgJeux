#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

using namespace sf;

namespace platformer
{
	class SceneEffacerCompte : public Scene
	{
	public:
		SceneEffacerCompte();
		~SceneEffacerCompte();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		Texture ecranEffacerCompteT;
		Sprite ecranEffacerCompte;
		Font font;
		Text instruction;
		Text nickname;
		Text password;

		Scene::scenes sceneActive;
		Textbox textboxNickName;
		Textbox textboxPassword;
		Textbox textboxErreur;


		bool backspaceActif = false;
		bool enterActif = false;
		bool infoValide = false;

		Textbox* textboxActif = nullptr;
	};
}