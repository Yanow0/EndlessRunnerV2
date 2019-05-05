//
// Created by Yanis on 24/03/2019.
//

#include "Graphics.h"
#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace std;


Graphics::Graphics(): jeu(){

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) <=0) {
        cout << "Erreur lors de l'initialisation de la SDL_Image : " << IMG_GetError() << endl;IMG_Quit();exit(1);
    }
    // Creation de la fenetre
    jeu.window = SDL_CreateWindow("EndlessRunner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, jeu.getTerrain()->getDimX()*40, jeu.getTerrain()->getDimY()*40, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (jeu.window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    jeu.renderer = SDL_CreateRenderer(jeu.window,-1,SDL_RENDERER_PRESENTVSYNC);

    jeu.exit = false;

    menu = new GraphicMenu(jeu);
    joueur=new GraphicJoueur(jeu);
    terrain=new GraphicTerrain(jeu);
    obstacle=new GraphicObstacle(jeu);
    frame=0;
    objet=new GraphicObjet(jeu);
    saut=false;
    baisser=false;
    relever=false;
    debout=true;
    doublesaut=false;
}


//Destructeur de Graphics
Graphics::~Graphics(){
    SDL_DestroyRenderer(jeu.renderer);
    SDL_DestroyWindow(jeu.window);
    IMG_Quit();
    SDL_Quit();
}

void Graphics::doJeu (){
    //cout << "in loop: " << jeu.getJoueur().pos->getY()<< endl;
    if (!menu->menuState) {
        jeu.actionAutomatique(saut);
    }
    if (jeu.getJoueur()->getDoubleSaut() && doublesaut && debout) {
        jeu.actionClavier('x');
        doublesaut=false;
        jeu.getJoueur()->desactiverDoubleSaut();
    }
    if (saut && debout) jeu.actionClavier('h');
    if (jeu.collisionSol()) saut = false;
    if (baisser && !saut) {
            jeu.actionClavier('c');
            baisser=false;
            }
    if (baisser && saut) debout=true;
    if (relever && !saut) {
            jeu.actionClavier('r');
            relever=false;
    }
}

void Graphics::afficherGraphics() {
    SDL_SetRenderDrawColor(jeu.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(jeu.renderer);
    if (menu->menuState){
        menu->afficherMenu(jeu);
    }else{
        terrain->afficherTerrain(jeu);
        joueur->afficherJoueur(jeu, frame);
        obstacle->afficherObstacle(jeu);
        objet->afficherObjet(jeu);
    }
}

void Graphics::loop() {

    while (!jeu.exit) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (menu->menuState){
                  if (event.type == SDL_QUIT) {
                    jeu.exit = true;
                } else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_UP:
                            menu->pos--;
                            if (menu->pos<0){menu->pos=0;}
                            break;

                        case SDL_SCANCODE_DOWN:
                            menu->pos++;
                            if (menu->pos>2){menu->pos=2;}
                            break;

                        case SDL_SCANCODE_RETURN:
                            menu->handleMenu(jeu);
                            menu->menuState=false;
                            break;

                        default:

                            break;
                    }   // End switch

                }
            }else{
                if (event.type == SDL_QUIT) {
                    jeu.exit = true;
                } else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                    switch (event.key.keysym.scancode) {

                        case SDL_SCANCODE_LEFT:
                            break;

                        case SDL_SCANCODE_RIGHT:
                            break;

                        case SDL_SCANCODE_UP:
                            if (!saut) {
                                    saut=true;
                            }  else {
                                    doublesaut=true;
                            }
                            break;

                        case SDL_SCANCODE_DOWN:
                            baisser=true;
                            debout=false;
                            break;

                        case SDL_SCANCODE_ESCAPE:
                            jeu.exit=true;
                            break;

                        case SDL_SCANCODE_P:
                            menu->currentMenu=1;
                            menu->menuState=true;

                        default:

                            break;
                    }   // End switch

                } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
                    switch (event.key.keysym.scancode) {

                        case SDL_SCANCODE_LEFT:
                            break;

                        case SDL_SCANCODE_RIGHT:
                            break;

                        case SDL_SCANCODE_UP:
                            break;

                        case SDL_SCANCODE_DOWN:
                            relever=true;
                            debout=true;
                            break;

                        default:

                            break;
                    }   // End switch
                }

            }
    }
    doJeu();
    afficherGraphics();
    SDL_RenderPresent(jeu.renderer);
    frame++;
    if (frame/6 >= 6 ){
        frame=0;
    }
    }
}
