#include "dinosaur.h"
#include "map.h"

#include <QDebug>
#include <QTimer>


Dinosaur::Dinosaur() : age_(0), speed_(rand()%maxSpeed), maxHunger_(minMaxHunger + rand()%(maxMaxHunger-minMaxHunger)), hunger_(0), thirst_(0) {
    // TODO: zmienic kolejnosc w liscie inicjalizacyjnej
    // TODO: ograniczenia jednych parametrów względem innych
    currentDestination_ = new Coordinates();
    currentDestination_->setXcoordinate(rand()%currentDestination_->MAX_X_-currentDestination_->MAX_X_/2);
    currentDestination_->setYcoordinate(rand()%currentDestination_->MAX_Y_-currentDestination_->MAX_Y_/2);
}


//Dinosaur::Dinosaur() {

//}

void Dinosaur::stepRight(){
    if(!gui_->isSelected()){
        gui_->stepRight();
        energyBurning();
    }
}
void Dinosaur::stepLeft(){
    if(!gui_->isSelected()){
        gui_->stepLeft();
        energyBurning();
    }
}
void Dinosaur::stepUp(){
    if(!gui_->isSelected()){
        gui_->stepUp();
        energyBurning();
    }
}
void Dinosaur::stepDown(){
    if(!gui_->isSelected()){
        gui_->stepDown();
        energyBurning();
    }
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

   // } else if (this->target_.expired() != false) { // ruch w kierunku celu

    } else { // ruch w losowym kierunku
        move_to_destination(0,0);
    }
}

void Dinosaur::analyze_surroundings() {
    for (int i = gui_->position_->getXcoordinate()-1; i <= gui_->position_->getXcoordinate()+1; ++i)
        for (int j = gui_->position_->getYcoordinate()-1; j <= gui_->position_->getYcoordinate()+1; ++j)
            if (i != gui_->position_->getXcoordinate() || j != gui_->position_->getYcoordinate()) {
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
        if (gui_->position_->getXcoordinate() < x) { // określenie współrzędnych w osi OX
            deltaX = speed_;
        } else if (gui_->position_->getXcoordinate() == x) {
            deltaX = 0;
        } else { // x_ > x
            deltaX = -speed_;
        }

        if (gui_->position_->getYcoordinate() < y) { // określenie współrzędnych w osi OY
            deltaY = speed_;
        } else if (gui_->position_->getYcoordinate() == y) {
            deltaY = 0;
        } else { // y_ > y
            deltaY = -speed_;
        }
    }

    gui_->position_->setXcoordinate(gui_->position_->getXcoordinate() + deltaX);
    gui_->position_->setYcoordinate(gui_->position_->getYcoordinate() + deltaY);
}

void Dinosaur::drawLotsPosition()
{
    currentDestination_->setRandomCoordiantes();
}

void Dinosaur::energyBurning(){
    hunger_--;
    thirst_--;
}

Dinosaur::hungerStates Dinosaur::eating()
{
    if(hunger()<maxHunger()){
        hunger_++;
        return EATING;
    }
    else{
        return FULL;
    }
}

Dinosaur::thirstStates Dinosaur::drinking()
{
    if(thirst()<maxThirst){
        thirst_++;
        return DRINKING;
    }
    else{
        return DRUNK;
    }
}

void Dinosaur::behaviour()
{
/*    if(thirst() == 0 || hunger() == 0|| age()== maxAge){
        toDie();
    }
    else*/ if(thirst()<criticalThirst){
        go2nearestLake();
      //  if(target_->position_->getRealYcoordinate() ==)
    }
    else if(hunger()<criticalHunger){
        go2nearestEating();
    }
    else if(age()>reproductiveAge){
        go2Partner();
    }
    else {
        if(gui_->position_->getRealXcoordinate()==currentDestination_->getXcoordinate() && gui_->position_->getRealYcoordinate()==currentDestination_->getYcoordinate()){
            drawLotsPosition();
        }
        else{
            move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());
        }
    }

}

void Dinosaur::toDie()
{
   // ~Dinosaur();
}

void Dinosaur::go2nearestLake()
{
    target_ = Map::getInstance()->getNearestLake(this);
    move2position(target_->position_->getXcoordinate(),target_->position_->getYcoordinate());
}

