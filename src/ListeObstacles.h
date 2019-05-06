#ifndef ENDLESSRUNNER_LISTE_OBSTACLES_H
#define ENDLESSRUNNER_LISTE_OBSTACLES_H

#include <vector>
#include "Obstacle.h"

using namespace std;

class ListeObstacles {

private:
    vector<Obstacle> obstacles; //!< Tableau Dynamique de type Obstacle, contient tous les obstacles du Jeu

public:

    //! Constructeur de ListeObstacles sans paramètre
    /*!
        Appelle la fonction membre creation
    */
    ListeObstacles();

    //! Destructeur de ListeObstacles sans paramètre
    /*!
        Appelle la fonction membre vider
    */
    ~ListeObstacles();

    //! nbObstacles, fonction membre de ListeObstacles sans paramètre
        /*!
            Retourne le nombre d'obstacles dans le tableau dynamique obstacles
        */
    int nbObstacles();

    //! listeVide, fonction membre de ListeObstacles sans paramètre
        /*!
            Retourne true si le tableau dynamique obstacles est vide, false sinon
        */
    bool listeVide();

    //! Getter de action du joueur
        /*!
            Retourne l'Obstacle à la position i du tableau dynamique.
            \param i entier, position de l'obstacle dans le tableau dynamique
        */
    Obstacle* getObstacle(const int &i);

    //! nbObstacles, procedure membre de ListeObstacles sans paramètre
        /*!
            Retourne le nombre d'obstacles dans le tableau dynamique obstacles
        */
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
