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

    //Constructeur de Jeu
    GraphicJoueur(Jeu jeu);

    //Destructeur de Jeu
    ~GraphicJoueur();

    void afficherJoueur(Jeu jeu);
};


#endif //ENDLESSRUNNERV2_GRAPHICJOUEUR_H
