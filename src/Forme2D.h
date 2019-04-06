//
// Created by Valentin on 14/03/2019.
//

#ifndef PROJECT_FORME2D_H
#define PROJECT_FORME2D_H


class Forme2D {
public:
    //Default constructor, if no values are given, put longueur=1 and largeur=1
    Forme2D();

    //Destructor
    ~Forme2D();

    //Initialize a Form2D object with the longueur and largeur values given
    Forme2D(int hauteur, int largeur);

    int getHauteur();

    int getLargeur();

    void setHauteur(int hauteur);

    void setLargeur(int largeur);

private:
    int hauteur;
    int largeur;
};


#endif //PROJECT_FORME2D_H
