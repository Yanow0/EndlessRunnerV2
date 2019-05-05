#ifndef GRAPHICMENU_H
#define GRAPHICMENU_H

#include "Jeu.h"


class GraphicMenu
{
    public:
        GraphicMenu(Jeu jeu);
        ~GraphicMenu();

        SDL_Color color;
        SDL_Surface *sMainMenu;
        SDL_Texture *tMainMenu;
        SDL_Surface *sPauseMenu;
        SDL_Texture *tPauseMenu;
        SDL_Surface *sEndGameMenu;
        SDL_Texture *tEndGameMenu;
        SDL_Surface *sArrow;
        SDL_Texture *tArrow;
        SDL_Rect arrow;
        bool menuState;
        int currentMenu;
        void handleMenu(Jeu& jeu);
        void afficherMenu(Jeu& jeu);

        int pos;

    private:
};

#endif // GRAPHICMENU_H
