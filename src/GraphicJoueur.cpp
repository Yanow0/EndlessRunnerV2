//
// Created by Yanis on 24/03/2019.
//

#include "GraphicJoueur.h"
#include <iostream>
using namespace std;

GraphicJoueur::GraphicJoueur(Jeu jeu) {
    joueur=jeu.getJoueur();
    sSprite = IMG_Load("joueur2.png");
    if (!sSprite) {
        cout << "Error: cannot load sprite surface" <<endl;
        IMG_GetError();
    }

    tSprite = SDL_CreateTextureFromSurface(jeu.renderer,sSprite);
     if (tSprite==NULL) {
        cout << "Error: cannot create sprite texture" <<endl;
    }

   // SPRITE QUI COURT
        jSpriteClips[ 0 ].x =  10;
		jSpriteClips[ 0 ].y =  193;
		jSpriteClips[ 0 ].w =  80;
		jSpriteClips[ 0 ].h =  65;

		jSpriteClips[ 1 ].x =  90;
		jSpriteClips[ 1 ].y = 193;
		jSpriteClips[ 1 ].w =  80;
		jSpriteClips[ 1 ].h =  65;

		jSpriteClips[ 2 ].x = 170;
		jSpriteClips[ 2 ].y = 193;
		jSpriteClips[ 2 ].w =  80;
		jSpriteClips[ 2 ].h =  65;

		jSpriteClips[ 3 ].x =  250;
		jSpriteClips[ 3 ].y =  193;
		jSpriteClips[ 3 ].w =  80;
		jSpriteClips[ 3 ].h =  65;

		jSpriteClips[ 4 ].x = 330;
		jSpriteClips[ 4 ].y =  193;
		jSpriteClips[ 4 ].w =  80;
		jSpriteClips[ 4 ].h =  65;

		jSpriteClips[ 5 ].x =  410;
		jSpriteClips[ 5 ].y =   193;
		jSpriteClips[ 5 ].w =  80;
		jSpriteClips[ 5 ].h =  65;

}

GraphicJoueur::~GraphicJoueur(){}

void GraphicJoueur::afficherJoueur(Jeu jeu, int frame) {


    imageJoueur.x= joueur.pos->getX()*40;
    imageJoueur.y= joueur.pos->getY()*40;
    imageJoueur.w= joueur.taille->getLargeur()*40;
    imageJoueur.h= joueur.taille->getHauteur()*40;
    //SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderDrawRect(jeu.renderer, &imageJoueur);

    SDL_RenderCopy(jeu.renderer, tSprite, &jSpriteClips[frame/6], &imageJoueur);
}
