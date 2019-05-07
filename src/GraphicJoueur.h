//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_GRAPHICJOUEUR_H
#define ENDLESSRUNNERV2_GRAPHICJOUEUR_H

#include "Jeu.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class GraphicJoueur {
public:
    Joueur* joueur; //!< Pointeur de type Joueur
    SDL_Rect imageJoueur; //!< Variable membre de type SDL_Rect, repr�sente la hitbox du joueur
    vector<SDL_Rect> imageVie; //!< Tableau Dynamique de type SDL_Rect, repr�sente la hitbox du symbole du coeur
    vector<SDL_Rect> imageObjet; //!< Tableau Dynamique de type SDL_Rect, repr�sente la hitbox du symbole des objets

    SDL_Surface *sSprite; //!< Pointeur de type SDL_Surface, repr�sente la surface du sprite du joueur
    SDL_Texture *tSprite; //!< Pointeur de type SDL_Texture, repr�sente la texture du sprite du joueur
    SDL_Surface *sVie; //!< Pointeur de type SDL_Surface, repr�sente la surface du symbole du coeur
    SDL_Texture *tVie; //!< Pointeur de type SDL_Texture, repr�sente la texture du symbole du coeur
    SDL_Surface *sStar; //!< Pointeur de type SDL_Surface, repr�sente la surface du symbole pour l'objet "Etoile"
    SDL_Texture *tStar; //!< Pointeur de type SDL_Texture, repr�sente la texture du symbole pour l'objet "Etoile"
    SDL_Surface *sDoubleSaut; //!< Pointeur de type SDL_Surface, repr�sente la surface du symbole pour l'objet "Double Saut"
    SDL_Texture *tDoubleSaut; //!< Pointeur de type SDL_Texture, repr�sente la texture du symbole pour l'objet "Double Saut"
    SDL_Surface *sScore; //!< Pointeur de type SDL_Surface, repr�sente la surface du Score
    SDL_Texture *tScore; //!< Pointeur de type SDL_Texture, repr�sente la texture du Score
    TTF_Font *scoreFont; //!< Pointeur de type TTF_Font, repr�sente la police du Score
    SDL_Rect score; //!< Variable membre de type SDL_Rect, repr�sente la case du score
    int texW;  //!< Variable membre de type entier, repr�sente la largeur du score
    int texH; //!< Variable membre de type entier, repr�sente la hauteur du score
    SDL_Rect jSpriteClips[ 24 ]; //!< Tableau de type SDL_Rect, contient les diff�rents sprites pour animer le joueur
    SDL_Rect jSpriteDoubleSaut; //!< Variable membre de type SDL_Rect, contient le symbole pour l'objet "Double Saut"

    //Constructeur de Jeu
    //! Constructeur de GraphicJoueur avec 1 param�tre
    /*!
        Initialise les variables membres de GraphicJoueur, cr�er la texture du joueur.
      \param jeu passage en r�f�rence du Jeu en cours.

    */
    GraphicJoueur(Jeu& jeu);

    //Destructeur de Jeu
    ~GraphicJoueur();

    //! afficherJoueur, fonction membre de GraphicJoueur avec 2 param�tres
    /*!
        Affiche le joueur sur le renderer en fonction de sa position, sa forme et de la frame actuelle
      \param jeu passage en r�f�rence du Jeu en cours.
      \param frame entier repr�sentant l'image actuelle.
    */
    void afficherJoueur(Jeu& jeu, int frame) ;

    //! afficherVie, fonction membre de GraphicJoueur avec 1 param�tre
    /*!
        Affiche en haut � gauche du renderer le nombre de vies du joueur avec un nombre correspondant de symboles de coeur
      \param jeu passage en r�f�rence du Jeu en cours.
    */
    void afficherVie(Jeu& jeu) ;

    //! afficherObjet, fonction membre de GraphicJoueur avec 1 param�tre
    /*!
        Affiche en haut � gauche du renderer les symboles des objets � disposition du joueur
      \param jeu passage en r�f�rence du Jeu en cours.
    */
    void afficherObjet(Jeu& jeu) ;
    void afficherScore(Jeu& jeu) ;
};


#endif //ENDLESSRUNNERV2_GRAPHICJOUEUR_H
