//
// Created by Yanis on 14/03/2019.
//

#include "Terrain.h"
#include "Joueur.h"
#include "Obstacle.h"
#include "ListeObstacles.h"
#include "Objet.h"
#include <SDL2/SDL.h>

#ifndef ENDLESSRUNNER_JEU_H
#define ENDLESSRUNNER_JEU_H


class Jeu {

    private:
        Joueur joueur;
        ListeObstacles obstacles;
//        Obstacle obstacle;
        Terrain terrain;
        Objet objet;

    public:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int window_width;
        int window_height;
        bool exit;

        //Constructeur de Jeu
        Jeu();

        //Destructeur de Jeu
        ~Jeu();

        Terrain* getTerrain();
        Joueur* getJoueur();
        ListeObstacles* getObstacle();
//        Obstacle& getObstacle();
        Objet& getObjet();

        bool contactGauche();
        bool contactDroite();
        bool contactSuperieur();
        bool contactInferieur();

        bool collision();

        void actionClavier(const char &touche);
        void actionAutomatique(bool saut);
        bool collisionSol();

};


#endif //ENDLESSRUNNER_JEU_H
