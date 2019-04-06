//
// Created by Valentin on 14/03/2019.
//

#include "Forme2D.h"
#include <assert.h>

Forme2D::Forme2D() {
    this->hauteur = 1;
    this->largeur = 1;
}

Forme2D::~Forme2D() {
    this->hauteur = 1;
    this->largeur = 1;
}

Forme2D::Forme2D(int hauteur, int largeur) {
    assert (hauteur >= 1 && largeur >= 1);
    this->hauteur = hauteur;
    this->largeur = largeur;
}

int Forme2D::getHauteur() {return this->hauteur;}

int Forme2D::getLargeur() {return this->largeur;}

void Forme2D::setHauteur(int hauteur) {this->hauteur = hauteur;}

void Forme2D::setLargeur(int largeur) {this->largeur = largeur;}
