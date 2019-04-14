#ifndef GRAPHICOBJET_H_INCLUDED
#define GRAPHICOBJET_H_INCLUDED

#include "Fenetre.h"
#include "Jeu.h"

class GraphicObjet{
public:
    Objet objet;
    SDL_Rect imageObjet;
    SDL_Surface *sSprite;
    SDL_Texture *tSprite;

    //Constructeur de Jeu
    GraphicObjet(Jeu jeu);

    //Destructeur de Jeu
    ~GraphicObjet();

    void afficherObjet(Jeu jeu);
};

#endif // GRAPHICOBJET_H_INCLUDED