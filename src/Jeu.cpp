//
// Created by Yanis on 14/03/2019.
//
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <cstdlib>
#include <iostream>
#include "Jeu.h"
using namespace std;

Jeu::Jeu(): joueur(), obstacles(), terrain(), objets() {

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2,4096 ) < 0 ) {
            cout << "Erreur lors de l'initialisation de la SDL_mixer : " << Mix_GetError() << endl;
    }
    hitObject = Mix_LoadWAV( "./data/hitobject.wav" );
    hitObstacle = Mix_LoadWAV( "./data/hitobstacle.wav" );
    jump = Mix_LoadWAV( "./data/jump.wav" );
    wasted = Mix_LoadWAV( "./data/wasted.wav" );
    invincibility  = Mix_LoadWAV( "./data/invincibility.wav" );
    if ((hitObject == NULL ) || (hitObstacle == NULL ) || (jump == NULL ) || (wasted == NULL ) || (invincibility == NULL ) ) {
        cout << "Erreur lors de la cr�ation des effets sonores" << Mix_GetError() << endl;
    }
}

Jeu::~Jeu(){

}

Terrain* Jeu::getTerrain() {return &terrain;}
Joueur* Jeu::getJoueur() {return &joueur;}
ListeObstacles* Jeu::getObstacle() {return &obstacles;}
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


bool Jeu::collision() {
    for (int i=0; i<obstacles.nbObstacles(); i++) {
        Obstacle *o = obstacles.getObstacle(i);
        if ((contactGauche(o) && (contactSuperieur(o) || contactInferieur(o)))
        || (contactDroite(o) && (contactSuperieur(o) || contactInferieur(o)))) {
            if(joueur.getEtoile()==1){
                cout << "test" << endl;
                obstacles.supprimerElement(i);
                joueur.desactiverEtoile();
                return false;
            }
            Mix_HaltChannel(-1);
            Mix_PlayChannel( -1, hitObstacle, 0 );
            return true;
        }
    }
    return false;
}

bool Jeu::contactGaucheObjet(const Objet *o) const{
    return (o->pos->getX() <= joueur.pos->getX()
        && (o->pos->getX() + o->taille->getLargeur() >= joueur.pos->getX()));
}

bool Jeu::contactDroiteObjet(const Objet *o) const{
    return (joueur.pos->getX() <= o->pos->getX()
        && (joueur.pos->getX() + joueur.taille->getLargeur() - 0.8 >= o->pos->getX()));
}

bool Jeu::contactSuperieurObjet(const Objet *o) const{
    return (o->pos->getY() <= joueur.pos->getY()
        && (o->pos->getY() + o->taille->getHauteur() >= joueur.pos->getY() + 0.5));
}


bool Jeu::contactInferieurObjet(const Objet *o) const{
    return (joueur.pos->getY() <= o->pos->getY()
        && (joueur.pos->getY() + joueur.taille->getHauteur() >= o->pos->getY()));
}


bool Jeu::collisionObjet(){
    for (int i=0; i<objets.nbObjet(); i++) {
        Objet *o = objets.getObjet(i);
        if ((contactGaucheObjet(o) && (contactSuperieurObjet(o) || contactInferieurObjet(o)))
        || (contactDroiteObjet(o) && (contactSuperieurObjet(o) || contactInferieurObjet(o)))) {

            switch(objets.getObjet(i)->getTypeObjet()){
            case 0:
                joueur.vieUp();
                break;
            case 1:
                joueur.activerEtoile();
                Mix_PlayChannel( -1, invincibility, 0 );
                break;
            case 2:
                joueur.activerDoubleSaut();
                break;
            }
            objets.supprimerElement(i);
            Mix_HaltChannel(-1);
            Mix_PlayChannel( -1, hitObject, 0 );
            return true;
        }
    }
    return false;
}

void Jeu::actionClavier(const char &touche) {
	switch(touche) {
		case 'h' :
				joueur.sauter(terrain);
				Mix_PlayChannel( -1, jump, 0 );
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
    //if (collision(saut) && joueur.fantome==0) {
    if (collision() && joueur.getEtoile()==0) {
        cout << "collision" << endl;
        joueur.vieDown();
//        cout << "vie = " << joueur.getVie() << endl;

        saut = false;
        if (joueur.getVie() > 0) {
            joueur.secondeChance();
            obstacles.vider();
            objets.vider();

            #ifdef _WIN32
            Sleep(500);
            #else
            usleep(500000);
            #endif // WIN32
        } else if(joueur.getVie() == 0) {
            Mix_HaltChannel(-1);
            Mix_PlayChannel( -1, wasted, 0 );
        }

    }

    if (collisionObjet()) {
        cout << "collision avec objet" << endl;
    }
}


void Jeu::restart(){
    terrain = Terrain();
    joueur = Joueur();
    obstacles = ListeObstacles();
    objets = ListeObjet();
}

