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

	private:
		Controleur();
		static Controleur *instance;

	};
}