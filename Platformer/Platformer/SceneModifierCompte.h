#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Textbox.h"

using namespace sf;

namespace platformer
{
	class SceneModifierCompte : public Scene
	{
	public:
		SceneModifierCompte();
		~SceneModifierCompte();

		scenes run();
		bool init(RenderWindow * const window);
		void getInputs();
		void update();
		void draw();

	private:
		Texture ecranModifierCompteT;
		Sprite ecranModifierCompte;

		Font font;
		Text instruction;
		Text nickname;
		Text password;
		Text name;
		Text firstname;
		Text email;

		Scene::scenes sceneActive;
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