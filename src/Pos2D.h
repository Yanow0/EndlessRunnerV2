//
// Created by Valentin on 14/03/2019.
//

#ifndef PROJECT_POS2D_H
#define PROJECT_POS2D_H


class Pos2D {
public:
    //Default constructor, if no values are given, put x=1 and y=1
    Pos2D();

    //Destructor
    ~Pos2D();

    //Initialize a Pos2D object with the x and y values given
    Pos2D(const float x, const float y);

    float getX() const;

    float getY() const;

    void setX(const float x);

    void setY(const float y);

private:
    float x;
    float y;
};


#endif //PROJECT_POS2D_H
