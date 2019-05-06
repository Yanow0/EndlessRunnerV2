//
// Created by Yanis on 24/03/2019.
//

#include "GraphicJoueur.h"
#include <iostream>
using namespace std;

GraphicJoueur::GraphicJoueur(Jeu& jeu) {
    joueur=jeu.getJoueur();
    sSprite = IMG_Load("./data/lucario.png");
    if (!sSprite) {
        cout << "Error: cannot load sprite surface" <<endl;
        IMG_GetError();
    }
    tSprite = SDL_CreateTextureFromSurface(jeu.renderer,sSprite);
     if (tSprite==NULL) {
        cout << "Error: cannot create sprite texture" <<endl;
    }

    sVie = IMG_Load("./data/coeur.png");
    sStar = IMG_Load("./data/star.png");
    sDoubleSaut = IMG_Load("./data/icons.png");
    tVie = SDL_CreateTextureFromSurface(jeu.renderer,sVie);
    tStar = SDL_CreateTextureFromSurface(jeu.renderer,sStar);
    tDoubleSaut = SDL_CreateTextureFromSurface(jeu.renderer,sDoubleSaut);

   // SPRITE QUI COURT
        jSpriteClips[ 0 ].x =  48;
		jSpriteClips[ 0 ].y =  16;
		jSpriteClips[ 0 ].w =  48;
		jSpriteClips[ 0 ].h =  48;

		jSpriteClips[ 1 ].x =  48;
		jSpriteClips[ 1 ].y = 16;
		jSpriteClips[ 1 ].w =  48;
		jSpriteClips[ 1 ].h =  48;

		jSpriteClips[ 2 ].x = 96;
		jSpriteClips[ 2 ].y = 16;
		jSpriteClips[ 2 ].w =  48;
		jSpriteClips[ 2 ].h =  48;

		jSpriteClips[ 3 ].x =  96;
		jSpriteClips[ 3 ].y =  16;
		jSpriteClips[ 3 ].w =  48;
		jSpriteClips[ 3 ].h =  48;

		jSpriteClips[ 4 ].x = 144;
		jSpriteClips[ 4 ].y =  16;
		jSpriteClips[ 4 ].w =  48;
		jSpriteClips[ 4 ].h =  48;

		jSpriteClips[ 5 ].x =  144;
		jSpriteClips[ 5 ].y =  16;
		jSpriteClips[ 5 ].w =  48;
		jSpriteClips[ 5 ].h =  48;




// SPRITE BAISS� //
		jSpriteClips[ 6 ].x =  98;
		jSpriteClips[ 6 ].y =  100;
		jSpriteClips[ 6 ].w =  48;
		jSpriteClips[ 6 ].h =  28;

		jSpriteClips[ 7 ].x =  98;
		jSpriteClips[ 7 ].y = 100;
		jSpriteClips[ 7 ].w =  48;
		jSpriteClips[ 7 ].h =  28;

		jSpriteClips[ 8 ].x = 98;
		jSpriteClips[ 8 ].y = 100;
		jSpriteClips[ 8 ].w =  48;
		jSpriteClips[ 8 ].h =  28;

		jSpriteClips[ 9 ].x =  98;
		jSpriteClips[ 9 ].y =  100;
		jSpriteClips[ 9 ].w =  48;
		jSpriteClips[ 9 ].h =  28;

		jSpriteClips[ 10 ].x = 98;
		jSpriteClips[ 10 ].y =  100;
		jSpriteClips[ 10 ].w =  48;
		jSpriteClips[ 10 ].h =  28;

		jSpriteClips[ 11 ].x =  98;
		jSpriteClips[ 11 ].y =  100;
		jSpriteClips[ 11 ].w =  48;
		jSpriteClips[ 11 ].h =  28;


/* SPRITE SAUTER */
		jSpriteClips[ 12 ].x =  48;
		jSpriteClips[ 12 ].y =  272;
		jSpriteClips[ 12 ].w =  48;
		jSpriteClips[ 12 ].h =  48;

		jSpriteClips[ 13 ].x =  48;
		jSpriteClips[ 13 ].y = 272;
		jSpriteClips[ 13 ].w =  48;
		jSpriteClips[ 13 ].h =  48;

		jSpriteClips[ 14 ].x = 48;
		jSpriteClips[ 14 ].y = 272;
		jSpriteClips[ 14 ].w =  48;
		jSpriteClips[ 14 ].h =  48;

		jSpriteClips[ 15 ].x =  48;
		jSpriteClips[ 15 ].y =  272;
		jSpriteClips[ 15 ].w =  48;
		jSpriteClips[ 15 ].h =  48;

		jSpriteClips[ 16 ].x = 48;
		jSpriteClips[ 16 ].y =  272;
		jSpriteClips[ 16 ].w =  48;
		jSpriteClips[ 16 ].h =  48;

		jSpriteClips[ 17 ].x =  48;
		jSpriteClips[ 17 ].y =  272;
		jSpriteClips[ 17 ].w =  48;
		jSpriteClips[ 17 ].h =  48;


/* SPRITE TOMBER */
		jSpriteClips[ 18 ].x =  96;
		jSpriteClips[ 18 ].y =  272;
		jSpriteClips[ 18 ].w =  48;
		jSpriteClips[ 18 ].h =  48;

		jSpriteClips[ 19 ].x =  96;
		jSpriteClips[ 19 ].y = 272;
		jSpriteClips[ 19 ].w =  48;
		jSpriteClips[ 19 ].h =  48;

		jSpriteClips[ 20 ].x = 96;
		jSpriteClips[ 20 ].y = 272;
		jSpriteClips[ 20 ].w =  48;
		jSpriteClips[ 20 ].h =  48;

		jSpriteClips[ 21 ].x =  96;
		jSpriteClips[ 21 ].y =  272;
		jSpriteClips[ 21 ].w =  48;
		jSpriteClips[ 21 ].h =  48;

		jSpriteClips[ 22 ].x = 96;
		jSpriteClips[ 22 ].y =  272;
		jSpriteClips[ 22 ].w =  48;
		jSpriteClips[ 22 ].h =  48;

		jSpriteClips[ 23 ].x =  96;
		jSpriteClips[ 23 ].y =  272;
		jSpriteClips[ 23 ].w =  48;
		jSpriteClips[ 23 ].h =  48;

    //SPRITE OBJET DOUBLE SAUT
    jSpriteDoubleSaut.x =  64;
    jSpriteDoubleSaut.y =  256;
    jSpriteDoubleSaut.w =  32;
    jSpriteDoubleSaut.h =  32;
}

