//
// Created by Yanis on 14/03/2019.
//

#include <cstdlib>
#include "Obstacle.h"


Obstacle::Obstacle() {
    taille = new Forme2D( 1 , rand()%2 + 1 );
    pos = new Pos2D(20, rand()%(9-taille->getHauteur()) + 1 );
}

Obstacle::~Obstacle(){

}


void Obstacle::deplacementAuto() {
    float delta = 0.2; // deplacement à chaque pas de temps
    if (pos->getX()>=delta)
        pos->setX(pos->getX()-delta);
    else if (taille->getLargeur()>0) {
        taille->setLargeur(taille->getLargeur()-delta+pos->getX());
        pos->setX(0);
    }
}
