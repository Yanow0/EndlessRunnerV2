//
// Created by Yanis on 14/03/2019.
//

#include <cassert>
#include <iostream>
#include "Terrain.h"

using namespace std;

const char terrain1[10][21] = {
 "####################",    // 0
 "#                  #",    // 1
 "#                  #",    // 2
 "#                  #",    // 3
 "#                  #",    // 4
 "#                  #",    // 5
 "#                  #",    // 6
 "#                  #",    // 7
 "#------------------#",    // 8
 "####################"     // 9
};

Terrain::Terrain() {
    dimx = 20;
    dimy = 10;
    plateforme = 9;
	for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
			ter[x][y] = terrain1[y][x];
//			ter[x][y] = terrain1[dimy-1-y][x];
}

Terrain::~Terrain(){

}

int Terrain::getDimX() const {return dimx;}

int Terrain::getDimY() const {return dimy;}

int Terrain::getPlateforme() const {return plateforme;}


char Terrain::getXY(const int &x, const int &y) const {
	assert((x>=0) && (y>=0) && (x<dimx) && (y<dimy));
	return ter[x][y];
}

bool Terrain::positionValide(const int &x, const int &y) const {
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (ter[x][y]!='#'));
}

void Terrain::testRegression() {
    cout << endl;
    cout << "======== TEST de regression pour TERRAIN ========" << endl << endl;
    assert (getDimX()==20);
    cout << "dimX initiale terrain ok" << endl;
    assert (getDimY()==10);
    cout << "dimY initiale terrain ok" << endl;
    assert (getPlateforme()==9);
    cout << "plateforme initiale terrain ok" << endl;
    assert (positionValide(0,0)==false);
    assert (positionValide(1,1)==true);
    cout << "positionValide terrain ok" << endl << endl;
    cout << "==> TERRAIN : OK" << endl << endl;
}
