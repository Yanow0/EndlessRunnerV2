//
// Created by Yanis on 24/03/2019.
//

#ifndef ENDLESSRUNNERV2_FENETRE_H
#define ENDLESSRUNNERV2_FENETRE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Fenetre {

public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int window_width;
    int window_height;
    SDL_bool done;

    Fenetre();
    ~Fenetre();


};


#endif //ENDLESSRUNNERV2_FENETRE_H
