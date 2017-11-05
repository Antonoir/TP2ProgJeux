#include "Controleur.h"
#include <string>
namespace platformer
{
	Controleur *Controleur::instance = nullptr;

	Controleur::Controleur()
	{

	}

	Controleur* Controleur::getInstance()
	{
		if (!instance)
			instance = new Controleur();
		return instance;
	}

	void Controleur::release()
	{
		delete instance;
		instance = nullptr;
	}

	Scene::scenes Controleur::requeteChangementScene()
	{
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			return Scene::scenes::TITRE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::B))
		{
			return Scene::scenes::GESTIONCOMPTE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::C))
		{
			return Scene::scenes::SCORE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::M))
		{
			return Scene::scenes::MENUPRINCIPALE;
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			return Scene::scenes::EFFACER;
		}
		else if (Keyboard::isKeyPressed(Keyboard::E))
		{
			return Scene::scenes::CREER;
		}
		else if (Keyboard::isKeyPressed(Keyboard::F))
		{
			return Scene::scenes::MODIFIER;
		}
	}
	
	bool Controleur::requeteUserName(Textbox username)
	{
		bool valide = false;
		if (username.getTexte() == "antoine")
		{
			valide = true;
		}
		return valide;
	}
	
	bool Controleur::requetePassword(Textbox password)
	{
		bool valide = false;
		if (password.getTexte() == "password")
		{
			valide = true;
		}
		return valide;
	}

	bool Controleur::requeteNickNameCompte(Textbox nickname)
	{
		bool valide = false;
		return valide;
	}

	bool Controleur::requetePasswordCompte(Textbox password)
	{
		bool valide = false;
		return valide;
	}

	bool Controleur::requeteNameCompte(Textbox name)
	{
		bool valide = false;
		return valide;
	}

	bool Controleur::requeteFirstNameCompte(Textbox firstname)
	{
		bool valide = false;
		return valide;
	}

	bool Controleur::requeteEmailCompte(Textbox email)
	{
		bool valide = false;
		return valide;
	}
}