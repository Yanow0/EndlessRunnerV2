//
// Created by Yanis on 14/03/2019.
//

#include <cassert>
#include "Terrain.h"

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
