#include <iostream>
#include "GraphicObstacle.h"

using namespace std;

GraphicObstacle::GraphicObstacle(Jeu& jeu) {
    obstacle=jeu.getObstacle();

    sBullet = IMG_Load("bullet.png");
    if (!sBullet) {
        cout << "Error: cannot load sprite surface" <<endl;
        IMG_GetError();
    }

    tBullet = SDL_CreateTextureFromSurface(jeu.renderer,sBullet);
     if (tBullet==NULL) {
        cout << "Error: cannot create sprite texture" <<endl;
    }

 // SPRITE BULLET BILL
        jSpriteClips[ 0 ].x =  40;
		jSpriteClips[ 0 ].y =  120;
		jSpriteClips[ 0 ].w =  30;
		jSpriteClips[ 0 ].h =  30;

		jSpriteClips[ 1 ].x =  40;
		jSpriteClips[ 1 ].y =  120;
		jSpriteClips[ 1 ].w =  30;
		jSpriteClips[ 1 ].h =  30;

		jSpriteClips[ 2 ].x =  70;
		jSpriteClips[ 2 ].y = 120;
		jSpriteClips[ 2 ].w =  30;
		jSpriteClips[ 2 ].h =  30;

		jSpriteClips[ 3 ].x =  70;
		jSpriteClips[ 3 ].y = 120;
		jSpriteClips[ 3 ].w =  30;
		jSpriteClips[ 3 ].h =  30;

		jSpriteClips[ 4 ].x = 100;
		jSpriteClips[ 4 ].y = 120;
		jSpriteClips[ 4 ].w =  30;
		jSpriteClips[ 4 ].h =  30;

		jSpriteClips[ 5 ].x = 100;
		jSpriteClips[ 5 ].y = 120;
		jSpriteClips[ 5 ].w =  30;
		jSpriteClips[ 5 ].h =  30;

		jSpriteClips[ 6 ].x =  130;
		jSpriteClips[ 6 ].y =  120;
		jSpriteClips[ 6 ].w =  30;
		jSpriteClips[ 6 ].h =  30;

		jSpriteClips[ 7 ].x =  130;
		jSpriteClips[ 7 ].y =  120;
		jSpriteClips[ 7 ].w =  30;
		jSpriteClips[ 7 ].h =  30;

		jSpriteClips[ 8 ].x = 160;
		jSpriteClips[ 8 ].y =  120;
		jSpriteClips[ 8 ].w =  30;
		jSpriteClips[ 8 ].h =  30;

		jSpriteClips[ 9 ].x = 160;
		jSpriteClips[ 9 ].y =  120;
		jSpriteClips[ 9 ].w =  30;
		jSpriteClips[ 9 ].h =  30;

		jSpriteClips[ 10 ].x =  190;
		jSpriteClips[ 10 ].y =  120;
		jSpriteClips[ 10 ].w =  30;
		jSpriteClips[ 10 ].h =  30;

		jSpriteClips[ 11 ].x =  190;
		jSpriteClips[ 11 ].y =  120;
		jSpriteClips[ 11 ].w =  30;
		jSpriteClips[ 11 ].h =  30;
}

GraphicObstacle::~GraphicObstacle(){}

void GraphicObstacle::afficherObstacle(Jeu& jeu, int frame) {

    imageObstacle.clear();
    for (int k=0; k<obstacle->nbObstacles(); k++) {
        SDL_Rect image;
        image.x= obstacle->getObstacle(k)->pos->getX()*40;
        image.y= obstacle->getObstacle(k)->pos->getY()*40;
        image.w= obstacle->getObstacle(k)->taille->getLargeur()*40;
        image.h= obstacle->getObstacle(k)->taille->getHauteur()*40;
        imageObstacle.push_back(image);

        SDL_RenderCopy(jeu.renderer, tBullet, &jSpriteClips[frame/12], &imageObstacle.at(k));

    }


    //SDL_Rect* imgs = &imageObstacle[0];

   // SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//SDL_RenderFillRects(jeu.renderer, imgs, obstacle->nbObstacles());
}
