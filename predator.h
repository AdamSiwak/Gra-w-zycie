#ifndef PREDATOR_H
#define PREDATOR_H

#include "dinosaur.h"

class Predator : public Dinosaur {
    //Predator(QString& dinoName) : Dinosaur(dinoName) {}

private:
    int attack_;
    int loudness_;

    const QString picture = ":/dinosaur-brown.png";
};

#endif // PREDATOR_H