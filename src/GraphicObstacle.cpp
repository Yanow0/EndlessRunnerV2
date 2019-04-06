#include "GraphicObstacle.h"



GraphicObstacle::GraphicObstacle(Jeu jeu) {
    obstacle=jeu.getObstacle();

}

GraphicObstacle::~GraphicObstacle(){}

void GraphicObstacle::afficherObstacle(Jeu jeu) {
    imageObstacle.x= obstacle.pos->getX()*20;
    imageObstacle.y= obstacle.pos->getY()*20;
    imageObstacle.w= obstacle.taille->getLargeur()*20;
    imageObstacle.h= obstacle.taille->getHauteur()*20;
    SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(jeu.renderer, &imageObstacle);
}
