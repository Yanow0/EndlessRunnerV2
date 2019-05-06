//
// Created by Valentin on 14/03/2019.
//

#ifndef PROJECT_FORME2D_H
#define PROJECT_FORME2D_H


class Forme2D {
public:
    //Default constructor, if no values are given, put longueur=1 and largeur=1

    //! Constructeur de Forme2D sans paramètre
    /*!
      Initialise les entiers hauteur et largeur de la Forme2D à 1
    */
    Forme2D();

    //Destructor
    ~Forme2D();

    //Initialize a Form2D object with the longueur and largeur values given

    //! Constructeur de Forme2D avec 2 paramètres
    /*!
        Initialise les variables membres hauteur et largeur avec les valeurs passés en paramètres.
      \param hauteur un entier qui représente la hauteur de la Forme2D.
      \param largeur un entier qui représente la largeur de la Forme2D.
    */
    Forme2D(const int hauteur, const int largeur);

    //! Getter de hauteur de Forme2D
    /*!
        Retourne l'entier hauteur de la Forme2D.
    */
    int getHauteur() const;

    //! Getter de largeur de Forme2D
    /*!
        Retourne l'entier largeur de la Forme2D.
    */
    int getLargeur() const;

    //! Setter de hauteur de Forme2D
    /*!
        Affecte la valeur passée en paramètre à la variable membre hauteur de la Forme2D.
        \param hauteur un entier qui représente la hauteur de la Forme2D.
    */
    void setHauteur(const int hauteur);

    //! Setter de largeur de Forme2D
    /*!
        Affecte la valeur passée en paramètre à la variable membre largeur de la Forme2D.
        \param largeur un entier qui représente la hauteur de la Forme2D.
    */
    void setLargeur(const int largeur);

private:
    int hauteur; //!< Variable membre, entier représentant la hauteur de la Forme2D.
    int largeur; //!< Variable membre, entier représentant la largeur de la Forme2D.
};


#endif //PROJECT_FORME2D_H
