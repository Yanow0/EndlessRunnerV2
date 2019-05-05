//
// Created by Yanis on 14/03/2019.
//
#include <cstdlib>
#include <iostream>
#include "Jeu.h"
using namespace std;

Jeu::Jeu(): joueur(), obstacles(), terrain(), objet() {
}

Jeu::~Jeu(){

}

Terrain* Jeu::getTerrain() {return &terrain;}
Joueur* Jeu::getJoueur() {return &joueur;}
ListeObstacles* Jeu::getObstacle() {return &obstacles;}
Objet* Jeu::getObjet() {return &objet;}

// l'obstacle en contact avec le côté gauche du joueur
bool Jeu::contactGauche(Obstacle *o) {
    return (o->pos->getX() <= joueur.pos->getX()
        && (o->pos->getX() + o->taille->getLargeur() >= joueur.pos->getX()));
}

bool Jeu::contactDroite(Obstacle *o) {
    return (joueur.pos->getX() <= o->pos->getX()
        && (joueur.pos->getX() + joueur.taille->getLargeur() >= o->pos->getX()));
}

bool Jeu::contactSuperieur(Obstacle *o) {
    return (o->pos->getY() <= joueur.pos->getY()
        && (o->pos->getY() + o->taille->getHauteur() >= joueur.pos->getY() + 0.5));
}

bool Jeu::contactInferieur(Obstacle *o) {
    return (joueur.pos->getY() <= o->pos->getY()
        && (joueur.pos->getY() + joueur.taille->getHauteur() >= o->pos->getY()));
}


bool Jeu::collision(bool saut) {
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

bool Jeu::collisionSol(){
    if (joueur.pos->getY() + joueur.taille->getHauteur() >= terrain.getPlateforme()){
            joueur.pos->setY(terrain.getPlateforme() -  joueur.taille->getHauteur());

        cout << "sol" << endl;
        return true;
    }
    else return false;

}


void Jeu::actionAutomatique(bool saut) {
    obstacles.deplacementAuto();
//    cout << "vie = " << joueur.getVie() << endl;
    if (!saut) joueur.retomber(terrain);
    if (collision(saut))
        cout << "collision" << endl;
}

