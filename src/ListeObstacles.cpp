#include <iostream>
#include <cstdlib>
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

void ListeObstacles::ajouterObstacle(Obstacle o) {
    obstacles.push_back(o);
}

void ListeObstacles::supprimerEnTete() {
    obstacles.erase(obstacles.begin());
}

bool ListeObstacles::positionValide(Obstacle o) {
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
