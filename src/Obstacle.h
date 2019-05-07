//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_OBSTACLE_H
#define ENDLESSRUNNER_OBSTACLE_H

#include "Forme2D.h"
#include "Pos2D.h"


class Obstacle {

    public:
        Forme2D* taille; //!< Pointeur de type Forme2D
        Pos2D* pos; //!< Pointeur de type Pos2D

    //! Constructeur de Obstacle sans paramètre
    /*!
        Initialise les variables membre de Obstacle
    */
    Obstacle();

    //Destructeur de Obstacle
    ~Obstacle();

    //! deplacementAuto, procedure de Obstacle
    /*!
        permet le deplacement des obstacles dans l'espace
    */
    void deplacementAuto();
};


#endif //ENDLESSRUNNER_OBSTACLE_H
