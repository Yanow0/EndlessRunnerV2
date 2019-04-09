//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_OBJET_H
#define ENDLESSRUNNER_OBJET_H

#include "Forme2D.h"
#include "Pos2D.h"

class Objet {
public:
        Forme2D* taille;
        Pos2D* pos;

    Objet();
    ~Objet();

    void deplacementAuto();
};


#endif //ENDLESSRUNNER_OBJET_H
