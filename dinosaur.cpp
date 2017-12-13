#include "dinosaur.h"
#include <QDebug>

Dinosaur::Dinosaur() : age_(0), energy_(100), speed_(rand()%maxSpeed), sightRange_(rand()%maxSightRange), sightAngle_(rand()%maxSightAngle), maxHunger_(minMaxHunger + rand()%(maxMaxHunger-minMaxHunger)), hunger_(0), thirst_(0) {
    qDebug() << sightAngle_;
}

void Dinosaur::move() {
    this->analyze_surroundings();

    if (this->thirst_ < Dinosaur::criticalThirst) { // ruch w kierunku źródła

    } else if (this->target.expired() != false) { // ruch w kierunku celu

    } else { // ruch w losowym kierunku
        move_to_destination(0,0);
    }
}

void Dinosaur::move_to_destination(int x, int y) {//int x = 0, int y = 0) {
    int deltaX;
    int deltaY;

    if (x == 0 && y == 0) { // kierunek losowy
        deltaX = rand()%(2*speed_)-speed_;
        deltaY = rand()%(2*speed_)-speed_;
    } else {
        if (x_ < x) { // określenie współrzędnych w osi OX
            deltaX = speed_;
        } else if (x_ == x) {
            deltaX = 0;
        } else { // x_ > x
            deltaX = -speed_;
        }

        if (y_ < y) { // określenie współrzędnych w osi OY
            deltaY = speed_;
        } else if (y_ == y) {
            deltaY = 0;
        } else { // y_ > y
            deltaY = -speed_;
        }
    }

    x_ += deltaX;
    y_ += deltaY;
}
