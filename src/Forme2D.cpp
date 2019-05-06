//
// Created by Valentin on 14/03/2019.
//

#include "Forme2D.h"
#include <assert.h>

Forme2D::Forme2D() {
    setHauteur(1);
    setLargeur(1);
}

Forme2D::~Forme2D() {

}

Forme2D::Forme2D(const int hauteur, const int largeur) {
    assert (hauteur >= 1 && largeur >= 1);
    setHauteur(hauteur);
    setLargeur(largeur);
}

int Forme2D::getHauteur() const {return this->hauteur;}

int Forme2D::getLargeur() const {return this->largeur;}

void Forme2D::setHauteur(const int hauteur) {this->hauteur = hauteur;}

void Forme2D::setLargeur(const int largeur) {this->largeur = largeur;}
