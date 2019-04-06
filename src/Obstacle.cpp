//
// Created by Yanis on 14/03/2019.
//

#include <cstdlib>
#include "Obstacle.h"


Obstacle::Obstacle() {
    taille = new Forme2D( rand()%2 + 1 , rand()%3 + 1 );
    pos = new Pos2D(18, rand()%(8-taille->getHauteur()) + 1 );
}

Obstacle::~Obstacle(){

}


void Obstacle::deplacementAuto() {
    if (pos->getX()>0)
        pos->setX(pos->getX()-1);
    else if (taille->getLargeur()>0)
        taille->setLargeur(taille->getLargeur()-1);
}
