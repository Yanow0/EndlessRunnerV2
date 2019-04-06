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

Pos2D::Pos2D(int x, int y) {
    this->x = x;
    this->y = y;
}

int Pos2D::getX() { return this->x;}

int Pos2D::getY() {return this->y;}

void Pos2D::setX(int x) {this->x = x;}

void Pos2D::setY(int y) {this->y = y;}
