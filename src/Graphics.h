//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICS_H
#define ENDLESSRUNNERV2_GRAPHICS_H

#include "Fenetre.h"
#include "GraphicJoueur.h"
#include "GraphicTerrain.h"
#include "GraphicObstacle.h"
#include "GraphicObjet.h"
#include <SDL2/SDL.h>

class Graphics {
public:
    GraphicJoueur* joueur;
    GraphicTerrain* terrain;
    GraphicObstacle* obstacle;
    GraphicObjet* objet;
    Jeu jeu;
   // Fenetre fenetre;
    bool saut;
    bool baisser;
    bool relever;
    int frame;
    bool debout;

    //Constructeur de Graphics
    Graphics();

    //Destructeur de Graphics
    ~Graphics();

    void doJeu();
    void afficherGraphics();

    void loop();
};


#endif //ENDLESSRUNNERV2_GRAPHICS_H
