#pragma once
#include <SFML/Graphics.hpp>

namespace platformer
{	
	/// <summary>
	/// Nouvelle version de la classe game.  � pr�sent elle sera surtout charg�e de charger les diff�rentes sc�nes
	/// testTest est toujours pr�sent pour que vous puissez faire le lien avec les test unitaires
	/// </summary>
	class Game
	{
	public:
		Game();
		int run();
		int testTest();

	private:
		const int LARGEUR = 1280;
		const int HAUTEUR = 800;
		bool init();

		sf::RenderWindow mainWin;
		sf::Event event;
	};
}