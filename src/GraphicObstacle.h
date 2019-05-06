#ifndef ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
#define ENDLESSRUNNERV2_GRAPHICOBSTACLE_H

#include <SDL2/SDL_image.h>
#include "Jeu.h"
#include <vector>

class GraphicObstacle {
public:
    ListeObstacles* obstacle;
    vector<SDL_Rect> imageObstacle;
    SDL_Surface *sBullet;
    SDL_Texture *tBullet;
    SDL_Rect jSpriteClips[ 12 ];
//    SDL_Rect imageObstacle;

    //Constructeur de Jeu
    GraphicObstacle(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicObstacle();

    void afficherObstacle(Jeu& jeu, int frame);
};



#endif //ENDLESSRUNNERV2_GRAPHICOBSTACLE_H