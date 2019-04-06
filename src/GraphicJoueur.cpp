//
// Created by Yanis on 24/03/2019.
//

#include "GraphicJoueur.h"


GraphicJoueur::GraphicJoueur(Jeu jeu) {
    joueur=jeu.getJoueur();

}

GraphicJoueur::~GraphicJoueur(){}

void GraphicJoueur::afficherJoueur(Jeu jeu) {
    imageJoueur.x= joueur.pos->getX()*40;
    imageJoueur.y= joueur.pos->getY()*40;
    imageJoueur.w= joueur.taille->getLargeur()*40;
    imageJoueur.h= joueur.taille->getHauteur()*40;
    SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(jeu.renderer, &imageJoueur);
}
