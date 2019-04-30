//
// Created by Yanis on 14/03/2019.
//
#ifndef ENDLESSRUNNER_OBJET_H
#define ENDLESSRUNNER_OBJET_H

#include "Forme2D.h"
#include "Pos2D.h"
#include "Joueur.h"
class Objet {
public:
    Forme2D* taille;
    Pos2D* pos;
    int* objet = new int;

    Objet();
    ~Objet();
    int& getObjet();
    void setObjet(int x);
    void vie(Joueur &j);
    void fantome(Joueur &j);
    void doubleSaut(Joueur &j);
    void arme(Joueur &j);
};


#endif //ENDLESSRUNNER_OBJET_H
