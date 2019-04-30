//
// Created by Yanis on 14/03/2019.
//
#include <cstdlib>
#include <iostream>
#include "Jeu.h"
using namespace std;

Jeu::Jeu() {
   terrain = Terrain();
   joueur = Joueur();
//   obstacle = Obstacle();
   obstacles = ListeObstacles();
   objet = Objet();
}

Jeu::~Jeu(){

}

Terrain& Jeu::getTerrain() {return terrain;}
Joueur& Jeu::getJoueur() {return joueur;}
ListeObstacles& Jeu::getObstacle() {return obstacles;}
//Obstacle& Jeu::getObstacle() {return obstacle;}
Objet& Jeu::getObjet() {return objet;}

//bool Jeu::contactGauche() {
//    return (obstacle.pos->getX() <= joueur.pos->getX()
//            && obstacle.pos->getX() + obstacle.taille->getLargeur() >= joueur.pos->getX());
//}
//
//bool Jeu::contactDroite() {
//    return (joueur.pos->getX() <= obstacle.pos->getX()
//            && joueur.pos->getX() + joueur.taille->getLargeur() >= obstacle.pos->getX());
//}
//
//bool Jeu::contactSuperieur() {
//    return (obstacle.pos->getY() <= joueur.pos->getY()
//            && obstacle.pos->getY() + obstacle.taille->getHauteur() >= joueur.pos->getY());
//}
//
//bool Jeu::contactInferieur() {
//    return (joueur.pos->getY() <= obstacle.pos->getY()
//            && joueur.pos->getY() + joueur.taille->getHauteur() >= obstacle.pos->getY());
//}
//
//
//bool Jeu::collision() {
//    return (contactGauche() && (contactSuperieur() || contactInferieur()))
//        || (contactDroite() && (contactSuperieur() || contactInferieur()));
//}


void Jeu::actionClavier(const char &touche) {
	switch(touche) {
		case 'h' :
				joueur.sauter(terrain);
				break;
		case 'b' :
				//joueur.descendre(terrain);
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
            return true;
    } else return false;

    cout << "sol" << endl;
}


void Jeu::actionAutomatique(bool saut) {
    obstacles.deplacementAuto();
    if (!saut) joueur.retomber(terrain);
}

