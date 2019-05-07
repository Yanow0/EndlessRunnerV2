#ifndef GRAPHICOBJET_H_INCLUDED
#define GRAPHICOBJET_H_INCLUDED

#include <SDL2/SDL_image.h>
#include "Jeu.h"

class GraphicObjet{
public:
    ListeObjet* objet;  //!< Pointeur de type ListeObjet
    vector<SDL_Rect> imageObjet; //!< Tableau Dynamique de type SDL_Rect, contient les hitbox des obstacles.
    //SDL_Rect imageObjet; //!< Variable membre de type SDL_Rect, représente la hitbox d'un Objet
    SDL_Surface *sSprite; //!< Pointeur de type SDL_Surface, représente la surface du sprite de l'objet chaussures
    SDL_Texture *tSprite; //!< Pointeur de type SDL_Texture, représente la texture du sprite de l'objet chaussures

    SDL_Surface *sStar; //!< Pointeur de type SDL_Surface, représente la surface du sprite de l'objet étoile
    SDL_Texture *tStar; //!< Pointeur de type SDL_Texture, représente la texture du sprite de l'objet étoile

    SDL_Surface *sHeart; //!< Pointeur de type SDL_Surface, représente la surface du sprite de l'objet coeur
    SDL_Texture *tHeart; //!< Pointeur de type SDL_Texture, représente la texture du sprite de l'objet coeur

    SDL_Rect jSpriteClips[ 1 ]; //!< Tableau de type SDL_Rect, contient les différents sprites d'objet

    //Constructeur de Jeu
    //! Constructeur de GraphicObjet avec 1 paramètre
    /*!
        Initialise les variables membres de GraphicObjet, créer la texture de l'objet.
      \param jeu passage en référence du Jeu en cours.

    */
    GraphicObjet(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicObjet();

    //! afficherObjet, fonction membre de GraphicObjet avec 1 paramètre
    /*!
        Affiche l'objet sur le renderer en fonction de sa position, sa forme et de son type.
      \param jeu passage en référence du Jeu en cours.
      \param frame entier représentant l'image actuelle.
    */
    void afficherObjet(Jeu& jeu);
};

#endif // GRAPHICOBJET_H_INCLUDED
