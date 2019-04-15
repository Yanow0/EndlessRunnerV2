//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICJOUEUR_H
#define ENDLESSRUNNERV2_GRAPHICJOUEUR_H

#include "Fenetre.h"
#include "Jeu.h"

class GraphicJoueur {
public:
    Joueur joueur;
    SDL_Rect imageJoueur;

    SDL_Surface *sSprite;
    SDL_Texture *tSprite;
    SDL_Rect jSpriteClips[ 24 ];
    Uint32 colorkey;

    //Constructeur de Jeu
    GraphicJoueur(Jeu jeu);

    //Destructeur de Jeu
    ~GraphicJoueur();

    void afficherJoueur(Jeu jeu, int frame);
};


#endif //ENDLESSRUNNERV2_GRAPHICJOUEUR_H
