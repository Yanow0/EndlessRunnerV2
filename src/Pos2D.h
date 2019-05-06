//
// Created by Valentin on 14/03/2019.
//

#ifndef PROJECT_POS2D_H
#define PROJECT_POS2D_H


class Pos2D {
public:

    //! Constructeur de Pos2D sans param�tre
    /*!
        Initialise les variables membre de Pos2D
    */
    Pos2D();

    //Destructeur de Pos2D
    ~Pos2D();

    //! Constructeur de Objet avec param�tres
    /*!
        Initialise les variables membre de Objet avec les valeurs passee en parametres
        \param x,y float, les valeurs que doivent prendre les variables membre x et y
    */
    Pos2D(const float x, const float y);

    //! Getter de x de Pos2D
    /*!
        Retourne l'entier x de la Pos2D.
    */
    float getX() const;

    //! Getter de y de Pos2D
    /*!
        Retourne l'entier y de la Pos2D.
    */
    float getY() const;

    //! Setter de x de Pos2D
    /*!
        Affecte la valeur pass�e en param�tre � la variable membre hauteur de la Pos2D.
        \param x un entier qui repr�sente la valeur de la variable membre x.
    */
    void setX(const float x);

    //! Setter de y de Pos2D
    /*!
        Affecte la valeur pass�e en param�tre � la variable membre hauteur de la Pos2D.
        \param y un entier qui repr�sente la valeur de la variable membre y.
    */
    void setY(const float y);

private:
    float x; //!< Variable membre, entier repr�sentant la position en x de la Pos2D.
    float y; //!< Variable membre, entier repr�sentant la position en y de la Pos2D.
};


#endif //PROJECT_POS2D_H
