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
    SDL_Rect imageJoueur; //!< Variable membre de type SDL_Rect, représente la hitbox du joueur

    SDL_Surface *sSprite; //!< Pointeur de type SDL_Surface, représente la surface du sprite du joueur
    SDL_Texture *tSprite; //!< Pointeur de type SDL_Texture, représente la texture du sprite du joueur
    SDL_Rect jSpriteClips[ 24 ]; //!< Tableau de type SDL_Rect, contient les différents sprites pour animer le joueur

    //Constructeur de Jeu
    //! Constructeur de GraphicJoueur avec 1 paramètre
    /*!
        Initialise les variables membres de GraphicJoueur, créer la texture du joueur.
      \param jeu passage en référence du Jeu en cours.

    */
    GraphicJoueur(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicJoueur();

    //! afficherJoueur, fonction membre de GraphicJoueur avec 2 paramètres
    /*!
        Affiche le joueur sur le renderer en fonction de sa position, sa forme et de la frame actuelle
      \param jeu passage en référence du Jeu en cours.
      \param frame entier représentant l'image actuelle.
    */
    void afficherJoueur(Jeu& jeu, int frame) ;
};


#endif //ENDLESSRUNNERV2_GRAPHICJOUEUR_H
