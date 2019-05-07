//
// Created by Yanis on 14/03/2019.
//

#ifndef ENDLESSRUNNER_JOUEUR_H
#define ENDLESSRUNNER_JOUEUR_H


#include "Forme2D.h"
#include "Pos2D.h"
#include "Terrain.h"

class Joueur {
    private:
        int vie; //!< Variable membre de type entier, repr�sente le nombre de vies
        int score; //!< Variable membre de type entier, repr�sente le score
        bool fantome; //!< Variable membre de type booleen, repr�sente l'etat de fantome
        bool doubleSaut; //!< Variable membre de type booleen, repr�sente l'etat de doubleSaut
        int* action = new int; //!< Pointeur de type int, repr�sent l'action actuelle

    public:
        Forme2D* taille; //!< Pointeur de type Forme2D
        Pos2D* pos; //!< Pointeur de type Pos2D
        float vitesseSaut; //!< Variable membre de type float, repr�sente la vitesse de saut
        float gravite; //!< Variable membre de type float, repr�sente la force de gravite



    //Constructeur Joueur
    //! Constructeur de Joueur sans param�tre
    /*!
        Initialise les variables membre de Joueur
    */
    Joueur();

    //! Constructeur de Joueur avec 1 param�tre
        /*!
            Initialise les variables membre de Joueur et son nombre de vies en fonction du param�tre v
            \param v entier qui repr�sente le nombre de vie initial
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
        Affecte la valeur pass�e en param�tre � la variable membre action du Joueur.
        \param action un entier qui repr�sente l'action du Joueur.
    */
    void setAction(const int x);

    //! Getter de vie du joueur
        /*!
            Retourne l'entier vie du Joueur.
        */
    int& getVie();

    //! Setter de vie du Joueur
    /*!
        Affecte la valeur pass�e en param�tre � la variable membre vie du Joueur.
        \param x un entier qui repr�sente les vies du Joueur.
    */
    void setVie(const int x);

    //! Getter de score du joueur
        /*!
            Retourne l'entier score du Joueur.
        */
    int& getScore();

    //! Setter de score du Joueur
    /*!
        Affecte la valeur pass�e en param�tre � la variable membre score du Joueur.
        \param x un entier qui repr�sente le score du Joueur.
    */
    void setScore(const int x);

    //! vieUp, procedure membre de Joueur sans param�tre
        /*!
            Incr�mente de 1 la variable membre vie.
        */
    void vieUp();

    //! vieDown, procedure membre de Joueur sans param�tre
        /*!
            Decr�mente de 1 la variable membre vie.
        */
    void vieDown();

    //! Getter de doubleSaut du joueur
        /*!
            Retourne le booleen doubleSaut du Joueur.
        */
    bool getDoubleSaut() const;

    //! activerDoubleSaut, procedure membre de Joueur sans param�tre
        /*!
            Passe la variable membre doubleSaut � true;
        */
    void activerDoubleSaut();

    //! desactiverDoubleSaut, procedure membre de Joueur sans param�tre
        /*!
            Passe la variable membre doubleSaut � false
        */
    void desactiverDoubleSaut();

    //! Getter de fantome du joueur
        /*!
            Retourne le booleen fantome du Joueur.
        */
    bool getFantome() const;

    //! activerFantome, procedure membre de Joueur sans param�tre
        /*!
            Passe la variable membre fantome � true;
        */
    void activerFantome();

    //! desactiverFantome, procedure membre de Joueur sans param�tre
        /*!
            Passe la variable membre fantome � false;
        */
    void desactiverFantome();

    //! doubleSauter, procedure membre de Joueur avec 1 param�tre
        /*!
            Reinitialise la vitesse du saut � 0.5
            \param t Terrain repr�sentant le terrain actuel
        */
    void doubleSauter(const Terrain &t);
   // bool collisionSol(const Terrain &t);

   //! baisser, procedure membre de Joueur avec 1 param�tre
        /*!
            Passe la variable membre action � 1,
            Change la taille du joueur
            \param t Terrain repr�sentant le terrain actuel
        */
    void baisser(const Terrain &t);

    //! relever, procedure membre de Joueur avec 1 param�tre
        /*!
            Passe la variable membre action � 0,
            Change la taille du joueur
            \param t Terrain repr�sentant le terrain actuel
        */
    void relever(const Terrain &t);

    //! sauter, procedure membre de Joueur avec 1 param�tre
        /*!
            Change la position et l'action du Joueur en fonction de vitesseSaut
            \param t Terrain repr�sentant le terrain actuel
        */
    void sauter(const Terrain &t);

    //! descendre, procedure membre de Joueur avec 1 param�tre
        /*!
            Change la position du joueur pour le faire descendre d'un cran
            \param t Terrain repr�sentant le terrain actuel
        */
    void descendre(const Terrain &t);

     //! retomber, procedure membre de Joueur avec 1 param�tre
        /*!
            Appelle descendre si le joueur ne touche pas le sol
            \param t Terrain repr�sentant le terrain actuel
        */
    void retomber(const Terrain &t);

    void secondeChance();
     //! testRegression, procedure membre de Joueur sans param�tre
        /*!
            Lance un test de r�gression pour la classe Joueur
        */
    void testRegression();
};


#endif //ENDLESSRUNNER_JOUEUR_H
