#include "predator.h"
#include "visitor.h"
#include "map.h"

Predator::Predator() : Dinosaur(), attack_(rand()%100), loudness_(rand()%100) {
    gui_ = DinosaurGUI_sharedPtr(new DinosaurGUI(picture_,0.15,this));
}

Predator::Predator(Predator& parent1, Predator& parent2) {
    // TODO: dziedziczenie cech
    age_ = 0;
    speed_ = (parent1.speed_ + parent2.speed_)/2;;
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

Predator_sharedPtr Predator::reproduce(Predator &pred) {
    Predator_sharedPtr child = Predator_sharedPtr(new Predator(*this, pred));
    return child;
}

Dinosaur::hungerStates Predator::eating()
{

}

void Predator::go2nearestEating()
{
    target_dino_ = Map::getInstance()->getNearestPrey(*this);
    move2position(target_dino_->gui_->position_->getXcoordinate(),target_dino_->gui_->position_->getYcoordinate());
}

void Predator::go2Partner()
{
    target_ = Map::getInstance()->getNearestPredator(*this);
    move2position(target_dino_->gui_->position_->getXcoordinate(),target_dino_->gui_->position_->getYcoordinate());
}

void Predator::createGUIElement(){

}
