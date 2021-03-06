#pragma once
#include "deplaceable.h"


/// <summary>
/// Squelette d'une classe joueur.  Y a pas grand chose ici, mais c'est tout de m�me la sprite
/// De l'ensemble des animations qui est utilis�e.
///
///QUATRES CONSEILS IMPORTANTS:
///1- Vous aurez le choix entre animer la spriteSheet ou d'int�grer 4 sprites diff�rentes.  Dans ce cas-ci, votre 
///joueur ne devra plus h�riter de sprite
///
///2- Si vous faites plus d'un niveau, le joueur pourrait �tre port�e dans la game et pass� par r�f�rence plut�t que d�truit et cr�e � chaque niveau de jeu.
///
///3- Pour faire changer votre personnage direction, il faudra le "refl�ter dans une direction (reflet == scaling � -1)
///
///4- Si vous utilisez les sprites founis pour le joueur et que vous utilisez le cadre du Rectangle de sprite pour vos collisions, vos collisions seront probablement tr�s �loign�es.
///Votre jouuer pourrait "porter" un rectangle de collsion faisait 32 pixels de large.
///
/// </summary>
namespace platformer
{
	class Joueur : public Deplaceable
	{
	public:
		Joueur();
		~Joueur();
		void Update(bool, bool, bool);
		//(syst�me collision avec ennemie)nous l'aurions passez en boite de collision carr� mais par manque connaissance sur le fonctionnement nous avons remis � plus tard
		const bool EntityCollider(sf::Vector2f EnemyPosition);
		const sf::IntRect GetIntRect();


	private:
		static const int TAILLE_RECT = 32;
		const int GRAVITY_FORCE = -3; //gravity
		const short FRAME_BY_ANIMATION_STEP = 10;
		//(radius)informations en constante car toute les tuiles sont en 32x32 donc refaire le calcul serait inutile 
		const float RADIUS_32x32 = 20.0f;

		void Jump(int);
		void LetGravityDoItsJob();

		sf::IntRect rectTab[2][7];
		short leftCtr;
		short rightCtr;
		short jumpCharger;
		short currentRectPos1;
		short currentRectPos2;
		bool airborn;


	};
}

