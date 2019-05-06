#ifndef GRAPHICMENU_H
#define GRAPHICMENU_H

#include "Jeu.h"


class GraphicMenu
{
    public:
        GraphicMenu(Jeu& jeu);
        ~GraphicMenu();

        SDL_Color color;
        SDL_Surface *sMainMenu; //!< Pointeur de type SDL_Surface, repr�sente la surface du Main Menu
        SDL_Texture *tMainMenu; //!< Pointeur de type SDL_Texture, repr�sente la texture du Main Menu
        SDL_Surface *sPauseMenu; //!< Pointeur de type SDL_Surface, repr�sente la surface du Pause Menu
        SDL_Texture *tPauseMenu; //!< Pointeur de type SDL_Texture, repr�sente la texture du Pause Menu
        SDL_Surface *sEndGameMenu; //!< Pointeur de type SDL_Surface, repr�sente la surface du End Game Menu
        SDL_Texture *tEndGameMenu; //!< Pointeur de type SDL_Texture, repr�sente la texture du End Game Menu
        SDL_Surface *sControls; //!< Pointeur de type SDL_Surface, repr�sente la surface des Controls
        SDL_Texture *tControls; //!< Pointeur de type SDL_Texture, repr�sente la texture des Controls
        SDL_Surface *sCredits; //!< Pointeur de type SDL_Surface, repr�sente la surface des Credits
        SDL_Texture *tCredits; //!< Pointeur de type SDL_Texture, repr�sente la texture des Credits
        SDL_Surface *sArrow; //!< Pointeur de type SDL_Surface, repr�sente la surface des fleches du menu
        SDL_Texture *tArrow; //!< Pointeur de type SDL_Texture, repr�sente la texture des fleches du menu
        SDL_Rect arrow; //!< Variable membre de type SDL_Rect, repr�sente la forme et la position de la fleche de gauche
        SDL_Rect arrow2; //!< Variable membre de type SDL_Rect, repr�sente la forme et la position de la fleche de droite
        bool menuState; //!< Variable membre de type booleen, repr�sente l'�tat du menu
        int currentMenu; //!< Variable membre de type entier, repr�sente le menu actuel

        //! handleMenu, fonction membre de GraphicMenu avec 1 param�tre
        /*!
            G�re l'action � r�aliser en fonction du menu actuel et de la position des fl�ches dans le menu.
            \param jeu passage en r�f�rence du Jeu en cours.
        */
        void handleMenu(Jeu& jeu);

        //! afficherFleches, fonction membre de GraphicMenu avec 1 param�tre
        /*!
            Affiche les fl�ches sur le renderer en fonction de pos.
            \param jeu passage en r�f�rence du Jeu en cours.
        */
        void afficherFleches(Jeu& jeu);

        //! afficherMenu, fonction membre de GraphicMenu avec 1 param�tre
        /*!
            Affiche le menu actuel sur le renderer en fonction de currentMenu.
            Affiche les fl�ches sur le renderer en fonction de pos.
            \param jeu passage en r�f�rence du Jeu en cours.
        */
        void afficherMenu(Jeu& jeu);

        int pos; //!< Variable membre de type entier, repr�sentant la position des fl�ches dans le menu.

    private:
};

#endif // GRAPHICMENU_H
