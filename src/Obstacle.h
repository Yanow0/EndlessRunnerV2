//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_OBSTACLE_H
#define ENDLESSRUNNER_OBSTACLE_H

#include "Forme2D.h"
#include "Pos2D.h"


class Obstacle {

    public:
        Forme2D* taille;
        Pos2D* pos;

    Obstacle();
    ~Obstacle();

    void deplacementAuto();
};


#endif //ENDLESSRUNNER_OBSTACLE_H
