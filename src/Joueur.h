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
        float vitesseSaut;
        float gravite;
        int* action = new int;



    //Constructeur Joueur
    Joueur();

    //Destructeur Joueur
    ~Joueur();
    int& getAction();
    void setAction(int x);
    void doubleSauter(const Terrain &t);
    bool collisionSol(const Terrain &t);
    void baisser(const Terrain &t);
    void relever(const Terrain &t);
    void sauter(const Terrain &t);
    void descendre(const Terrain &t);
    void retomber(const Terrain &t);
};


#endif //ENDLESSRUNNER_JOUEUR_H
