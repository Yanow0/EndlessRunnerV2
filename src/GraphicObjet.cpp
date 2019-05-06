#include "GraphicObjet.h"
#include <iostream>
using namespace std;

GraphicObjet::GraphicObjet(Jeu& jeu) {
    objet=jeu.getObjet();

    sSprite = IMG_Load("./data/icons.png");
    if (!sSprite) {
        cout << "Error: cannot load sprite surface" <<endl;
        IMG_GetError();
    }

    tSprite = SDL_CreateTextureFromSurface(jeu.renderer,sSprite);
    if (tSprite==NULL) {
        cout << "Error: cannot create sprite texture" <<endl;
    }

    //SPRITE OBJET VIE
    jSpriteClips[ 0 ].x =  128;
    jSpriteClips[ 0 ].y =  288;
    jSpriteClips[ 0 ].w =  32;
    jSpriteClips[ 0 ].h =  32;

    //SPRITE OBJET FANTOME
    jSpriteClips[ 1 ].x =  160;
    jSpriteClips[ 1 ].y =  96;
    jSpriteClips[ 1 ].w =  32;
    jSpriteClips[ 1 ].h =  32;

    //SPRITE OBJET DOUBLE SAUT
    jSpriteClips[ 2 ].x =  64;
    jSpriteClips[ 2 ].y =  256;
    jSpriteClips[ 2 ].w =  32;
    jSpriteClips[ 2 ].h =  32;

    //SPRITE OBJET ARME
    jSpriteClips[ 3 ].x =  128;
    jSpriteClips[ 3 ].y =  192;
    jSpriteClips[ 3 ].w =  32;
    jSpriteClips[ 3 ].h =  32;
}

GraphicObjet::~GraphicObjet(){}

void GraphicObjet::afficherObjet(Jeu& jeu) {

    imageObjet.x= objet->pos->getX()*40;
    imageObjet.y= objet->pos->getY()*40;
    imageObjet.w= objet->taille->getLargeur()*40;
    imageObjet.h= objet->taille->getHauteur()*40;
    //SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderDrawRect(jeu.renderer, &imageObjet);

    SDL_RenderCopy(jeu.renderer, tSprite, &jSpriteClips[objet->getTypeObjet()], &imageObjet);
}

