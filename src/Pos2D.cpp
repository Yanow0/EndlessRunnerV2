//
// Created by Valentin on 14/03/2019.
//

#include "Pos2D.h"

Pos2D::Pos2D() {
    this->x = 1;
    this->y = 1;
}

Pos2D::~Pos2D() {
    this->x = 1;
    this->y = 1;
}

Pos2D::Pos2D(float x, float y) {
    this->x = x;
    this->y = y;
}

float Pos2D::getX() { return this->x;}

float Pos2D::getY() {return this->y;}

void Pos2D::setX(float x) {this->x = x;}

void Pos2D::setY(float y) {this->y = y;}
