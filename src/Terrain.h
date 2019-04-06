//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_TERRAIN_H
#define ENDLESSRUNNER_TERRAIN_H


#include "Pos2D.h"

class Terrain {

private:
	int dimx;
	int dimy;
	char ter [100][100];
    int plateforme;

public:
    //Constructeur Terrain
    Terrain();

    //Destructeur Terrain
    ~Terrain();

    int getDimX() const;
    int getDimY() const;
    int getPlateforme() const;

    char getXY(const int &x, const int &y) const;

    bool positionValide(const int &x, const int &y) const;
};


#endif //ENDLESSRUNNER_TERRAIN_H
