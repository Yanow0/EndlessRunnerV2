#ifndef ENDLESSRUNNER_LISTE_OBSTACLES_H
#define ENDLESSRUNNER_LISTE_OBSTACLES_H

#include <vector>
#include "Obstacle.h"

using namespace std;

class ListeObstacles {

private:
    vector<Obstacle> obstacles;

public:

    ListeObstacles();
    ~ListeObstacles();

    int nbObstacles();
    bool listeVide();
    Obstacle* getObstacle(const int &i);
    void ajouterObstacle(const Obstacle o);
    void supprimerEnTete();
    void supprimerElement(const int &i);

    // tester si la position d'un nouvel obstacle est valide
    // (pour ensuite l'insérer dans la liste d'obstacles)
    bool positionValide(const Obstacle o);

    // création aléatoire d'un obstacle valide
    void creation();

    // deplacement de tous les obstacles dans la liste
    void deplacementAuto();

    void vider();
};


#endif //ENDLESSRUNNER_LISTE_OBSTACLES_H
