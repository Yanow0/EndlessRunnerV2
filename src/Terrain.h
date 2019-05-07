//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_TERRAIN_H
#define ENDLESSRUNNER_TERRAIN_H


#include "Pos2D.h"

class Terrain {

private:
	int dimx; //!< Variable membre, entier représentant la dimension en x du terrain.
	int dimy; //!< Variable membre, entier représentant la dimension en y du terrain.
	char ter [100][100];
    int plateforme; //!< Variable membre, entier représentant la hauteur du sol.

public:
    //! Constructeur de Terrain sans paramètre
    /*!
        Initialise les variables membre de Terrain
    */
    Terrain();

    //Destructeur de Terrain
    ~Terrain();

    //! Getter de dimX de Terrain
    /*!
        Retourne l'entier dimX de Terrain.
    */
    int getDimX() const;

    //! Getter de dimY de Terrain
    /*!
        Retourne l'entier dimY de Terrain.
    */
    int getDimY() const;

    //! Getter de platefrome de Terrain
    /*!
        Retourne l'entier plateforme de Terrain.
    */
    int getPlateforme() const;

    //! Getter de la position en x et y  de Terrain
    /*!
        Retourne les entiers x et y de Terrain.
    */
    char getXY(const int &x, const int &y) const;

   //! positionValide , fonction memebre de Terrain
   /*!
        Verifie si la position entree est correcte
        \param x,y int, les positions x et y
    */
    bool positionValide(const int &x, const int &y) const;

    //! testRegression, procedure membre de Terrain sans paramètre
    /*!
        Lance un test de régression pour la classe Terrain
    */
    void testRegression();
};


#endif //ENDLESSRUNNER_TERRAIN_H
