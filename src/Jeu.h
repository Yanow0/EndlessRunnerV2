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
        Joueur joueur; //!< Variable membre de type Joueur, repr�sente le Joueur actuel
        ListeObstacles obstacles; //!< Variable membre de type ListeObstacles, repr�sente la ListeObstacles actuelle
        Terrain terrain; //!< Variable membre de type Terrain, repr�sente le Terrain actuel
        ListeObjet objets; //!< Variable membre de type ListeObjet, repr�sente la liseObjets actuelle

    public:
        SDL_Window* window; //!< Pointeur de type SDL_Window
        SDL_Renderer* renderer; //!< Pointeur de type SDL_Renderer
        //int window_width;
        //int window_height;
        bool exit; //!< Variable membre de type booleen, d�fini si le jeu est quitt� ou non

        //Constructeur de Jeu
        //! Constructeur de Jeu sans param�tre
        /*!
            Cr�er un Joueur, un Terrain, des Obstacles et des Objets.
        */
        Jeu();

        //Destructeur de Jeu
        ~Jeu();

        //! restart, procedure membre de Jeu sans param�tre
        /*!
            R�initialise le Joueur, le Terrain, les Obstacles et les Objets.
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

        //! contactGauche, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te gauche du joueur entre en collision avec un obstacle
        */
        bool contactGauche(const Obstacle *o) const;

        //! contactGaucheObjet, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te gauche du joueur entre en collision avec un objet
        */
        bool contactGaucheObjet(const Objet *o) const;

        //! contactDroite, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te droit du joueur entre en collision avec un obstacle
        */
        bool contactDroite(const Obstacle *o) const;

        //! contactGaucheObjet, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te droit du joueur entre en collision avec un objet
        */
        bool contactDroiteObjet(const Objet *o) const;

        //! contactSuperieur, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te superieur du joueur entre en collision avec un obstacle
        */
        bool contactSuperieur(const Obstacle *o) const;

        //! contactGaucheObjet, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te sup�rieur du joueur entre en collision avec un objet
        */
        bool contactSuperieurObjet(const Objet *o) const;

        //! contactInferieur, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te inferieur du joueur entre en collision avec un obstacle
        */
        bool contactInferieur(const Obstacle *o) const;

        //! contactGaucheObjet, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le c�te inferieur du joueur entre en collision avec un objet
        */
        bool contactInferieurObjet(const Objet *o) const;

        //! collision, fonction membre de Jeu avec 1 param�tre
        /*!
            Retourne vrai si le joueur entre en collision avec un obstacle
            \param saut booleen repr�sentant l'�tat actuel du saut
        */
        bool collision(const bool saut);

        //! collision, fonction membre de Jeu avec 1 param�tre
        /*!
            Retourne vrai si le joueur entre en collision avec un objet
            \param saut booleen repr�sentant l'�tat actuel du saut
        */
        bool collisionObjet(const bool saut);

        //! actionClavier, procedure membre de Jeu avec 1 param�tre
        /*!
            Effectue l'action de Jeu en fonction du param�tre touche
            \param touche char repr�sentant la touche de clavier enfonc�
        */
        void actionClavier(const char &touche);

        //! actionAutomatique, fonction membre de Jeu avec 1 param�tre
        /*!
            Appelle les fonctions qui ne d�pendent pas des actions du clavier, deplacementAuto et collision
            \param saut booleen repr�sentant l'�tat actuel du saut
        */
        void actionAutomatique(bool &saut);

        //! collisionSol, fonction membre de Jeu sans param�tre
        /*!
            Retourne vrai si le joueur entre en collision avec le sol
        */
        bool collisionSol();

};


#endif //ENDLESSRUNNER_JEU_H
