#pragma once
#include "Scene.h"
#include <string>
#include "Textbox.h"
namespace platformer
{
	class Controleur
	{
	public:
		static Controleur *getInstance();
		static void release();
		Scene::scenes requeteChangementScene();
		bool requeteUserName(Textbox username);
		bool requetePassword(Textbox password);
		bool requeteNickNameCompte(Textbox nickname);
		bool requetePasswordCompte(Textbox password);
		bool requeteNameCompte(Textbox name);
		bool requeteFirstNameCompte(Textbox firstname);
		bool requeteEmailCompte(Textbox email);

	private:
		Controleur();
		static Controleur *instance;

	};
}