//
// Created by Yanis on 14/03/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <unistd.h>


#include "Joueur.h"
using namespace std;


Joueur::Joueur() {
    taille = new Forme2D(2,1);
    pos = new Pos2D(8,6);
    vitesseSaut=3;
    gravite=1;
//    taille = new Forme2D(100,50);
//    pos = new Pos2D(320,370);
}

Joueur::~Joueur(){

}

void Joueur::sauter(const Terrain &t) {
  //  if (t.positionValide(pos->getX(),pos->getY()-d)) {
        pos->setY(pos->getY()-vitesseSaut);
        cout<<"sauter"<<endl;
  //  }
}
void Joueur::descendre(const Terrain &t) {
   // if (t.positionValide(pos->getX(),pos->getY()+d)) {
        pos->setY(pos->getY()+gravite);
        cout<<"descendre"<<endl;
  //  }
}
void Joueur::retomber(const Terrain &t) {
    if ( this->pos->getY() + this->taille->getHauteur() < t.getPlateforme() ) {
        descendre(t);
    }
}
