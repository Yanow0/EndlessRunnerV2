#ifndef GRAPHICOBJET_H_INCLUDED
#define GRAPHICOBJET_H_INCLUDED

#include <SDL2/SDL_image.h>
#include "Jeu.h"

class GraphicObjet{
public:
    Objet* objet;  //!< Pointeur de type Objet
    SDL_Rect imageObjet; //!< Variable membre de type SDL_Rect, représente la hitbox d'un Objet
    SDL_Surface *sSprite; //!< Pointeur de type SDL_Surface, représente la surface du sprite de l'objet
    SDL_Texture *tSprite; //!< Pointeur de type SDL_Texture, représente la texture du sprite de l'objet
    SDL_Rect jSpriteClips[ 4 ]; //!< Tableau de type SDL_Rect, contient les différents sprites d'objet

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