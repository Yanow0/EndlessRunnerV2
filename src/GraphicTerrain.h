//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICTERRAIN_H
#define ENDLESSRUNNERV2_GRAPHICTERRAIN_H

#include "Jeu.h"

class GraphicTerrain {
public:
    Terrain* terrain;
    SDL_Surface *background;
    SDL_Texture *texture;
    //Constructeur de Terrain
    GraphicTerrain(Jeu& jeu);

    //Destructeur de Terrain
    ~GraphicTerrain();

    void afficherTerrain(Jeu jeu);
};


#endif //ENDLESSRUNNERV2_GRAPHICTERRAIN_H
