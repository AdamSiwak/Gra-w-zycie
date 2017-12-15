#include "predator.h"
#include "visitor.h"

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

void Predator::createGUIElement() {

}
