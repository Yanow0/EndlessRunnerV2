//
// Created by Yanis on 14/03/2019.
//

#include <cstdlib>
#include <ctime>
#include "Objet.h"


Objet::Objet(){
    srand(time(NULL));
    taille = new Forme2D(1,1);
    pos = new Pos2D(20,rand()%8 + 1);
    setTypeObjet((rand() % 3));
}

Objet::~Objet(){
}

int& Objet::getTypeObjet() const{
    return *typeObjet;
}

void Objet::setTypeObjet(const int x){
    *typeObjet = x;
}

void Objet::vie(Joueur &j){
    j.vieUp();
}

void Objet::fantome(Joueur &j){
    j.activerFantome();
}

void Objet::doubleSaut(Joueur &j){
    j.activerDoubleSaut();
}

void Objet::deplacementAuto() {
    float delta = 0.2; // deplacement à chaque pas de temps
    if (pos->getX()>=delta)
        pos->setX(pos->getX()-delta);
    else if (taille->getLargeur()>0) {
        taille->setLargeur(taille->getLargeur()-delta+pos->getX());
        pos->setX(0);
    }
}
