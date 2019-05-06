#ifndef LISTEOBJET_H
#define LISTEOBJET_H

#include <vector>
#include "Objet.h"

using namespace std;

class ListeObjet
{
    public:
        ListeObjet();
        ~ListeObjet();
        int nbObjet();
        bool listeVide();
        Objet* getObjet(const int &i);
        void ajouterObjet(const Objet o);
        void supprimerEnTete();
        void supprimerElement(const int &i);

        // tester si la position d'un nouvel objet est valide
        // (pour ensuite l'insérer dans la liste d'objet)
        bool positionValide(const Objet o);

        // création aléatoire d'un objet valide
        void creation();

        // deplacement de tous les objets dans la liste
        void deplacementAuto();

        void vider();
    private:
        vector<Objet> objets;
};

#endif // LISTEOBJET_H
