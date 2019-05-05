#include <iostream>
#include "GraphicObstacle.h"



GraphicObstacle::GraphicObstacle(Jeu& jeu) {
 obstacle=jeu.getObstacle();
}

GraphicObstacle::~GraphicObstacle(){}

void GraphicObstacle::afficherObstacle(Jeu jeu) {


    imageObstacle.clear();
    for (int k=0; k<obstacle->nbObstacles(); k++) {
        SDL_Rect image;
        image.x= obstacle->getObstacle(k)->pos->getX()*40;
        image.y= obstacle->getObstacle(k)->pos->getY()*40;
        image.w= obstacle->getObstacle(k)->taille->getLargeur()*40;
        image.h= obstacle->getObstacle(k)->taille->getHauteur()*40;
        imageObstacle.push_back(image);
    }
    SDL_Rect* imgs = &imageObstacle[0];

    SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRects(jeu.renderer, imgs, obstacle->nbObstacles());
}
