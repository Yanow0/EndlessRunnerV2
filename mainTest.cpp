#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <SDL2/SDL.h>
#include "src/Jeu.h"
#include "src/Graphics.h"
#include <vector>
#include <assert.h>

using namespace std;



int main(int argc, char* argv[]){
    srand (time(NULL));
    Graphics jeuGr;
    jeuGr.jeu.getJoueur()->testRegression();

    return 0;


}

