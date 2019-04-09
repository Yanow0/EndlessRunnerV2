//
// Created by Yanis on 24/03/2019.
//

#include "Graphics.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Constructeur de Graphics
Graphics::Graphics(){
    jeu=Jeu();
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) <=0) {
        cout << "Erreur lors de l'initialisation de la SDL_Image : " << SDL_GetError() << endl;IMG_Quit();exit(1);
    }
    // Creation de la fenetre
    jeu.window = SDL_CreateWindow("EndlessRunner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, jeu.getTerrain().getDimX()*40, jeu.getTerrain().getDimY()*40, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (jeu.window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    jeu.renderer = SDL_CreateRenderer(jeu.window,-1,SDL_RENDERER_PRESENTVSYNC);

    jeu.done = SDL_FALSE;


    joueur = new GraphicJoueur(jeu);
    terrain= new GraphicTerrain(jeu);
    obstacle = new GraphicObstacle(jeu);
    frame=0;
    objet = new GraphicObjet(jeu);
    saut=false;


}

//Destructeur de Graphics
Graphics::~Graphics(){
    SDL_DestroyRenderer(jeu.renderer);
    SDL_DestroyWindow(jeu.window);
    IMG_Quit();
    SDL_Quit();
}

void Graphics::doJeu (){
    jeu.actionAutomatique(saut);
    if (saut) jeu.actionClavier('h');
    if (jeu.collisionSol()) saut = false;
}

void Graphics::afficherGraphics() {
    SDL_SetRenderDrawColor(jeu.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(jeu.renderer);
    terrain->afficherTerrain(jeu);
    joueur->afficherJoueur(jeu, frame);
    obstacle->afficherObstacle(jeu);
    objet->afficherObjet(jeu);
}

void Graphics::loop() {

    while (!jeu.done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {


            if (event.type == SDL_QUIT) {
                jeu.done = SDL_TRUE;
            } else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                switch (event.key.keysym.scancode) {

                    case SDL_SCANCODE_LEFT:
                        break;

                    case SDL_SCANCODE_RIGHT:
                        break;

                    case SDL_SCANCODE_UP:
                        saut=true;
                        break;

                    case SDL_SCANCODE_DOWN:
                        break;

                    default:

                        break;
                }   // End switch
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
