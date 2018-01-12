#include "prey.h"
#include "visitor.h"
#include "map.h"

Prey::Prey(): Dinosaur(), defence_(rand()%100), hearingDistance_(rand()%10), isChased_(false) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));

}

Prey::Prey(Prey& parent1, Prey& parent2) {
    // TODO: dziedziczenie cech
    age_ = 0;
    speed_ = (parent1.speed_ + parent2.speed_)/2;
    maxHunger_ = (parent1.maxHunger_ + parent2.maxHunger_)/2;
    hunger_ = 0;
    thirst_ = 0;
    currentDestination_->setXcoordinate(rand()%currentDestination_->MAX_X_-currentDestination_->MAX_X_/2);
    currentDestination_->setYcoordinate(rand()%currentDestination_->MAX_Y_-currentDestination_->MAX_Y_/2);


    defence_ = (parent1.defence_ + parent2.defence_)/2;
    hearingDistance_ = (parent1.hearingDistance_ + parent2.hearingDistance_)/2;

    isChased_ = false;
}

void Prey::createGUIElement() {

}

void Prey::accept(Visitor &v) {
    v.visit(*this);
}

Dinosaur::behaviourStates Prey::eating()
{

}

void Prey::findTheNearestEating()
{
    target_ = Map::getInstance()->getNearestTree(*this);
}

Dinosaur::behaviourStates Prey::go2eating()
{
    move2position(target_->position_->getXcoordinate(),target_->position_->getYcoordinate());
    if(*target_->position_==*position_){
        return GO2EATING;
    }
    else{
        return EATING;
    }
}

void Prey::go2Partner()
{
    target_dino_ = Map::getInstance()->getNearestPrey(*this);

}
