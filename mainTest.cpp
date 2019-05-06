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

/*

int main(int argc, char* argv[]){
    srand (time(NULL));
    Graphics jeuGr;
    //Terrain& t = jeuGr.jeu.getTerrain();

    //TESTS JOUEUR
    assert (jeuGr.jeu.getJoueur()->pos->getX()==8);
    cout << "\npos x initiale joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->pos->getY()==7);
    cout << "pos y initiale joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->getVie()==3);
    cout << "vie initiale joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->getFantome()==false);
    cout << "fantome initial joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->getDoubleSaut()==false);
    cout << "double saut initial joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->vitesseSaut==0.5);
    cout << "vitesseSaut initiale joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->gravite==0.025f);
    cout << "gravite initiale joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->getAction()==0);
    cout << "action initiale joueur ok" << endl;

    jeuGr.jeu.getJoueur()->pos->setX(1);
    assert (jeuGr.jeu.getJoueur()->pos->getX()==1);
    cout << "\npos x après set joueur ok" << endl;
    jeuGr.jeu.getJoueur()->pos->setY(1);
    assert (jeuGr.jeu.getJoueur()->pos->getY()==1);
    cout << "pos y après set joueur ok" << endl;
    jeuGr.jeu.getJoueur()->setVie(1);
    assert (jeuGr.jeu.getJoueur()->getVie()==1);
    cout << "vie après set joueur ok" << endl;
    jeuGr.jeu.getJoueur()->activerFantome();
    assert (jeuGr.jeu.getJoueur()->getFantome()==true);
    cout << "fantome apres activer joueur ok" << endl;
    jeuGr.jeu.getJoueur()->activerDoubleSaut();
    assert (jeuGr.jeu.getJoueur()->getDoubleSaut()==true);
    cout << "double saut apres activer joueur ok" << endl;
    jeuGr.jeu.getJoueur()->setAction(1);
    assert (jeuGr.jeu.getJoueur()->getAction()==1);
    cout << "action apres set joueur ok" << endl;
     jeuGr.jeu.getJoueur()->sauter(t);
    assert (jeuGr.jeu.getJoueur()->pos->getY()==1-0.5);
    cout << "pos y après sauter joueur ok" << endl;
    assert (jeuGr.jeu.getJoueur()->vitesseSaut==0.5-0.025f);
    cout << "pos y après sauter joueur ok" << endl;



    return 0;


}
*/
