#include "prey.h"
#include "visitor.h"
#include "map.h"

Prey::Prey(): Dinosaur(), isChased_(false) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
    setIsHiden(false);

}

Prey::Prey(Prey& parent1, Prey& parent2):Dinosaur(parent1, parent2), isChased_(false) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
    setIsHiden(false);
}

void Prey::createGUIElement() {

}

void Prey::accept(Visitor &v) {
    v.visit(*this);
}

Dinosaur::behaviourStates Prey::eating()
{
    if(hunger()<maxHunger()){
        hunger_+=100;
        return EATING;
    }
    else{
        return FULL;
    }
}

Dinosaur::behaviourStates Prey::findTheNearestEating()
{
    target_ = Map::getInstance()->getNearestTree(*this);
    return GO2EATING;
}

Dinosaur::behaviourStates Prey::go2eating()
{
    move2position(target_->position_->getXcoordinate(),target_->position_->getYcoordinate());
    if(*target_->position_==*position_){
        return EATING;
    }
    else{
        return GO2EATING;
    }
}

Dinosaur::behaviourStates Prey::findPartner()
{
    target_dino_ = Map::getInstance()->getNearestReproductivePrey(*this);
    if(target_dino_!=nullptr){
        return GO2PARTNER;
    }
    else{
        return SERCH4PARTNER;
    }
}

Dinosaur::behaviourStates Prey::reproducing()
{
    if (target_dino_.use_count() != 0) {
        hunger_ -= 0.3*maxHunger();
        thirst_ -= 0.3*maxThirst;
        Prey_sharedPtr newDino = reproduce(dynamic_cast<Prey&>(*target_dino_));
        Map::getInstance()->addNewPrey(static_cast<Dinosaur_sharedPtr>(newDino));
        return REPRODUCING;
    } else {
        if (*currentDestination_ == *position_) {
            drawLotsPosition();
        }
        move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());
        qDebug() << "USE COUNT == 0 - reproducing prey" + QString::number(maxHunger_);
        return SERCH4PARTNER;
    }
}

boost::shared_ptr<Prey> Prey::reproduce(Prey& prey)
{
    Prey_sharedPtr child = static_cast<Prey_sharedPtr>(new Prey(*this, prey));
    return child;
}


