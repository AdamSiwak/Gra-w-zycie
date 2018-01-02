#include "dinosaur.h"

#include <QDebug>
#include <QTimer>

Dinosaur::Dinosaur() : age_(0), energy_(100), speed_(rand()%maxSpeed), sightRange_(rand()%maxSightRange), sightAngle_(rand()%maxSightAngle), maxHunger_(minMaxHunger + rand()%(maxMaxHunger-minMaxHunger)), hunger_(0), thirst_(0) {
    // TODO: zmienic kolejnosc w liscie inicjalizacyjnej
    // TODO: ograniczenia jednych parametrów względem innych
    currentDestination_ = new Coordinates();
    currentDestination_->setXcoordinate(rand()%currentDestination_->MAX_X_-currentDestination_->MAX_X_/2);
    currentDestination_->setYcoordinate(rand()%currentDestination_->MAX_Y_-currentDestination_->MAX_Y_/2);
}


//Dinosaur::Dinosaur() {

//}

void Dinosaur::stepRight(){
    gui_->stepRight();
}
void Dinosaur::stepLeft(){
    gui_->stepLeft();
}
void Dinosaur::stepUp(){
    gui_->stepUp();
}
void Dinosaur::stepDown(){
    gui_->stepDown();
}

void Dinosaur::move2position(int x, int y)
{
    if (x<gui_->position_->getXcoordinate()){
        stepLeft();
    }
    else if (x>gui_->position_->getXcoordinate()){
        stepRight();
    }
    if(y<gui_->position_->getYcoordinate()){
        stepUp();
    }
    else if(y>gui_->position_->getYcoordinate()){
        stepDown();
    }
}



void Dinosaur::move() {
    this->analyze_surroundings();

    if (this->thirst_ > Dinosaur::criticalThirst) { // ruch w kierunku źródła

    } else if (this->target.expired() != false) { // ruch w kierunku celu

    } else { // ruch w losowym kierunku
        move_to_destination(0,0);
    }
}

void Dinosaur::analyze_surroundings() {
    for (int i = gui_->position_->x_-1; i <= gui_->position_->x_+1; ++i)
        for (int j = gui_->position_->y_-1; j <= gui_->position_->y_+1; ++j)
            if (i != gui_->position_->x_ || j != gui_->position_->y_) {
                // TODO: analiza
            }
}

void Dinosaur::move_to_destination(int x, int y) {//int x = 0, int y = 0) {
    int deltaX;
    int deltaY;

    if (x == 0 && y == 0) { // kierunek losowy
        deltaX = rand()%(2*speed_)-speed_;
        deltaY = rand()%(2*speed_)-speed_;
    } else {
        if (gui_->position_->x_ < x) { // określenie współrzędnych w osi OX
            deltaX = speed_;
        } else if (gui_->position_->x_ == x) {
            deltaX = 0;
        } else { // x_ > x
            deltaX = -speed_;
        }

        if (gui_->position_->y_ < y) { // określenie współrzędnych w osi OY
            deltaY = speed_;
        } else if (gui_->position_->y_ == y) {
            deltaY = 0;
        } else { // y_ > y
            deltaY = -speed_;
        }
    }

    gui_->position_->x_ += deltaX;
    gui_->position_->y_ += deltaY;
}
