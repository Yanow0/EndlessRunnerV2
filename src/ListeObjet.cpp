#include <iostream>
#include <cstdlib>
#include <assert.h>
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


void ListeObjet::testRegression() {
    cout << endl;
    cout << "======== TEST de regression pour LISTEOBJET ========" << endl << endl;

    ListeObjet liste;
    assert (liste.listeVide()==false);
    cout << "fonction listeVide ok" << endl;

    Objet o;
    liste.ajouterObjet(o);
    assert (liste.nbObjet()==2);
    cout << "ajouterObjet ok" << endl;
    cout << "nbObjet dans la liste ok" << endl;

    liste.supprimerEnTete();
    assert (liste.nbObjet()==1);
    assert (liste.getObjet(0)->pos->getY()==o.pos->getY());
    assert (liste.getObjet(0)->taille->getLargeur()==o.taille->getLargeur());
    cout << "getObjet ok" << endl;
    cout << "supprimerEnTete ok" << endl;

    liste.vider();
    assert (liste.listeVide()==true);
    cout << "fonction vider ok" << endl << endl;
    cout << "==> LISTEOBJET : OK" << endl << endl;
}
