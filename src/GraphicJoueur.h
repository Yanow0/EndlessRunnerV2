//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICJOUEUR_H
#define ENDLESSRUNNERV2_GRAPHICJOUEUR_H

#include "Jeu.h"
#include <SDL2/SDL_image.h>

class GraphicJoueur {
public:
    Joueur* joueur; //!< Pointeur de type Joueur
    SDL_Rect imageJoueur; //!< Variable membre de type SDL_Rect, représente la hitbox du joueur
    vector<SDL_Rect> imageVie; //!< Tableau Dynamique de type SDL_Rect, représente la hitbox du symbole du coeur
    vector<SDL_Rect> imageObjet; //!< Tableau Dynamique de type SDL_Rect, représente la hitbox du symbole des objets

    SDL_Surface *sSprite; //!< Pointeur de type SDL_Surface, représente la surface du sprite du joueur
    SDL_Texture *tSprite; //!< Pointeur de type SDL_Texture, représente la texture du sprite du joueur
    SDL_Surface *sVie; //!< Pointeur de type SDL_Surface, représente la surface du symbole du coeur
    SDL_Texture *tVie; //!< Pointeur de type SDL_Texture, représente la texture du symbole du coeur
    SDL_Surface *sStar; //!< Pointeur de type SDL_Surface, représente la surface du symbole pour l'objet "Etoile"
    SDL_Texture *tStar; //!< Pointeur de type SDL_Texture, représente la texture du symbole pour l'objet "Etoile"
    SDL_Surface *sDoubleSaut; //!< Pointeur de type SDL_Surface, représente la surface du symbole pour l'objet "Double Saut"
    SDL_Texture *tDoubleSaut; //!< Pointeur de type SDL_Texture, représente la texture du symbole pour l'objet "Double Saut"
    SDL_Rect jSpriteClips[ 24 ]; //!< Tableau de type SDL_Rect, contient les différents sprites pour animer le joueur
    SDL_Rect jSpriteDoubleSaut; //!< Variable membre de type SDL_Rect, contient le symbole pour l'objet "Double Saut"

    //Constructeur de Jeu
    //! Constructeur de GraphicJoueur avec 1 paramètre
    /*!
        Initialise les variables membres de GraphicJoueur, créer la texture du joueur.
      \param jeu passage en référence du Jeu en cours.

    */
    GraphicJoueur(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicJoueur();

    //! afficherJoueur, fonction membre de GraphicJoueur avec 2 paramètres
    /*!
        Affiche le joueur sur le renderer en fonction de sa position, sa forme et de la frame actuelle
      \param jeu passage en référence du Jeu en cours.
      \param frame entier représentant l'image actuelle.
    */
    void afficherJoueur(Jeu& jeu, int frame) ;

    //! afficherVie, fonction membre de GraphicJoueur avec 1 paramètre
    /*!
        Affiche en haut à gauche du renderer le nombre de vies du joueur avec un nombre correspondant de symboles de coeur
      \param jeu passage en référence du Jeu en cours.
    */
    void afficherVie(Jeu& jeu) ;

    //! afficherObjet, fonction membre de GraphicJoueur avec 1 paramètre
    /*!
        Affiche en haut à gauche du renderer les symboles des objets à disposition du joueur
      \param jeu passage en référence du Jeu en cours.
    */
    void afficherObjet(Jeu& jeu) ;
};


#endif //ENDLESSRUNNERV2_GRAPHICJOUEUR_H
