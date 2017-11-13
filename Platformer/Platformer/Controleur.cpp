#include "Controleur.h"
#include <string>
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <fstream>

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
		else
		{
			return Scene::scenes::MENUPRINCIPALE;
		}
	}
	void Controleur::requeteSupprimerCompte(Textbox username, Textbox password)
	{
		std::ifstream user("Assets\\Account\\User.txt");
		if (!user.is_open())
		{
			//on fait rien
		}
		std::string line;
		while (std::getline(user, line))
		{
			std::string usernamestr;
			std::string passwordstr;
			std::string namestr;
			std::string firstnamestr;
			std::string emailstr;
			std::stringstream elem(line);
			if (username.getTexte() == usernamestr && password.getTexte() == passwordstr)
			{
				line.erase();
			}
		}
	}
	bool Controleur::requeteModifCompte(Textbox username,Textbox password, Textbox name, Textbox firstname, Textbox email)
	{
		std::ifstream user("Assets\\Account\\User.txt");
		if (!user.is_open())
		{
			//on fait rien
		}
		std::string line;
		while (std::getline(user, line))
		{
			std::string usernamestr;
			std::string passwordstr;
			std::stringstream elem(line);
			if (username.getTexte() == usernamestr && password.getTexte() == passwordstr)
			{
				return true;
			}
		}
	}
	void Controleur::requeteModifInfoCompte(Textbox& name, Textbox& firstname, Textbox& email)
	{
		std::ifstream user("Assets\\Account\\User.txt");
		if (!user.is_open())
		{
			//on fait rien
		}
		std::string line;
		while (std::getline(user, line))
		{
			std::string namestr;
			std::string firstnamestr;
			std::string emailstr;
			std::stringstream elem(line);

			name.insererTexte(namestr);
			firstname.insererTexte(firstnamestr);
			email.insererTexte(emailstr);
		}

	}
	bool Controleur::requeteUserName(Textbox username,Textbox password)
	{
		std::ifstream user("Assets\\Account\\User.txt");
		if (!user.is_open())
		{
			return false;
		}
		std::string line;
		while(std::getline(user,line))
		{
			std::string usernamestr;
			std::string passwordstr;
			std::stringstream elem(line);
			
			elem >> usernamestr >> passwordstr;
			if (username.getTexte() == usernamestr && password.getTexte() == passwordstr)
			{
				return true;
			}

		}

		return false;
	}

	bool Controleur::requeteNickNameCompte(Textbox nickname)
	{
		bool valide = false;
		if (nickname.getTexte().getSize() >= 3 && nickname.getTexte().getSize() <= 25)
		{
			valide = true;
		}
		return valide;
	}

	bool Controleur::requetePasswordCompte(Textbox password)
	{
		bool contientNombre = false;
		bool contientMinuscule = false;
		bool contientMajuscule = false;
		bool contientSpecialChar = false;
		bool valide = false;
		if ((password.getTexte().getSize() >= 5 && password.getTexte().getSize() <= 15))
		{
			for (int i = 0; i < password.getTexte().getSize(); ++i)
			{
				if (isdigit(password.getTexte()[i]))
				{
					contientNombre = true;
				}
			}
			if (contientNombre)
			{
				for (int i = 0; i < password.getTexte().getSize(); ++i)
				{
					if (islower(password.getTexte()[i]))
					{
						contientMinuscule = true;
					}
				}

				if (contientNombre && contientMinuscule)
				{
					for (int i = 0; i < password.getTexte().getSize(); ++i)
					{
						if (isupper(password.getTexte()[i]))
						{
							contientMajuscule = true;
						}
					}

					if (contientNombre && contientMinuscule && contientMajuscule)
					{
						for (int i = 0; i < password.getTexte().getSize(); ++i)
						{
							if (!isalnum(password.getTexte()[i]))
							{
								contientSpecialChar = true;
							}
						}

						if (contientNombre && contientMinuscule && contientMajuscule && contientSpecialChar)
						{
							valide = true;
						}
					}
				}
			}

		}
		return valide;
	}

	bool Controleur::requeteNameCompte(Textbox name)
	{
		bool valide = false;
		if (name.getTexte().getSize() >= 2 && name.getTexte().getSize() <= 25)
		{
			for (int i = 0; i < name.getTexte().getSize(); ++i)
			{
				if (isalpha(name.getTexte()[i]) || name.getTexte()[i]=='.' || name.getTexte()[i]=='-')
				{
					valide = true;
				}
				else if (!isalpha(name.getTexte()[i]) || name.getTexte()[i]!='.' || name.getTexte()[i]!='-')
				{
					valide = false;		
				}
			}
		}
		return valide;
	}

	bool Controleur::requeteEmailCompte(Textbox email)
	{
		bool valide = false;
		bool contientArobas = false;
		int compteurArobas = 0;
		for (int i = 0; i < email.getTexte().getSize(); ++i)
		{
			if (isalnum(email.getTexte()[i]) || email.getTexte()[i] == '_' || email.getTexte()[i] == '-' || email.getTexte()[i] == '.' || email.getTexte()[i] == '@')
			{
				if (email.getTexte()[i] == '@')
				{
					compteurArobas++;
					if (compteurArobas == 1)
					{
						contientArobas = true;
					}
					else if (compteurArobas != 1)
					{
						contientArobas = false;
					}
				}
			}
		}
		if (contientArobas)
		{
			for (int i = 0; i < email.getTexte().getSize(); ++i)
			{
				if (email.getTexte()[i] == '.')
				{
					if (email.getTexte().getSize() - i >= 2 && email.getTexte().getSize() - i <= 4)
					{
						valide = true;
					}
				}
			}
		}
		return valide;
	}
	bool Controleur::requeteCreerCompte(const Textbox& textusername, const Textbox& textpassword, const Textbox& textfirstname, const Textbox& textlastname, const Textbox& textemail)
	{
		std::ofstream userWrite("Assets\\Account\\User.txt", std::ios::app);
		std::ifstream userRead("Assets\\Account\\User.txt");
		if (!userRead.is_open())
		{
			return false;
		}
		std::string textusernamestr, textpasswordstr, textfirstnamestr, textlastnamestr, textemailstr;
		textusernamestr = textusername.getTexte();
		textpasswordstr = textpassword.getTexte();
		textfirstnamestr = textfirstname.getTexte();
		textlastnamestr = textlastname.getTexte();
		textemailstr = textemail.getTexte();


		if (requeteNickNameCompte(textusername))
		{
			if (requetePasswordCompte(textpassword))
			{
				if (requeteNameCompte(textfirstname))
				{
					if (requeteNameCompte(textlastname))
					{
						if (requeteEmailCompte(textemail))
						{
							userWrite<< std::endl << textusernamestr << " " << textpasswordstr << " " << textlastnamestr << " " << textfirstnamestr << " " << textemailstr;
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool Controleur::requeteCreerModif(const Textbox& textfirstname, const Textbox& textlastname, const Textbox& textemail)
	{
		std::ofstream userWrite("Assets\\Account\\User.txt", std::ios::app);
		std::ifstream userRead("Assets\\Account\\User.txt");
		if (!userRead.is_open())
		{
			return false;
		}
		std::string textusernamestr, textpasswordstr, textfirstnamestr, textlastnamestr, textemailstr;
		userWrite << std::endl << textusernamestr << " " << textpasswordstr << " " << textlastnamestr << " " << textfirstnamestr << " " << textemailstr;
		return true;
	}
}
