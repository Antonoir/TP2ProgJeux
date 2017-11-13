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
		void requeteModifCompte(Textbox username, Textbox password, Textbox name, Textbox firstname, Textbox email);
		bool requeteUserName(Textbox username, Textbox password);
		bool requeteNickNameCompte(Textbox nickname);
		void requeteSupprimerCompte(Textbox username, Textbox password);
		bool requetePasswordCompte(Textbox password);
		bool requeteNameCompte(Textbox name);
		bool requeteEmailCompte(Textbox email);
		bool requeteCreerCompte(const Textbox& textusername, const Textbox& textpassword, const Textbox& textfirstname, const Textbox& textlastname, const Textbox& textemail);

	private:
		Controleur();
		static Controleur *instance;

	};
}