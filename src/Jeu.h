//
// Created by Yanis on 14/03/2019.
//

#include "Terrain.h"
#include "Joueur.h"
#include "Obstacle.h"
#include "Objet.h"
#include <SDL2/SDL.h>

#ifndef ENDLESSRUNNER_JEU_H
#define ENDLESSRUNNER_JEU_H


class Jeu {

    private:
        Joueur joueur;
        Obstacle obstacle;
        Terrain terrain;
        Objet objet;

    public:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int window_width;
        int window_height;
        SDL_bool done;

        //Constructeur de Jeu
        Jeu();

        //Destructeur de Jeu
        ~Jeu();

        Terrain& getTerrain();
        Joueur& getJoueur();
        Obstacle& getObstacle();
        Objet& getObjet();

        bool contactGauche();
        bool contactDroite();
        bool contactSuperieur();
        bool contactInferieur();

        bool collision();

        void actionClavier(const char &touche);
        void actionAutomatique();
        bool collisionSol();

};


#endif //ENDLESSRUNNER_JEU_H
