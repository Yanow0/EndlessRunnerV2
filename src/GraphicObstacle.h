
#ifndef ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
#define ENDLESSRUNNERV2_GRAPHICOBSTACLE_H

#include "Fenetre.h"
#include "Jeu.h"
#include <vector>

class GraphicObstacle {
public:
//    Obstacle obstacle;
    ListeObstacles obstacle;
    vector<SDL_Rect> imageObstacle;
//    SDL_Rect imageObstacle;

    //Constructeur de Jeu
    GraphicObstacle(Jeu jeu);

    //Destructeur de Jeu
    ~GraphicObstacle();

    void afficherObstacle(Jeu jeu);
};



#endif //ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
