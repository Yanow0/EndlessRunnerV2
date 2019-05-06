#include <iostream>
#include <cstdlib>
#include "ListeObjet.h"

using namespace std;

ListeObjet::ListeObjet()
{
    creation();
}

ListeObjet::~ListeObjet()
{
    vider();
}

int ListeObjet::nbObjet()
{
    return objets.size();
}

bool ListeObjet::listeVide()
{
    return objets.empty();
}

Objet* ListeObjet::getObjet(const int &i)
{
    return &objets[i];
}

void ListeObjet::ajouterObjet(const Objet o)
{
    objets.push_back(o);
}

void ListeObjet::supprimerEnTete()
{
    objets.erase(objets.begin());
}

void ListeObjet::supprimerElement(const int &i)
{
    objets.erase(objets.begin()+i);
}

bool ListeObjet::positionValide(const Objet o)
{
    return (listeVide()
            || (o.pos->getX() > objets.back().pos->getX() + objets.back().taille->getLargeur() + 18)
            || ((o.pos->getX() > objets.back().pos->getX() + objets.back().taille->getLargeur() + 18)
                && ((o.pos->getY() > objets.back().pos->getY() + objets.back().taille->getHauteur() + 6)
                    || (objets.back().pos->getY() > o.pos->getY() + o.taille->getHauteur() + 6))));
}

void ListeObjet::creation()
{
    Objet o = Objet();
    if(positionValide(o)){
        ajouterObjet(o);
    }
}

void ListeObjet::deplacementAuto()
{
    if (nbObjet()<2) creation();
    for (int i=0; i<nbObjet(); i++) {
        objets[i].deplacementAuto();
    }
    while (objets.front().pos->getX()+objets.front().taille->getLargeur() <= 0)
        supprimerEnTete();
}

void ListeObjet::vider()
{
    objets.clear();
}
