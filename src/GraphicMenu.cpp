#include "GraphicMenu.h"

#include <iostream>
#include <SDL2/SDL_image.h>
using namespace std;

GraphicMenu::GraphicMenu(Jeu jeu){

    //TEXTURE MAIN MENU
    sMainMenu = IMG_Load("MainMenu.jpg");
    if (!sMainMenu) {
        cout << "Error: cannot load main menu surface" <<endl;
        IMG_GetError();
    }
    tMainMenu = SDL_CreateTextureFromSurface(jeu.renderer, sMainMenu);

    //TEXTURE PAUSE MENU
    sPauseMenu = IMG_Load("PauseMenu.jpg");
    if (!sPauseMenu) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tPauseMenu = SDL_CreateTextureFromSurface(jeu.renderer, sPauseMenu);

    //TEXTURE END GAME MENU
    sEndGameMenu = IMG_Load("EndGameMenu.jpg");
    if (!sEndGameMenu) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tEndGameMenu = SDL_CreateTextureFromSurface(jeu.renderer, sEndGameMenu);

    sArrow = IMG_Load("arrow.png");
    if (!sArrow) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tArrow = SDL_CreateTextureFromSurface(jeu.renderer, sArrow);

    arrow={200, 100, 35, 35};
    arrow2={400, 150, 35, 35};
    currentMenu = 0;
    menuState=true;
    pos=0;
}

GraphicMenu::~GraphicMenu(){
    //dtor
}

void GraphicMenu::afficherMenu(Jeu& jeu) {
    switch (currentMenu) {
            case 0:
                SDL_RenderCopy(jeu.renderer, tMainMenu, NULL, NULL);
                break;
            case 1:
                SDL_RenderCopy(jeu.renderer, tPauseMenu, NULL, NULL);
                break;
            case 2:
                SDL_RenderCopy(jeu.renderer, tEndGameMenu, NULL, NULL);
                break;
    }
    switch (pos) {
            case 0:
                // PLAY AGAIN
                arrow={180, 120, 35, 50};
                arrow2={560, 120, 35, 50};
                SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(jeu.renderer, tArrow, NULL, &arrow);
                SDL_RenderCopyEx(jeu.renderer, tArrow, NULL, &arrow2, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;

            case 1:
                // MAIN MENU
                arrow={180, 195, 35, 50};
                arrow2={560, 195, 35, 50};
                SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(jeu.renderer, tArrow, NULL, &arrow);
                SDL_RenderCopyEx(jeu.renderer, tArrow, NULL, &arrow2, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;

            case 2:
                // CREDITS
                arrow={180, 270, 35, 50};
                arrow2={560, 270, 35, 50};
                SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(jeu.renderer, tArrow, NULL, &arrow);
                SDL_RenderCopyEx(jeu.renderer, tArrow, NULL, &arrow2, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;
    }

}

void GraphicMenu::handleMenu(Jeu& jeu) {
    switch (currentMenu) {
            case 0:
                switch (pos) {
                        case 0:
                            // PLAY
                            break;

                        case 1:
                            // CONTROLS
                            break;

                        case 2:
                            // CREDITS
                            break;
                }
                break;

            case 1:
                switch (pos) {
                        case 0:
                            //CONTINUE
                            break;

                        case 1:
                            // PLAY AGAIN
                            jeu.restart();
                            break;

                        case 2:
                            //MAIN MENU
                            break;
                }
                break;

            case 2:
                switch (pos) {
                        case 0:
                            // PLAY AGAIN
                            jeu.restart();
                            break;

                        case 1:
                            // MAIN MENU
                            break;

                        case 2:
                            // CREDITS
                            break;


                }
                break;
    }
}
