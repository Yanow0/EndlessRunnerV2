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
    GraphicJoueur* joueur; //!< Pointeur de type GraphicJoueur
    GraphicTerrain* terrain; //!< Pointeur de type GraphicTerrain
    GraphicObstacle* obstacle; //!< Pointeur de type GraphicObstacle
    GraphicObjet* objet; //!< Pointeur de type GraphicObjet
    GraphicMenu* menu; //!< Pointeur de type GraphicMenu
    Jeu jeu; //!< Variable membre de type Jeu, repr�sente le Jeu en cours
   // Fenetre fenetre;
    bool saut; //!< Variable membre de type booleen, repr�sente l'etat de saut
    bool baisser; //!< Variable membre de type booleen, repr�sente l'etat de baisser
    bool relever; //!< Variable membre de type booleen, repr�sente l'etat de relever
    int frame; //!< Variable membre de type entier, repr�sente l'image actuelle
    int frameObstacle; //!< Variable membre de type entier, repr�sente l'image actuelle pour les obstacles
    bool debout; //!< Variable membre de type booleen, repr�sente l'etat de debout
    bool doublesaut; //!< Variable membre de type booleen, repr�sente l'etat de doublesaut

    //Constructeur de Graphics
    //! Constructeur de GraphicJoueur sans param�tre
    /*!
        Initialise les variables membres de Graphics, cr�er un Jeu, initialise la SDL.
    */
    Graphics();

    //Destructeur de Graphics
    ~Graphics();

    //! doJeu, fonction membre de Graphics sans param�tre
    /*!
        Appelle les fonctions de Graphics en fonction des valeurs des variables membres
    */
    void doJeu();

    //! afficherGraphics, fonction membre de Graphics sans param�tre
    /*!
        Appelle les fonctions d'affichage en fonction de menuState.
    */
    void afficherGraphics();

    //! loop, fonction membre de Graphics sans param�tre
    /*!
        Boucle le Jeu tant qu'il n'est pas quitt�, g�re les �v�nements du clavier, appelle les fonctions doJeu et afficherGraphics.
    */
    void loop();
};


#endif //ENDLESSRUNNERV2_GRAPHICS_H
