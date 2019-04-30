#include <iostream>
#include <cstdlib>
#include "ListeObstacles.h"

using namespace std;

ListeObstacles::ListeObstacles() {
    creation();
}

ListeObstacles::~ListeObstacles() {
//    vider();
}

int ListeObstacles::nbObstacles() {
    return obstacles.size();
}

bool ListeObstacles::listeVide() {
    return obstacles.empty();
}

Obstacle& ListeObstacles::getObstacle(const int &i) {
    return obstacles[i];
}

void ListeObstacles::ajouterObstacle(Obstacle o) {
    obstacles.push_back(o);
//    cout << "AJOUT" << endl;
}

void ListeObstacles::supprimerEnTete() {
    obstacles.erase(obstacles.begin());
}

bool ListeObstacles::positionValide(Obstacle o) {
    return (listeVide()
            || (o.pos->getX() > obstacles.back().pos->getX() + obstacles.back().taille->getLargeur() + 2));
//                && (o.pos->getY() > obstacles.back().pos->getY() + obstacles.back().taille->getHauteur() + 2
//                    || obstacles.back().pos->getY() > o.pos->getY() + o.taille->getHauteur() + 2))
//            || (o.pos->getX() > obstacles.back().pos->getX() + obstacles.back().taille->getLargeur() + 2
//                && (o.pos->getY() > obstacles.back().pos->getY() + obstacles.back().taille->getHauteur() + 2
//                    || obstacles.back().pos->getY() > o.pos->getY() + o.taille->getHauteur() + 2)));
}

void ListeObstacles::creation() {
//    Obstacle o;
//    do {
//        o = Obstacle();
//    } while (!positionValide(o));
//    ajouterObstacle(o);

    Obstacle o = Obstacle();
    cout << "CREATION" << endl;
    if (positionValide(o))
        ajouterObstacle(o);

//    cout << "largeur " << o.taille->getLargeur() << endl;

//    Obstacle o = Obstacle();
//    ajouterObstacle(o);
}

void ListeObstacles::deplacementAuto() {
    creation();
    for (int i=0; i<nbObstacles(); i++) {
        obstacles[i].deplacementAuto();
//        cout << "deplacement " << i << endl;
    }
//    while (obstacles.front().pos->getX()+obstacles.front().taille->getLargeur() == 0)
//        supprimerEnTete();
}

void ListeObstacles::vider() {
    obstacles.clear();
}
