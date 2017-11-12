#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "CppUnitTest.h"
#include "../Platformer/Controleur.h"
#include "../Platformer/Textbox.h"
//Il faut que ce dernier lien soit aussi dans 
//[right-click sur projet]\éditeur de liens\propriétés\entrées\dépendances additionnelles
//sinon il y aura une erreur de linkage

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace platformer;

namespace ProjetSFMLTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestUsernameValide)
		{			
			Textbox username;
			Textbox password;
			username.insererTexte("Zoro9968");
			password.insererTexte("Pa55w*rd");
			Assert::IsTrue(Controleur::getInstance()->requeteUserName(username,password));
		}

		TEST_METHOD(TestUsernameInvalide1)
		{
			Textbox username;
			Textbox password;
			username.insererTexte("Zoro9968");
			password.insererTexte("password");
			Assert::IsFalse(Controleur::getInstance()->requeteUserName(username,password));
		}

		TEST_METHOD(TestUsernameInvalide2)
		{
			Textbox username;
			Textbox password;
			username.insererTexte("antoine");
			password.insererTexte("Pa55w*rd");
			Assert::IsFalse(Controleur::getInstance()->requeteUserName(username, password));
		}


		TEST_METHOD(TestNicknameValide)
		{
			Textbox nickname;
			nickname.insererTexte("antoine");
			Assert::IsTrue(Controleur::getInstance()->requeteNickNameCompte(nickname));
		}

		TEST_METHOD(TestNicknameInvalide1)
		{
			Textbox nickname;
			nickname.insererTexte("a");
			Assert::IsFalse(Controleur::getInstance()->requeteNickNameCompte(nickname));
		}

		TEST_METHOD(TestNicknameInvalide2)
		{
			Textbox nickname;
			nickname.insererTexte("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
			Assert::IsFalse(Controleur::getInstance()->requeteNickNameCompte(nickname));
		}

		TEST_METHOD(TestPasswordCompteValide)
		{
			Textbox password;
			password.insererTexte("Antoine9912*");
			Assert::IsTrue(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestPasswordCompteInvalide1)
		{
			Textbox password;
			password.insererTexte("antoine9912*");
			Assert::IsFalse(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestPasswordCompteInvalide2)
		{
			Textbox password;
			password.insererTexte("Antoine9912");
			Assert::IsFalse(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestPasswordCompteInvalide3)
		{
			Textbox password;
			password.insererTexte("Antoine*");
			Assert::IsFalse(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestPasswordCompteInvalide4)
		{
			Textbox password;
			password.insererTexte("ANTOINE9912*");
			Assert::IsFalse(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestPasswordCompteInvalide5)
		{
			Textbox password;
			password.insererTexte("Al3*");
			Assert::IsFalse(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestPasswordCompteInvalide6)
		{
			Textbox password;
			password.insererTexte("Antoine9912*lllllllllllllllllllllll");
			Assert::IsFalse(Controleur::getInstance()->requetePasswordCompte(password));
		}

		TEST_METHOD(TestNameCompteValide1)
		{
			Textbox name;
			name.insererTexte("Antoine.R-L.-");
			Assert::IsTrue(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestNameCompteValide2)
		{
			Textbox name;
			name.insererTexte("-----------------");
			Assert::IsTrue(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestNameCompteValide3)
		{
			Textbox name;
			name.insererTexte(".............");
			Assert::IsTrue(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestNameCompteValide4)
		{
			Textbox name;
			name.insererTexte("antoine");
			Assert::IsTrue(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestNameCompteInvalide1)
		{
			Textbox name;
			name.insererTexte("Antoine.R-L.99");
			Assert::IsFalse(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestNameCompteInvalide2)
		{
			Textbox name;
			name.insererTexte("A");
			Assert::IsFalse(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestNameCompteInvalide3)
		{
			Textbox name;
			name.insererTexte("AntoineRlllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll");
			Assert::IsFalse(Controleur::getInstance()->requeteNameCompte(name));
		}

		TEST_METHOD(TestEmailValide1)
		{
			Textbox email;
			email.insererTexte("titoi._-ne9912@hotmail.com");
			Assert::IsTrue(Controleur::getInstance()->requeteEmailCompte(email));
		}

		TEST_METHOD(TestEmailValide2)
		{
			Textbox email;
			email.insererTexte("titoine9912@hotmail.ca.qc");
			Assert::IsTrue(Controleur::getInstance()->requeteEmailCompte(email));
		}

		TEST_METHOD(TestEmailInvalide1)
		{
			Textbox email;
			email.insererTexte("titoine9912hotmail.ca");
			Assert::IsFalse(Controleur::getInstance()->requeteEmailCompte(email));
		}

		TEST_METHOD(TestEmailInvalide2)
		{
			Textbox email;
			email.insererTexte("titoine@@9912hotmail.ca");
			Assert::IsFalse(Controleur::getInstance()->requeteEmailCompte(email));
		}


		TEST_METHOD(TestEmailInvalide3)
		{
			Textbox email;
			email.insererTexte("titoine@9912hot.mailca");
			Assert::IsFalse(Controleur::getInstance()->requeteEmailCompte(email));
		}

		TEST_METHOD(TestEmailInvalide4)
		{
			Textbox email;
			email.insererTexte("titoine@9912hotmailca");
			Assert::IsFalse(Controleur::getInstance()->requeteEmailCompte(email));
		}

	};
}