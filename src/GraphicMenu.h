#ifndef GRAPHICMENU_H
#define GRAPHICMENU_H

#include "Jeu.h"


class GraphicMenu
{
    public:
        GraphicMenu(Jeu& jeu);
        ~GraphicMenu();

        SDL_Color color;
        SDL_Surface *sMainMenu;
        SDL_Texture *tMainMenu;
        SDL_Surface *sPauseMenu;
        SDL_Texture *tPauseMenu;
        SDL_Surface *sEndGameMenu;
        SDL_Texture *tEndGameMenu;
        SDL_Surface *sControls;
        SDL_Texture *tControls;
        SDL_Surface *sCredits;
        SDL_Texture *tCredits;
        SDL_Surface *sArrow;
        SDL_Texture *tArrow;
        SDL_Rect arrow;
        SDL_Rect arrow2;
        bool menuState;
        int currentMenu;
        void handleMenu(Jeu& jeu);
        void afficherFleches(Jeu& jeu);
        void afficherMenu(Jeu& jeu);

        int pos;

    private:
};

#endif // GRAPHICMENU_H
