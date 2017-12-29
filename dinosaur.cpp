#include "dinosaur.h"
#include <QDebug>

Dinosaur::Dinosaur() : age_(0), energy_(100), speed_(rand()%maxSpeed), sightRange_(rand()%maxSightRange), sightAngle_(rand()%maxSightAngle), maxHunger_(minMaxHunger + rand()%(maxMaxHunger-minMaxHunger)), hunger_(0), thirst_(0) {
    // TODO: zmienic kolejnosc w liscie inicjalizacyjnej
    // TODO: ograniczenia jednych parametrów względem innych
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
    while ((position_->getXcoordinate() != x) && (position_->getYcoordinate() != y)){
        if (x>position_->getXcoordinate()){
            stepRight();
        }
        else if (x<position_->getXcoordinate()){
            stepRight();
        }
        if(y>position_->getYcoordinate()){
            stepDown();
        }
        else if(y<position_->getYcoordinate()){
            stepUp();
        }
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
    for (int i = position_->x_-1; i <= position_->x_+1; ++i)
        for (int j = position_->y_-1; j <= position_->y_+1; ++j)
            if (i != position_->x_ || j != position_->y_) {
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
        if (position_->x_ < x) { // określenie współrzędnych w osi OX
            deltaX = speed_;
        } else if (position_->x_ == x) {
            deltaX = 0;
        } else { // x_ > x
            deltaX = -speed_;
        }

        if (position_->y_ < y) { // określenie współrzędnych w osi OY
            deltaY = speed_;
        } else if (position_->y_ == y) {
            deltaY = 0;
        } else { // y_ > y
            deltaY = -speed_;
        }
    }

    position_->x_ += deltaX;
    position_->y_ += deltaY;
}
