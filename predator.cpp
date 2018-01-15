#include "predator.h"
#include "visitor.h"
#include "map.h"

Predator::Predator() : Dinosaur() {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
    setIsHiden(false);
}

Predator::Predator(Predator& parent1, Predator& parent2):Dinosaur(parent1, parent2) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
    setIsHiden(false);
}

void Predator::accept(Visitor &v) {
    v.visit(*this);
}

boost::shared_ptr<Predator> Predator::reproduce(Predator &pred)
{
    Predator_sharedPtr child = static_cast<Predator_sharedPtr>(new Predator(*this, pred));
    return child;
}

Dinosaur::behaviourStates Predator::eating()
{

    if (target_dino_.use_count() != 0 && !target_dino_->getIsHiden()) {
        if(hunger()<maxHunger_){
            hunger_+=10;
            if (target_dino_->hunger() <= 10) {
                target_dino_->setHunger(0);
                target_dino_ = nullptr;
                return SERCH4EATING;
            } else {
                target_dino_->setHunger(target_dino_->hunger() - 10);
            }
            target_dino_->setBehaviourState(IS_DEVOURED);
            return EATING;
        }
        else{
   //         target_dino_->setBehaviourState(TO_DIE);
 //           target_dino_->setHunger(0); // BUGGED - 2 predators are eating the same prey - if one of them is full, the prey dies
            target_dino_ = nullptr;
            return FULL;
        }
    } else {
        if (*currentDestination_ == *position_) {
            drawLotsPosition();
        }
        move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());
        return SERCH4EATING;
    }
}

Dinosaur::behaviourStates Predator::findTheNearestEating()
{
   target_dino_ = Map::getInstance()->getNearestPrey(*this);
   if (target_dino_ == nullptr) {
       if (*currentDestination_ == *position_) {
           drawLotsPosition();
       }
       move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());

       return SERCH4EATING;
   }else{
       target_dino_->setChased(true);
       return GO2EATING;
   }
}

Dinosaur::behaviourStates Predator::go2eating()
{
    if (target_dino_.use_count() != 0 && !target_dino_->getIsHiden()) {
        move2position(target_dino_->gui_->position_->getXcoordinate(),target_dino_->gui_->position_->getYcoordinate());
        if(*target_dino_->gui_->position_==*position_){
            return EATING;
        }
        else{
            return GO2EATING;
        }
    } else {
        if (*currentDestination_ == *position_) {
            drawLotsPosition();
        }
        move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());
        return SERCH4EATING;
    }
}

Dinosaur::behaviourStates Predator::reproducing()
{
    if (target_dino_.use_count() != 0) {
        hunger_ -= 0.5*maxHunger();
        thirst_ -= 0.5*maxThirst;
        Predator_sharedPtr newDino = reproduce(dynamic_cast<Predator&>(*target_dino_));
        Map::getInstance()->addNewPredator(static_cast<Dinosaur_sharedPtr>(newDino));
        return REPRODUCING;
    } else {
        if (*currentDestination_ == *position_) {
            drawLotsPosition();
        }
        move2position(currentDestination_->getXcoordinate(),currentDestination_->getYcoordinate());
        return SERCH4PARTNER;
    }
}

Dinosaur::behaviourStates Predator::findPartner()
{
    target_dino_ = Map::getInstance()->getNearestReproductivePredator(*this);
    if(target_dino_!=nullptr){
        return GO2PARTNER;
    }
    else{
        return SERCH4PARTNER;
    }
}