GraphicJoueur::~GraphicJoueur(){}

void GraphicJoueur::afficherJoueur(Jeu& jeu, int frame) {


    imageJoueur.x= joueur->pos->getX()*40;
    imageJoueur.y= joueur->pos->getY()*40;
    imageJoueur.w= joueur->taille->getLargeur()*40;
    imageJoueur.h= joueur->taille->getHauteur()*40;
    //SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    //SDL_RenderDrawRect(jeu.renderer, &imageJoueur);

    //SDL_RenderCopy(jeu.renderer, tSprite, &jSpriteClips[frame/6], &imageJoueur);
    SDL_RenderCopy(jeu.renderer, tSprite, &jSpriteClips[frame/6+joueur->getAction()*6], &imageJoueur);

}

void GraphicJoueur::afficherVie(Jeu &jeu) {
    imageVie.clear();
    for (int k=0; k<joueur->getVie(); k++) {
        SDL_Rect image;
        image.x= (k+1)*30;
        image.y= 20;
        image.w= 30;
        image.h= 30;
        imageVie.push_back(image);

        SDL_RenderCopy(jeu.renderer, tVie, NULL, &imageVie.at(k));


    }
}

void GraphicJoueur::afficherObjet(Jeu &jeu) {
    imageObjet.clear();
    int k=0;
    if (joueur->getDoubleSaut()) {
        SDL_Rect image;
        image.x= 20;
        image.y= 60;
        image.w= 30;
        image.h= 30;
        imageObjet.push_back(image);

        SDL_RenderCopy(jeu.renderer, tDoubleSaut, &jSpriteDoubleSaut, &imageObjet.at(k));

        k++;
    }
    if (joueur->getFantome()) {
        SDL_Rect image;
        image.x= 40;
        image.y= 40;
        image.w= 40;
        image.h= 40;
        imageObjet.push_back(image);

        SDL_RenderCopy(jeu.renderer, tStar, NULL, &imageObjet.at(k));

        k++;
    }
}


