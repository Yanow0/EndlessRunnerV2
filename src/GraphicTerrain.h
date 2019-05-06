//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICTERRAIN_H
#define ENDLESSRUNNERV2_GRAPHICTERRAIN_H

#include <SDL2/SDL_image.h>
#include "Jeu.h"

class GraphicTerrain {
public:
    Terrain* terrain; //!< Pointeur de type Terrain
    SDL_Surface *background; //!< Pointeur de type SDL_Surface, repr�sente la surface du terrain
    SDL_Texture *texture; //!< Pointeur de type SDL_Texture, repr�sente la texture du sprite du terrain

    //Constructeur de Terrain
    //! Constructeur de GraphicTerrain avec 1 param�tre
    /*!
        Initialise les variables membres de GraphicTerrain, cr�er la texture du terrain.
      \param jeu passage en r�f�rence du Jeu en cours.

    */
    GraphicTerrain(Jeu& jeu);

    //Destructeur de Terrain
    ~GraphicTerrain();

    //! afficherTerrain, fonction membre de GraphicJoueur avec 1 param�tre
    /*!
        Affiche le terrain sur tout le renderer
      \param jeu passage en r�f�rence du Jeu en cours.
    */
    void afficherTerrain(Jeu& jeu);
};


#endif //ENDLESSRUNNERV2_GRAPHICTERRAIN_H
