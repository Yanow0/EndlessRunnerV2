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
    taille = new Forme2D(2,2);
    pos = new Pos2D(8,7);
    setVie(3);
    fantome = false;
    doubleSaut = false;
    vitesseSaut=0.5;
    gravite=0.025f;
    setAction(0);
}

Joueur::~Joueur(){

}

int& Joueur::getAction() {
    return *action;
}

void Joueur::setAction(int x){
    *action = x;
};

int& Joueur::getVie(){
    return vie;
}

void Joueur::setVie(int x){
    vie = x;
}

void Joueur::vieUp(){
    vie++;
}

bool& Joueur::getDoubleSaut(){
    return doubleSaut;
}

void Joueur::activerDoubleSaut(){
    doubleSaut = true;
}

void Joueur::desactiverDoubleSaut(){
    doubleSaut = false;
}

void Joueur::sauter(const Terrain &t) {
  //  if (t.positionValide(pos->getX(),pos->getY()-d)) {
        if (vitesseSaut > 0) {
             setAction(2);
        } else {
            setAction(3);
        }

        pos->setY(pos->getY()-vitesseSaut);
        vitesseSaut-=gravite;
        if(pos->getY() + taille->getHauteur() >= t.getPlateforme()) {
            vitesseSaut=0.5;
            setAction(0);
        }
//        cout<<"sauter"<<endl;
  //  }

}

void Joueur::doubleSauter(const Terrain &t) {
  //  if (t.positionValide(pos->getX(),pos->getY()-d)) {
        vitesseSaut=0.5;
        cout<<"double Sauter"<<endl;
  //  }

}

void Joueur::descendre(const Terrain &t) {
   // if (t.positionValide(pos->getX(),pos->getY()+d)) {
        pos->setY(pos->getY()+gravite);
//        cout<<"descendre"<<endl;
  //  }
}
void Joueur::retomber(const Terrain &t) {
    if ( this->pos->getY() + this->taille->getHauteur() < t.getPlateforme() ) {
        descendre(t);
    }
}

void Joueur::baisser(const Terrain &t) {
    setAction(1);
    taille->setHauteur(1);
    pos->setY(pos->getY()+ 1);

  //   cout<<"baisser"<< action << endl;
}


void Joueur::relever(const Terrain &t) {
    setAction(0);
    taille->setHauteur(2);
    pos->setY(pos->getY()-1);
   // cout<<"relever"<< action << endl;
}

