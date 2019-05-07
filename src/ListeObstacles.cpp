#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "ListeObstacles.h"

using namespace std;

ListeObstacles::ListeObstacles() {
    creation();
}

ListeObstacles::~ListeObstacles() {
    vider();
}

int ListeObstacles::nbObstacles() {
    return obstacles.size();
}

bool ListeObstacles::listeVide() {
    return obstacles.empty();
}

Obstacle* ListeObstacles::getObstacle(const int &i) {
    return &obstacles[i];
}

void ListeObstacles::ajouterObstacle(const Obstacle o) {
    obstacles.push_back(o);
}

void ListeObstacles::supprimerEnTete() {
    obstacles.erase(obstacles.begin());
}

void ListeObstacles::supprimerElement(const int &i){
    obstacles.erase(obstacles.begin()+i);
}

bool ListeObstacles::positionValide(const Obstacle o) {
    return (listeVide()
            || (o.pos->getX() > obstacles.back().pos->getX() + obstacles.back().taille->getLargeur() + 7)
            || ((o.pos->getX() > obstacles.back().pos->getX() + obstacles.back().taille->getLargeur() + 2)
                && ((o.pos->getY() > obstacles.back().pos->getY() + obstacles.back().taille->getHauteur() + 6)
                    || (obstacles.back().pos->getY() > o.pos->getY() + o.taille->getHauteur() + 6))));
}

void ListeObstacles::creation() {
    Obstacle o = Obstacle();
    if (positionValide(o)){
        ajouterObstacle(o);
    }
}

void ListeObstacles::deplacementAuto() {

    creation();

    for (int i=0; i<nbObstacles(); i++) {
        obstacles[i].deplacementAuto();
    }
    while (obstacles.front().pos->getX()+obstacles.front().taille->getLargeur() <= 0)
        supprimerEnTete();
}

void ListeObstacles::vider() {
    obstacles.clear();
}


void ListeObstacles::testRegression() {
    cout << endl;
    cout << "======== TEST de regression pour LISTEOBSTACLES ========" << endl << endl;

    ListeObstacles liste;
    assert (liste.listeVide()==false);
    cout << "fonction listeVide ok" << endl;

    Obstacle o;
    liste.ajouterObstacle(o);
    assert (liste.nbObstacles()==2);
    cout << "ajouterObstacle ok" << endl;
    cout << "nbObstacles dans la liste ok" << endl;

    liste.supprimerEnTete();
    assert (liste.nbObstacles()==1);
    assert (liste.getObstacle(0)->pos->getY()==o.pos->getY());
    assert (liste.getObstacle(0)->taille->getLargeur()==o.taille->getLargeur());
    cout << "getObstacle ok" << endl;
    cout << "supprimerEnTete ok" << endl;

    liste.vider();
    assert (liste.listeVide()==true);
    cout << "fonction vider ok" << endl << endl;
    cout << "==> LISTEOBSTACLES : OK" << endl << endl;
}
