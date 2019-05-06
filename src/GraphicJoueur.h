//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICJOUEUR_H
#define ENDLESSRUNNERV2_GRAPHICJOUEUR_H

#include "Jeu.h"
#include <SDL2/SDL_image.h>

class GraphicJoueur {
public:
    Joueur* joueur; //!< Pointeur de type Joueur
    SDL_Rect imageJoueur; //!< Variable membre de type SDL_Rect, repr�sente la hitbox du joueur

    SDL_Surface *sSprite; //!< Pointeur de type SDL_Surface, repr�sente la surface du sprite du joueur
    SDL_Texture *tSprite; //!< Pointeur de type SDL_Texture, repr�sente la texture du sprite du joueur
    SDL_Rect jSpriteClips[ 24 ]; //!< Tableau de type SDL_Rect, contient les diff�rents sprites pour animer le joueur

    //Constructeur de Jeu
    //! Constructeur de GraphicJoueur avec 1 param�tre
    /*!
        Initialise les variables membres de GraphicJoueur, cr�er la texture du joueur.
      \param jeu passage en r�f�rence du Jeu en cours.

    */
    GraphicJoueur(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicJoueur();

    //! afficherJoueur, fonction membre de GraphicJoueur avec 2 param�tres
    /*!
        Affiche le joueur sur le renderer en fonction de sa position, sa forme et de la frame actuelle
      \param jeu passage en r�f�rence du Jeu en cours.
      \param frame entier repr�sentant l'image actuelle.
    */
    void afficherJoueur(Jeu& jeu, int frame) ;
};


#endif //ENDLESSRUNNERV2_GRAPHICJOUEUR_H
