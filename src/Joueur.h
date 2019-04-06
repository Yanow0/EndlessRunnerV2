//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_JOUEUR_H
#define ENDLESSRUNNER_JOUEUR_H


#include "Forme2D.h"
#include "Pos2D.h"
#include "Terrain.h"

class Joueur {
    public:
        Forme2D* taille;
        Pos2D* pos;
        int vitesseSaut;
        int gravite;

    //Constructeur Terrain
    Joueur();

    //Destructeur Terrain
    ~Joueur();

    void sauter(const Terrain &t);
    void descendre(const Terrain &t);
    void retomber(const Terrain &t);
};


#endif //ENDLESSRUNNER_JOUEUR_H
