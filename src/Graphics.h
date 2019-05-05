//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICS_H
#define ENDLESSRUNNERV2_GRAPHICS_H

#include "GraphicJoueur.h"
#include "GraphicTerrain.h"
#include "GraphicObstacle.h"
#include "GraphicObjet.h"
#include "GraphicMenu.h"
#include <SDL2/SDL.h>


class Graphics {
public:
    GraphicJoueur* joueur;
    GraphicTerrain* terrain;
    GraphicObstacle* obstacle;
    GraphicObjet* objet;
    GraphicMenu* menu;
    Jeu jeu;
   // Fenetre fenetre;
    bool saut;
    bool baisser;
    bool relever;
    int frame;
    bool debout;
    bool doublesaut;

    //Constructeur de Graphics
    Graphics();

    //Destructeur de Graphics
    ~Graphics();
    void startGame();
    void doJeu();
    void afficherGraphics();

    void loop();
};


#endif //ENDLESSRUNNERV2_GRAPHICS_H
