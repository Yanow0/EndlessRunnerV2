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
        Objet* getObjet();

        bool contactGauche(Obstacle *o);
        bool contactDroite(Obstacle *o);
        bool contactSuperieur(Obstacle *o);
        bool contactInferieur(Obstacle *o);

        bool collision(bool saut);

        void actionClavier(const char &touche);
        void actionAutomatique(bool saut);
        bool collisionSol();

};


#endif //ENDLESSRUNNER_JEU_H
