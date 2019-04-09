//
// Created by Yanis on 14/03/2019.
//

#include <iostream>
#include "Jeu.h"
using namespace std;

Jeu::Jeu() {
   terrain = Terrain();
   joueur = Joueur();
   obstacle = Obstacle();
   objet = Objet();
}

Jeu::~Jeu(){

}

Terrain& Jeu::getTerrain() {return terrain;}
Joueur& Jeu::getJoueur() {return joueur;}
Obstacle& Jeu::getObstacle() {return obstacle;}
Objet& Jeu::getObjet() {return objet;}


bool Jeu::contactGauche() {
    return (obstacle.pos->getX() <= joueur.pos->getX()
            && obstacle.pos->getX() + obstacle.taille->getLargeur() >= joueur.pos->getX());
}

bool Jeu::contactDroite() {
    return (joueur.pos->getX() <= obstacle.pos->getX()
            && joueur.pos->getX() + joueur.taille->getLargeur() >= obstacle.pos->getX());
}

bool Jeu::contactSuperieur() {
    return (obstacle.pos->getY() <= joueur.pos->getY()
            && obstacle.pos->getY() + obstacle.taille->getHauteur() >= joueur.pos->getY());
}

bool Jeu::contactInferieur() {
    return (joueur.pos->getY() <= obstacle.pos->getY()
            && joueur.pos->getY() + joueur.taille->getHauteur() >= obstacle.pos->getY());
}


bool Jeu::collision() {
    return (contactGauche() && (contactSuperieur() || contactInferieur()))
        || (contactDroite() && (contactSuperieur() || contactInferieur()));
}


void Jeu::actionClavier(const char &touche) {
	switch(touche) {
		case 'h' :
				joueur.sauter(terrain);
				break;
		case 'b' :
				//joueur.descendre(terrain);
				break;
	}
}

bool Jeu::collisionSol(){
    return joueur.pos->getY() + joueur.taille->getHauteur() >= terrain.getPlateforme();
}


void Jeu::actionAutomatique(bool saut) {
    obstacle.deplacementAuto();
    if (!saut) joueur.retomber(terrain);
}

