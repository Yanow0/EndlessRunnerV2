#include "GraphicMenu.h"

#include <iostream>
#include <SDL2/SDL_image.h>
using namespace std;

GraphicMenu::GraphicMenu(Jeu& jeu){

    //TEXTURE MAIN MENU
    sMainMenu = IMG_Load("./data/MainMenu.jpg");
    if (!sMainMenu) {
        cout << "Error: cannot load main menu surface" <<endl;
        IMG_GetError();
    }
    tMainMenu = SDL_CreateTextureFromSurface(jeu.renderer, sMainMenu);

    //TEXTURE PAUSE MENU
    sPauseMenu = IMG_Load("./data/PauseMenu.jpg");
    if (!sPauseMenu) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tPauseMenu = SDL_CreateTextureFromSurface(jeu.renderer, sPauseMenu);

    //TEXTURE END GAME MENU
    sEndGameMenu = IMG_Load("./data/EndGameMenu.jpg");
    if (!sEndGameMenu) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tEndGameMenu = SDL_CreateTextureFromSurface(jeu.renderer, sEndGameMenu);

    //TEXTURE END GAME MENU
    sControls = IMG_Load("./data/Controls.jpg");
    if (!sControls) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tControls = SDL_CreateTextureFromSurface(jeu.renderer, sControls);

    //TEXTURE END GAME MENU
    sCredits = IMG_Load("./data/Credits.jpg");
    if (!sCredits) {
        cout << "Error: cannot load pause menu surface" <<endl;
        IMG_GetError();
    }
    tCredits = SDL_CreateTextureFromSurface(jeu.renderer, sCredits);

    //TEXTURE ARROW MENU
    sArrow = IMG_Load("./data/arrow.png");
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
                afficherFleches(jeu);
                break;
            case 1:
                SDL_RenderCopy(jeu.renderer, tPauseMenu, NULL, NULL);
                afficherFleches(jeu);
                break;
            case 2:
                SDL_RenderCopy(jeu.renderer, tEndGameMenu, NULL, NULL);
                afficherFleches(jeu);
                break;
            case 3:
                SDL_RenderCopy(jeu.renderer, tControls, NULL, NULL);
                break;
            case 4:
                SDL_RenderCopy(jeu.renderer, tCredits, NULL, NULL);
                break;
    }


}

void GraphicMenu::afficherFleches(Jeu& jeu) {
 switch (pos) {
            case 0:
                arrow={180, 120, 35, 50};
                arrow2={560, 120, 35, 50};
                SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(jeu.renderer, tArrow, NULL, &arrow);
                SDL_RenderCopyEx(jeu.renderer, tArrow, NULL, &arrow2, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;

            case 1:
                arrow={180, 195, 35, 50};
                arrow2={560, 195, 35, 50};
                SDL_SetRenderDrawColor(jeu.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderCopy(jeu.renderer, tArrow, NULL, &arrow);
                SDL_RenderCopyEx(jeu.renderer, tArrow, NULL, &arrow2, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;

            case 2:
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
                            currentMenu=3;
                            menuState=true;
                            jeu.restart();
                            pos=0;
                            break;

                        case 2:
                            // CREDITS
                            currentMenu=4;
                            menuState=true;
                            jeu.restart();
                            pos=0;
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
                            pos=0;
                            break;

                        case 2:
                            //MAIN MENU
                            currentMenu=0;
                            menuState=true;
                            jeu.restart();
                            pos=0;
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
                            currentMenu=0;
                            menuState=true;
                            jeu.restart();
                            pos=0;
                            break;

                        case 2:
                            // CREDITS
                            currentMenu=4;
                            menuState=true;
                            jeu.restart();
                            pos=0;
                            break;


                }
                break;
            case 3:
                currentMenu=0;
                menuState=true;
                jeu.restart();
                pos=0;
                break;

            case 4:
                currentMenu=0;
                menuState=true;
                jeu.restart();
                pos=0;
                break;
    }
}
