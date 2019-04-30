//
// Created by Yanis on 14/03/2019.
//

#include <cstdlib>
#include <ctime>
#include "Objet.h"


Objet::Objet(){
    srand(time(NULL));
    taille = new Forme2D(1,1);
    pos = new Pos2D(3,2);
    setObjet((rand() % 4));
}

Objet::~Objet(){
}

int& Objet::getObjet() {
    return *objet;
}

void Objet::setObjet(int x){
    *objet = x;
}

void Objet::vie(Joueur &j){
    j.vieUp();
}

void Objet::fantome(Joueur &j){
    j.fantome = true;
}

void Objet::doubleSaut(Joueur &j){
}

void Objet::arme(Joueur &j){
}

