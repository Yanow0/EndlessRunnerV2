#ifndef LISTEOBJET_H
#define LISTEOBJET_H

#include <vector>
#include "Objet.h"

using namespace std;

class ListeObjet
{
    public:

        //! Constructeur de ListeObjet sans paramètre
        /*!
            Appelle la fonction membre creation
        */
        ListeObjet();

        //! Destructeur de ListeObjet sans paramètre
        /*!
        Appelle la fonction membre vider
        */
        ~ListeObjet();

        //! nbObjet, fonction membre de ListeObjet sans paramètre
        /*!
            Retourne le nombre d'objet dans le tableau dynamique objets
        */
        int nbObjet();

        //! listeVide, fonction membre de ListeObjet sans paramètre
        /*!
            Retourne true si le tableau dynamique objets est vide, false sinon
        */
        bool listeVide();

        //! Getter de action du joueur
        /*!
            Retourne l'Objet à la position i du tableau dynamique.
            \param i entier, position de l'objet dans le tableau dynamique
        */
        Objet* getObjet(const int &i);

        //! nbObjet, procedure membre de ListeObjet sans paramètre
        /*!
            Ajoute l'obstacle dans le tableau dynamique obstacles
            \param o Objet, l'objet a ajouter
        */
        void ajouterObjet(const Objet o);

        //! supprimerEnTete, procedure membre de ListeObjet
        /*!
            Supprime le premier element du tableau dynamique objets
        */
        void supprimerEnTete();

        //! supprimerELement, procedure membre de ListeObjet
        /*!
            supprime l'element à l'index i du tableau dynamique objets
            \param i entier, l'index de l'element a supprimer
        */
        void supprimerElement(const int &i);

        //! positionValide, fonction membre de ListeObjet
        /*!
            Verifie si la position de l'objet est valide (pour ensuite pour l'inserer)
            \param o Objet, l'objet dont la postion doit etre verifiee
        */
        bool positionValide(const Objet o);

        //! creation, procedure membre de ListeObjet
        /*!
            Créer un aléatoirement un objet valide
        */
        void creation();

        //! deplacementAuto, procedure membre de ListeObjet
        /*!
            Permet le deplacement de tous les objets dans la liste
        */
        void deplacementAuto();

        //! vider, procedure membre de ListeObjet
        /*!
            Vide la liste de tous les objets
        */
        void vider();
    private:
        vector<Objet> objets; //!< Tableau Dynamique de type Obstacle, contient tous les obstacles du Jeu
};

#endif // LISTEOBJET_H
