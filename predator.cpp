#include "predator.h"
#include "visitor.h"
#include "map.h"

Predator::Predator() : Dinosaur() {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
}

Predator::Predator(Predator& parent1, Predator& parent2):Dinosaur(parent1, parent2) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
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
    if(!target_dino_->getIsHiden()){
        if(hunger()<maxHunger()){
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
            target_dino_->setBehaviourState(TO_DIE);
            target_dino_->setHunger(0); // BUGGED - 2 predators are eating the same prey - if one of them is full, the prey dies
            target_dino_ = nullptr;
            return FULL;
        }
    }
    else{
        return SERCH4EATING;
    }
}

Dinosaur::behaviourStates Predator::findTheNearestEating()
{
    target_dino_ = Map::getInstance()->getNearestNotHidenPrey(*this);
    if (target_dino_ == nullptr) {
        return SERCH4EATING;
    }else{
        target_dino_->setChased(true);
        return GO2EATING;
    }

}

Dinosaur::behaviourStates Predator::go2eating()
{
    move2position(target_dino_->gui_->position_->getXcoordinate(),target_dino_->gui_->position_->getYcoordinate());
    if(*target_dino_->gui_->position_==*position_){
        return EATING;
    }
    else{
        return GO2EATING;
    }
}

void Predator::reproducing()
{
    hunger_ -= 0.3*maxHunger();
    thirst_ -= 0.3*maxThirst;
    Predator_sharedPtr newDino = reproduce(dynamic_cast<Predator&>(*target_dino_));
    Map::getInstance()->addNewPredator(static_cast<Dinosaur_sharedPtr>(newDino));
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


void Predator::createGUIElement(){

}
