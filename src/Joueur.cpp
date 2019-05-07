//
// Created by Yanis on 14/03/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
    setScore(0);
}

Joueur::~Joueur(){

}

int& Joueur::getAction() const{
    return *action;
}

void Joueur::setAction(const int x){
    *action = x;
};

int& Joueur::getVie() {
    return vie;
}

void Joueur::setVie(const int x){
    vie = x;
}

int& Joueur::getScore(){
    return score;
}
void Joueur::setScore(const int x){
    score = x;
}

void Joueur::vieUp(){
    vie++;
}

void Joueur::vieDown(){
    if (vie >= 1) vie--;
}

bool Joueur::getDoubleSaut() const{
    return doubleSaut;
}

void Joueur::activerDoubleSaut(){
    doubleSaut = true;
}

void Joueur::desactiverDoubleSaut(){
    doubleSaut = false;
}

bool Joueur::getFantome() const{
    return fantome;
}

void Joueur::activerFantome(){
    fantome = true;
}

void Joueur::desactiverFantome(){
    fantome = false;
}

void Joueur::sauter(const Terrain &t) {
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
}

void Joueur::doubleSauter(const Terrain &t) {
        vitesseSaut=0.5;
}

void Joueur::descendre(const Terrain &t) {
        pos->setY(pos->getY()+gravite);
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
}


void Joueur::relever(const Terrain &t) {
    setAction(0);
    taille->setHauteur(2);
    pos->setY(pos->getY()-1);
}

void Joueur::testRegression() {
    cout << endl;
    cout << "======== TEST de regression pour JOUEUR ========" << endl;
    assert (pos->getX()==8);
    cout << "\npos x initiale joueur ok" << endl;
    assert (pos->getY()==7);
    cout << "pos y initiale joueur ok" << endl;
    assert (getVie()==3);
    cout << "vie initiale joueur ok" << endl;
    assert (getFantome()==false);
    cout << "fantome initial joueur ok" << endl;
    assert (getDoubleSaut()==false);
    cout << "double saut initial joueur ok" << endl;
    assert (vitesseSaut==0.5);
    cout << "vitesseSaut initiale joueur ok" << endl;
    assert (gravite==0.025f);
    cout << "gravite initiale joueur ok" << endl;
    assert (getAction()==0);
    cout << "action initiale joueur ok" << endl;

    pos->setX(1);
    assert (pos->getX()==1);
    cout << "\npos x apres set joueur ok" << endl;
    pos->setY(1);
    assert (pos->getY()==1);
    cout << "pos y apres set joueur ok" << endl;
    setVie(1);
    assert (getVie()==1);
    cout << "vie apres set joueur ok" << endl;
    activerFantome();
    assert (getFantome()==true);
    cout << "fantome apres activer joueur ok" << endl;
    activerDoubleSaut();
    assert (getDoubleSaut()==true);
    cout << "double saut apres activer joueur ok" << endl;
    setAction(1);
    assert (getAction()==1);
    cout << "action apres set joueur ok" << endl;

    sauter(*(new Terrain()));
    assert (pos->getY()==1-0.5);
    cout << "pos y apres sauter joueur ok" << endl << endl;
//    assert (vitesseSaut==0.5-0.025f);
//    cout << "vitesseSaut apres sauter joueur ok" << endl;
    cout << "==> JOUEUR : OK" << endl << endl;
}

void Joueur::secondeChance() {
    taille = new Forme2D(2,2);
    pos = new Pos2D(8,7);
    fantome = false;
    doubleSaut = false;
    vitesseSaut=0.5;
    gravite=0.025f;
    setAction(0);
}

