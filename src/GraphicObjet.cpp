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

    sHeart = IMG_Load("./data/coeur.png");
    if (!sHeart) {
        cout << "Error: cannot load sprite surface" <<endl;
        IMG_GetError();
    }

    tHeart = SDL_CreateTextureFromSurface(jeu.renderer,sHeart);
    if (tHeart==NULL) {
        cout << "Error: cannot create sprite texture" <<endl;
    }

    sStar = IMG_Load("./data/star.png");
    if (!sStar) {
        cout << "Error: cannot load sprite surface" <<endl;
        IMG_GetError();
    }

    tStar = SDL_CreateTextureFromSurface(jeu.renderer,sStar);
    if (tStar==NULL) {
        cout << "Error: cannot create sprite texture" <<endl;
    }

    //SPRITE OBJET DOUBLE SAUT
    jSpriteClips[ 0 ].x =  64;
    jSpriteClips[ 0 ].y =  256;
    jSpriteClips[ 0 ].w =  32;
    jSpriteClips[ 0 ].h = 32;

}

GraphicObjet::~GraphicObjet(){}

void GraphicObjet::afficherObjet(Jeu& jeu) {
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

        switch(objet->getObjet(k)->getTypeObjet()) {
            case 0 :
                SDL_RenderCopy(jeu.renderer, tHeart, NULL, &imageObjet.at(k));
                break;

            case 1 :
                SDL_RenderCopy(jeu.renderer, tStar, NULL, &imageObjet.at(k));
                 break;

            case 2 :
                SDL_RenderCopy(jeu.renderer, tSprite, &jSpriteClips[0], &imageObjet.at(k));
                break;
        }
    }
}

