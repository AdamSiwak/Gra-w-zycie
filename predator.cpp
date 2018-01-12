#include "predator.h"
#include "visitor.h"
#include "map.h"

Predator::Predator() : Dinosaur(), attack_(rand()%100), loudness_(rand()%100) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
}

Predator::Predator(Predator& parent1, Predator& parent2) {
    // TODO: dziedziczenie cech
    age_ = 0;
    speed_ = (parent1.speed_ + parent2.speed_)/2;
    maxHunger_ = (parent1.maxHunger_ + parent2.maxHunger_)/2;
    hunger_ = 0;
    thirst_ = 0;
    currentDestination_->setRandomCoordiantes();

    attack_ = (parent1.attack_ + parent2.attack_)/2;
    loudness_ = (parent1.loudness_ + parent2.loudness_)/2;
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
    if(hunger()<maxHunger()){
        hunger_+=10;
        target_dino_->setBehaviourState(IS_DEVOURED);
        return EATING;
    }
    else{
        target_dino_->setBehaviourState(TO_DIE);
        return FULL;
    }
}

void Predator::findTheNearestEating()
{
    target_dino_ = Map::getInstance()->getNearestPrey(*this); 
    target_dino_->setCased(true);
}

Dinosaur::behaviourStates Predator::go2eating()
{
    move2position(target_dino_->gui_->position_->getXcoordinate(),target_dino_->gui_->position_->getYcoordinate());
    if(*target_dino_->position_==*position_){
        return GO2EATING;
    }
    else{
        return EATING;
    }
}

void Predator::reproducing()
{
    hunger_ -= 0.3*maxHunger();
    thirst_ -= 0.3*maxThirst;
    Predator_sharedPtr newDino = reproduce(dynamic_cast<Predator&>(*target_dino_));
    Map::getInstance()->addNewPredator(newDino);
}

Dinosaur::behaviourStates Predator::findPartner()
{
    if(Map::getInstance()->getNearestReproductivePredator(*this)!=nullptr){
        target_dino_ = Map::getInstance()->getNearestPredator(*this);
        return GO2PARTNER;
    }
    else{
        return SERCH4PARTNER;
    }
}


void Predator::createGUIElement(){

}
