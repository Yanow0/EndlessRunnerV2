//
// Created by Yanis on 14/03/2019.
//

#include <cstdlib>
#include "Objet.h"


Objet::Objet(){
    taille = new Forme2D(1,1);
    pos = new Pos2D(3,2);
}

Objet::~Objet(){
}

void Objet::deplacementAuto() {
    if (pos->getX()>0)
        pos->setX(pos->getX()-1);
    else if (taille->getLargeur()>0)
        taille->setLargeur(taille->getLargeur()-1);
}
