#include "predator.h"
#include "visitor.h"
#include "map.h"

Predator::Predator() : Dinosaur(), attack_(rand()%100), loudness_(rand()%100) {
    gui_ = new DinosaurGUI(picture_,0.15);

//    age_ = 0;
//    maxEnergy_ = rand()%maxMaxEnergy;
//    energy_ = rand()%maxEnergy_;
//    speed_ = rand()%maxSpeed;
//    sightRange_ = rand()%maxSightRange;
//    sightAngle_ = rand()%maxSightAngle;
//    maxHunger_ = maxHunger();
//    hunger_ = 0;
//    thirst_ = 0;
}

Predator::Predator(Predator& parent1, Predator& parent2) {
    // TODO: dziedziczenie cech
    age_ = 0;
    maxEnergy_ = (parent1.maxEnergy_ + parent2.maxEnergy_)/2;
    energy_ = (parent1.energy_ + parent2.energy_)/2;
    speed_ = (parent1.speed_ + parent2.speed_)/2;
    sightRange_ = (parent1.sightRange_ + parent2.sightRange_)/2;
    sightAngle_ = (parent1.sightAngle_ + parent2.sightAngle_)/2;
    maxHunger_ = (parent1.maxHunger_ + parent2.maxHunger_)/2;
    hunger_ = 0;
    thirst_ = 0;
    currentDestination_->setXcoordinate(rand()%currentDestination_->MAX_X_-currentDestination_->MAX_X_/2);
    currentDestination_->setYcoordinate(rand()%currentDestination_->MAX_Y_-currentDestination_->MAX_Y_/2);

    attack_ = (parent1.attack_ + parent2.attack_)/2;
    loudness_ = (parent1.loudness_ + parent2.loudness_)/2;
}

void Predator::accept(Visitor &v) {
    v.visit(*this);
}

Predator* Predator::reproduce(Predator &pred) {
    Predator* child = new Predator(*this, pred);
    return child;
}

Dinosaur::hungerStates Predator::eating()
{

}

void Predator::go2nearestEating()
{
    currentDestination_ = Map::getInstance()->getNearestPrey(this);
}

void Predator::go2Partner()
{
    currentDestination_ = Map::getInstance()->getNearestPredator(this);
}

void Predator::createGUIElement(){

}
