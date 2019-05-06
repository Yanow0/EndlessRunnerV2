//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_JOUEUR_H
#define ENDLESSRUNNER_JOUEUR_H


#include "Forme2D.h"
#include "Pos2D.h"
#include "Terrain.h"

class Joueur {
    public:
        Forme2D* taille; //!< Pointeur de type Forme2D
        Pos2D* pos; //!< Pointeur de type Pos2D
        int vie; //!< Variable membre de type entier, représente le nombre de vies
        bool fantome; //!< Variable membre de type booleen, représente l'etat de fantome
        bool doubleSaut; //!< Variable membre de type booleen, représente l'etat de doubleSaut
        float vitesseSaut; //!< Variable membre de type float, représente la vitesse de saut
        float gravite; //!< Variable membre de type float, représente la force de gravite
        int* action = new int; //!< Pointeur de type int, représent l'action actuelle



    //Constructeur Joueur
    //! Constructeur de Joueur sans paramètre
    /*!
        Initialise les variables membre de Joueur
    */
    Joueur();

    //! Constructeur de Jeu avec 1 paramètre
        /*!
            Initialise les variables membre de Joueur et son nombre de vies en fonction du paramètre v
            \param v entier qui représente le nombre de vie initial
        */
    Joueur(const int &v);   // v: nouveau nombre de vies

    //Destructeur Joueur
    ~Joueur();

    //! Getter de action du joueur
        /*!
            Retourne l'entier action du Joueur.
        */
    int& getAction() const;

    //! Setter de action du Joueur
    /*!
        Affecte la valeur passée en paramètre à la variable membre action du Joueur.
        \param action un entier qui représente l'action du Joueur.
    */
    void setAction(const int x);

    //! Getter de vie du joueur
        /*!
            Retourne l'entier vie du Joueur.
        */
    int& getVie();

    //! Setter de vie du Joueur
    /*!
        Affecte la valeur passée en paramètre à la variable membre vie du Joueur.
        \param x un entier qui représente les vies du Joueur.
    */
    void setVie(const int x);

    //! vieUp, procedure membre de Joueur sans paramètre
        /*!
            Incrémente de 1 la variable membre vie.
        */
    void vieUp();

    //! vieDown, procedure membre de Joueur sans paramètre
        /*!
            Decrémente de 1 la variable membre vie.
        */
    void vieDown();

    //! Getter de doubleSaut du joueur
        /*!
            Retourne le booleen doubleSaut du Joueur.
        */
    bool getDoubleSaut() const;

    //! activerDoubleSaut, procedure membre de Joueur sans paramètre
        /*!
            Passe la variable membre doubleSaut à true;
        */
    void activerDoubleSaut();

    //! desactiverDoubleSaut, procedure membre de Joueur sans paramètre
        /*!
            Passe la variable membre doubleSaut à false
        */
    void desactiverDoubleSaut();

    //! Getter de fantome du joueur
        /*!
            Retourne le booleen fantome du Joueur.
        */
    bool getFantome() const;

    //! activerFantome, procedure membre de Joueur sans paramètre
        /*!
            Passe la variable membre fantome à true;
        */
    void activerFantome();

    //! desactiverFantome, procedure membre de Joueur sans paramètre
        /*!
            Passe la variable membre fantome à false;
        */
    void desactiverFantome();

    //! doubleSauter, procedure membre de Joueur avec 1 paramètre
        /*!
            Reinitialise la vitesse du saut à 0.5
            \param t Terrain représentant le terrain actuel
        */
    void doubleSauter(const Terrain &t);
   // bool collisionSol(const Terrain &t);

   //! baisser, procedure membre de Joueur avec 1 paramètre
        /*!
            Passe la variable membre action à 1,
            Change la taille du joueur
            \param t Terrain représentant le terrain actuel
        */
    void baisser(const Terrain &t);

    //! relever, procedure membre de Joueur avec 1 paramètre
        /*!
            Passe la variable membre action à 0,
            Change la taille du joueur
            \param t Terrain représentant le terrain actuel
        */
    void relever(const Terrain &t);

    //! sauter, procedure membre de Joueur avec 1 paramètre
        /*!
            Change la position et l'action du Joueur en fonction de vitesseSaut
            \param t Terrain représentant le terrain actuel
        */
    void sauter(const Terrain &t);

    //! descendre, procedure membre de Joueur avec 1 paramètre
        /*!
            Change la position du joueur pour le faire descendre d'un cran
            \param t Terrain représentant le terrain actuel
        */
    void descendre(const Terrain &t);

     //! retomber, procedure membre de Joueur avec 1 paramètre
        /*!
            Appelle descendre si le joueur ne touche pas le sol
            \param t Terrain représentant le terrain actuel
        */
    void retomber(const Terrain &t);

     //! testRegression, procedure membre de Joueur sans paramètre
        /*!
            Lance un test de régression pour la classe Joueur
        */
    void testRegression();
};


#endif //ENDLESSRUNNER_JOUEUR_H
