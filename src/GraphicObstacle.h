
#ifndef ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
#define ENDLESSRUNNERV2_GRAPHICOBSTACLE_H

#include "Fenetre.h"
#include "Jeu.h"
#include <vector>

class GraphicObstacle {
public:
    ListeObstacles* obstacle;
    vector<SDL_Rect> imageObstacle;
    SDL_Surface *sSprite;
    SDL_Texture *tSprite;

    //Constructeur de Jeu
    GraphicObstacle(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicObstacle();

    void afficherObstacle(Jeu jeu);
};



#endif //ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
