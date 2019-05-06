//
// Created by Yanis on 14/03/2019.
//

#include "Terrain.h"
#include "Joueur.h"
#include "Obstacle.h"
#include "ListeObstacles.h"
#include "ListeObjet.h"
#include "Objet.h"
#include <SDL2/SDL.h>

#ifndef ENDLESSRUNNER_JEU_H
#define ENDLESSRUNNER_JEU_H


class Jeu {

    private:
        Joueur joueur; //!< Variable membre de type Joueur, représente le Joueur actuel
        ListeObstacles obstacles; //!< Variable membre de type ListeObstacles, représente la ListeObstacles actuelle
        Terrain terrain; //!< Variable membre de type Terrain, représente le Terrain actuel
        //Objet objet; //!< Variable membre de type Objet, représente l'Objet actuel
        ListeObjet objets; //!< Variable membre de type ListeObjet, représente la liseObjets actuelle

    public:
        SDL_Window* window; //!< Pointeur de type SDL_Window
        SDL_Renderer* renderer; //!< Pointeur de type SDL_Renderer
        //int window_width;
        //int window_height;
        bool exit; //!< Variable membre de type booleen, défini si le jeu est quitté ou non

        //Constructeur de Jeu
        //! Constructeur de Jeu sans paramètre
        /*!
            Créer un Joueur, un Terrain, des Obstacles et des Objets.
        */
        Jeu();

        //Destructeur de Jeu
        ~Jeu();

        //! restart, procedure membre de Jeu sans paramètre
        /*!
            Réinitialise le Joueur, le Terrain, les Obstacles et les Objets.
        */
        void restart();

        //! Getter de terrain de Jeu
        /*!
            Retourne le Terrain terrain du Jeu.
        */
        Terrain* getTerrain();

        //! Getter de joueur de Jeu
        /*!
            Retourne le Joueur joueur du Jeu.
        */
        Joueur* getJoueur();

        //! Getter de obstacles de Jeu
        /*!
            Retourne la ListeObstacles obstacles du Jeu.
        */
        ListeObstacles* getObstacle();

        //! Getter de joueur de Jeu
        /*!
            Retourne la ListeObjets Objets du Jeu.
        */
        ListeObjet* getObjet();

        //! contactGauche, fonction membre de Jeu sans paramètre
        /*!
            Retourne vrai si le côte gauche du joueur entre en collision avec un objet
        */
        bool contactGauche(const Obstacle *o) const;

        //! contactDroite, fonction membre de Jeu sans paramètre
        /*!
            Retourne vrai si le côte droit du joueur entre en collision avec un objet
        */
        bool contactDroite(const Obstacle *o) const;

        //! contactSuperieur, fonction membre de Jeu sans paramètre
        /*!
            Retourne vrai si le côte superieur du joueur entre en collision avec un objet
        */
        bool contactSuperieur(const Obstacle *o) const;

        //! contactInferieur, fonction membre de Jeu sans paramètre
        /*!
            Retourne vrai si le côte inferieur du joueur entre en collision avec un objet
        */
        bool contactInferieur(const Obstacle *o) const;

        //! collision, fonction membre de Jeu sans 1 paramètre
        /*!
            Retourne vrai si le joueur entre en collision avec un objet
        */
        bool collision();

        //! actionClavier, procedure membre de Jeu avec 1 paramètre
        /*!
            Effectue l'action de Jeu en fonction du paramètre touche
            \param touche char représentant la touche de clavier enfoncé
        */
        void actionClavier(const char &touche);

        //! actionAutomatique, fonction membre de Jeu avec 1 paramètre
        /*!
            Appelle les fonctions qui ne dépendent pas des actions du clavier, deplacementAuto et collision
            \param saut booleen représentant l'état actuel du saut
        */
        void actionAutomatique(bool &saut);

        //! collisionSol, fonction membre de Jeu sans paramètre
        /*!
            Retourne vrai si le joueur entre en collision avec le sol
        */
        bool collisionSol();

};


#endif //ENDLESSRUNNER_JEU_H
