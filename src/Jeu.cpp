//
// Created by Yanis on 14/03/2019.
//
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <cstdlib>
//#include <pthread.h>
#include <iostream>
#include "Jeu.h"
using namespace std;

Jeu::Jeu(): joueur(), obstacles(), terrain(), objets() {
}

Jeu::~Jeu(){

}

Terrain* Jeu::getTerrain() {return &terrain;}
Joueur* Jeu::getJoueur() {return &joueur;}
ListeObstacles* Jeu::getObstacle() {return &obstacles;}
//Objet* Jeu::getObjet() {return &objet;}
ListeObjet* Jeu::getObjet(){return &objets;}

// l'obstacle en contact avec le cote gauche du joueur
bool Jeu::contactGauche(const Obstacle *o) const{
    return (o->pos->getX() <= joueur.pos->getX()
        && (o->pos->getX() + o->taille->getLargeur() >= joueur.pos->getX()));
}

bool Jeu::contactDroite(const Obstacle *o) const{
    return (joueur.pos->getX() <= o->pos->getX()
        && (joueur.pos->getX() + joueur.taille->getLargeur() - 0.8 >= o->pos->getX()));
}

bool Jeu::contactSuperieur(const Obstacle *o) const{
    return (o->pos->getY() <= joueur.pos->getY()
        && (o->pos->getY() + o->taille->getHauteur() >= joueur.pos->getY() + 0.5));
}

bool Jeu::contactInferieur(const Obstacle *o) const{
    return (joueur.pos->getY() <= o->pos->getY()
        && (joueur.pos->getY() + joueur.taille->getHauteur() >= o->pos->getY()));
}


bool Jeu::collision(const bool saut) {
//    for (int i=0; i<obstacles.nbObstacles(); i++) {
//        Obstacle *o = obstacles.getObstacle(i);
//
//        if ((contactGauche(o) && (contactSuperieur(o)))
//        || (contactDroite(o) && (contactSuperieur(o)))) {
//            return true;
//        }
//
//        else if (saut && ((contactGauche(o) && contactInferieur(o))
//                        || (contactDroite(o) && contactInferieur(o)))) {
//
//            joueur.pos->setY(o->pos->getY()-joueur.taille->getHauteur());
//            return false;
//        }
//    }
//    return false;


    for (int i=0; i<obstacles.nbObstacles(); i++) {
        Obstacle *o = obstacles.getObstacle(i);
        if ((contactGauche(o) && (contactSuperieur(o) || contactInferieur(o)))
        || (contactDroite(o) && (contactSuperieur(o) || contactInferieur(o)))) {
            return true;
        }
    }
    return false;
}


void Jeu::actionClavier(const char &touche) {
	switch(touche) {
		case 'h' :
				joueur.sauter(terrain);
				break;
        case 'c' :
                joueur.baisser(terrain);
                break;
        case 'r' :
            joueur.relever(terrain);
            break;
        case 'x' :
				joueur.doubleSauter(terrain);
				break;
	}
}

bool Jeu::collisionSol() {
    if (joueur.pos->getY() + joueur.taille->getHauteur() >= terrain.getPlateforme()){
            joueur.pos->setY(terrain.getPlateforme() -  joueur.taille->getHauteur());

       // cout << "sol" << endl;
        return true;
    }
    else return false;

}


void Jeu::actionAutomatique(bool &saut) {
    obstacles.deplacementAuto();
    objets.deplacementAuto();

    if (!saut) joueur.retomber(terrain);
    if (collision(saut)) {
        cout << "collision" << endl;
        joueur.vieDown();
        cout << "vie = " << joueur.getVie() << endl;

        saut = false;
        joueur = Joueur(joueur.getVie());
        obstacles.vider();
//        objet = Objet();

        #ifdef _WIN32
        Sleep(500);
		#else
		usleep(500000);
        #endif // WIN32
    }
}


void Jeu::restart(){
    terrain = Terrain();
    joueur = Joueur();
    obstacles = ListeObstacles();
    objets = ListeObjet();
}

