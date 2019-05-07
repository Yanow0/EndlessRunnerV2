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
        Ajoute l'obstacle dans le tableau dynamique obstacles
        \param o, l'obstacle a ajouter
    */
    void ajouterObstacle(const Obstacle o);

    //! supprimerEnTete, procedure membre de ListeObstacles
    /*!
        Supprime le premier element du tableau dynamique obstacles
    */
    void supprimerEnTete();

    //! supprimerELement, procedure membre de ListeObstacles
    /*!
        supprime l'element à l'index i du tableau dynamique obstacles
        \param i entier, l'index de l'element a supprimer
    */
    void supprimerElement(const int &i);

    //! positionValide, fonction membre de ListeObstacles
    /*!
        Verifie si la position de l'obstacle est valide (pour ensuite pour l'inserer)
        \param o Obstacle, l'obstacle dont la postion doit etre verifiee
    */
    bool positionValide(const Obstacle o);

    //! creation, procedure membre de ListeObstacles
    /*!
        Créer un aléatoirement un obstacle valide
    */
    void creation();

    //! deplacementAuto, procedure membre de ListeObstacles
    /*!
        Permet le deplacement de tous les obstacles dans la liste
    */
    void deplacementAuto();

    //! vider, procedure membre de ListeObstacles
    /*!
        Vide la liste de tous les objets
    */
    void vider();

    //! testRegression, procedure membre de ListeObstacles sans paramètre
    /*!
        Lance un test de régression pour la classe ListeObstacles
    */
    void testRegression();
};


#endif //ENDLESSRUNNER_LISTE_OBSTACLES_H
