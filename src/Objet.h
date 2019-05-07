//
// Created by Yanis on 14/03/2019.
//
#ifndef ENDLESSRUNNER_OBJET_H
#define ENDLESSRUNNER_OBJET_H

#include "Forme2D.h"
#include "Pos2D.h"
#include "Joueur.h"
class Objet {
public:
    Forme2D* taille; //!< Pointeur de type Forme2D
    Pos2D* pos; //!< Pointeur de type Pos2D
    int* typeObjet = new int; //!< Pointeur de type int

    //! Constructeur de Objet sans paramètre
    /*!
        Initialise les variables membre de Objet
    */
    Objet();

    //Destructeur de l'objet
    ~Objet();

    //! getTypeObjet, fonction membre de Objet
    /*!
        retourne la valeur de la variable membre typeObjet
    */
    int& getTypeObjet() const;

    //! setTypeObjet, procedure membre de Objet
    /*!
        permet de mettre la variable membre typeObjet à la valeur x
        \param x int, la valeur que va prendre typeObjet
    */
    void setTypeObjet(const int x);

    //! vie, procedure membre de Objet
    /*!
        appelle la fonction vieUp() de la classe Joueur pour augmenter la vie de 1
        \param j Joueur, le joueur dont la vie va etre augmentee
    */
    void vie(Joueur &j);

    //! fantome, procedure membre de Objet
    /*!
        appelle la fonction activerFantome() de Joueur pour passer à true la variable fantome
        \param j Joueur, le joueur donc la variable fantome sera mise à true
    */
    void fantome(Joueur &j);

    //! doubleSaut, procedure membre de Objet
    /*!
        appelle la fonction activerDoubleSaut() de Joueur pour passer à true la variable doubleSaut
        \param j Joueur, le joueur donc la variable doubleSaut sera mise à true
    */
    void doubleSaut(Joueur &j);

    //! deplacementAuto, procedure de Objet
    /*!
        permet le deplacement des objets dans l'espace
    */
    void deplacementAuto();
};


#endif //ENDLESSRUNNER_OBJET_H
