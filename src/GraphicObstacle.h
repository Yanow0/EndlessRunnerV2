#ifndef ENDLESSRUNNERV2_GRAPHICOBSTACLE_H
#define ENDLESSRUNNERV2_GRAPHICOBSTACLE_H

#include <SDL2/SDL_image.h>
#include "Jeu.h"
#include <vector>

class GraphicObstacle {
public:
    ListeObstacles* obstacle; //!< Pointeur de type ListeObstacles
    vector<SDL_Rect> imageObstacle; //!< Tableau Dynamique de type SDL_Rect, contient les hitbox des obstacles.
    SDL_Surface *sBullet; //!< Pointeur de type SDL_Surface, représente la surface du sprite de l'obstacle
    SDL_Texture *tBullet; //!< Pointeur de type SDL_Texture, représente la texture du sprite du joueur
    SDL_Rect jSpriteClips[ 12 ]; //!< Tableau de type SDL_Rect, contient les différents sprites pour animer l'obstacle
//    SDL_Rect imageObstacle;

    //Constructeur de Jeu
    //! Constructeur de GraphicObstacle avec 1 paramètre
    /*!
        Initialise les variables membres de GraphicObstacle, créer la texture des obstacles.
      \param jeu passage en référence du Jeu en cours.

    */
    GraphicObstacle(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicObstacle();

    //! afficherObstacle, fonction membre de GraphicObstacle avec 2 paramètres
    /*!
        Affiche les obstacles sur le renderer en fonction de leur position, leur forme et de la frame actuelle
      \param jeu passage en référence du Jeu en cours.
      \param frame entier représentant l'image actuelle.
    */
    void afficherObstacle(Jeu& jeu, int frame);
};



#endif //ENDLESSRUNNERV2_GRAPHICOBSTACLE_H