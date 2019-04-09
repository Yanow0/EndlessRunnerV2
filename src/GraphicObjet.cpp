#include "GraphicObjet.h"
#include <iostream>
using namespace std;

GraphicObjet::GraphicObjet(Jeu jeu) {
    objet=jeu.getObjet();
    /**
    background = IMG_Load("32-done.gif");
    if (background==NULL) {
        cout << "Error: cannot load object background" <<endl;
    }
    texture = SDL_CreateTextureFromSurface(jeu.renderer,background);
    */
}

GraphicObjet::~GraphicObjet(){}

void GraphicObjet::afficherObjet(Jeu jeu) {

    imageObjet.x= objet.pos->getX()*20;
    imageObjet.y= objet.pos->getY()*20;
    imageObjet.w= objet.taille->getLargeur()*20;
    imageObjet.h= objet.taille->getHauteur()*20;
    SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(jeu.renderer, &imageObjet);

    //SDL_RenderCopy(jeu.renderer, texture, NULL, NULL);
}
