#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"


using namespace sf;

/// <summary>
/// Classe abstraite avec aucune méthode concrétisée.  Un .h suffit donc.
/// </summary>
namespace platformer
{
	class Scene
	{
	public:
		//Quand vos ajouterez des scènes, ajouter un enum ici
		enum scenes {TITRE, NIVEAU1, SORTIE, MENUPRINCIPALE,GESTIONCOMPTE,SCORE,EFFACER,CREER,MODIFIER};
		static const int NOMBRE_TUILES_X = 40;
		static const int NOMBRE_TUILES_Y = 25;
		static const int TAILLE_TUILES = 32;

		virtual ~Scene() {}  //Pour que le destructeur de l'objet en mémoire soit apellé
		virtual scenes run() = 0;
		
		//La boucle de jeu est maintenant gérée par la scène
		virtual bool init(RenderWindow * const window) = 0;
		virtual void getInputs() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

	protected:
		RenderWindow *mainWin;
		Event event;
		
		/// <summary>
		/// À la fin de chaque scène, on indique à Game quelle nouvelle scène elle doit charger.
		/// </summary>
		Scene::scenes transitionVersScene;
		bool isRunning;
	};
}