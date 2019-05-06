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
}

GraphicObjet::~GraphicObjet(){}

void GraphicObjet::afficherObjet(Jeu& jeu, int frame) {
    imageObjet.clear();
    for (int k=0; k<objet->nbObjet(); k++) {
        SDL_Rect image;
        image.x= objet->getObjet(k)->pos->getX()*40;
        image.y= objet->getObjet(k)->pos->getY()*40;
        image.w= objet->getObjet(k)->taille->getLargeur()*40;
        image.h= objet->getObjet(k)->taille->getHauteur()*40;
        imageObjet.push_back(image);
        //SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        //SDL_RenderDrawRect(jeu.renderer, &imageObjet);

        SDL_RenderCopy(jeu.renderer, tSprite, &jSpriteClips[objet->getObjet(k)->getTypeObjet()], &imageObjet.at(k));
    }
}

