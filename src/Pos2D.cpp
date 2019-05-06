//
// Created by Valentin on 14/03/2019.
//

#include "Pos2D.h"

Pos2D::Pos2D() {
    setX(1);
    setY(1);
}

Pos2D::~Pos2D() {

}

Pos2D::Pos2D(const float x, const float y) {
    setX(x);
    setY(y);
}

float Pos2D::getX() const { return this->x;}

float Pos2D::getY() const {return this->y;}

void Pos2D::setX(const float x) {this->x = x;}

void Pos2D::setY(const float y) {this->y = y;}
