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
        int vie;
        bool fantome;
        bool doubleSaut;
        float vitesseSaut;
        float gravite;
        int* action = new int;



    //Constructeur Joueur
    Joueur();
    Joueur(const int &v);   // v: nouveau nombre de vies

    //Destructeur Joueur
    ~Joueur();
    int& getAction() const;
    void setAction(const int x);
    int& getVie();
    void setVie(const int x);
    void vieUp();
    void vieDown();
    bool getDoubleSaut() const;
    void activerDoubleSaut();
    void desactiverDoubleSaut();
    bool getFantome() const;
    void activerFantome();
    void desactiverFantome();
    void doubleSauter(const Terrain &t);
    bool collisionSol(const Terrain &t);
    void baisser(const Terrain &t);
    void relever(const Terrain &t);
    void sauter(const Terrain &t);
    void descendre(const Terrain &t);
    void retomber(const Terrain &t);
};


#endif //ENDLESSRUNNER_JOUEUR_H
