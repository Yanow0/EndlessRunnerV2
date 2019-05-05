
#ifndef ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
#define ENDLESSRUNNERV2_GRAPHICOBSTACLE_H

#include <SDL2/SDL_image.h>
#include "Jeu.h"


class GraphicObstacle {
public:
    Obstacle obstacle;
    SDL_Rect imageObstacle;

    //Constructeur de Jeu
    GraphicObstacle(Jeu jeu);

    //Destructeur de Jeu
    ~GraphicObstacle();

    void afficherObstacle(Jeu jeu);
};



#endif //ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
