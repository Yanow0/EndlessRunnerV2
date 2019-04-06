//
// Created by Yanis on 24/03/2019.
//

#include "GraphicTerrain.h"
#include <iostream>
using namespace std;

GraphicTerrain::GraphicTerrain(Jeu jeu) {
    terrain=jeu.getTerrain();
    background = IMG_Load("background.jpg");
    if (background==NULL) {
        cout << "Error: cannot load background" <<endl;
    }
    texture = SDL_CreateTextureFromSurface(jeu.renderer,background);
}

GraphicTerrain::~GraphicTerrain(){}

void GraphicTerrain::afficherTerrain(Jeu jeu) {

    SDL_RenderCopy(jeu.renderer, texture, NULL, NULL);
   // SDL_SetRenderDrawColor(fenetre.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
   // SDL_RenderDrawLine(fenetre.renderer, 0, (terrain.getDimY()*20-terrain.getPlateforme()), terrain.getDimX()*20, (terrain.getDimY()*20-terrain.getPlateforme()));
}

