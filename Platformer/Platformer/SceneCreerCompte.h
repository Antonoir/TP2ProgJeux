#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

using namespace sf;

namespace platformer
{
	class SceneCreerCompte : public Scene
	{
	public:
		SceneCreerCompte();
		~SceneCreerCompte();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		Texture ecranCreerCompteT;
		Sprite ecranCreerCompte;
		Font font;
		Text instruction;
		Text nickname;
		Text password;
		Text name;
		Text firstname;
		Text email;

		Scene::scenes sceneActive1;
		Textbox textboxNickName;
		Textbox textboxPassword;
		Textbox textboxName;
		Textbox textboxFirstName;
		Textbox textboxEmail;
		Textbox textboxErreur;

		bool backspaceActif = false;
		bool enterActif = false;
		bool compteValide = false;

		Textbox* textboxActif = nullptr;
	};
}