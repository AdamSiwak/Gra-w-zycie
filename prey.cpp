#include "prey.h"
#include "visitor.h"

Prey::Prey(Prey& parent1, Prey& parent2) {
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

    defence_ = (parent1.defence_ + parent2.defence_)/2;
    hearingDistance_ = (parent1.hearingDistance_ + parent2.hearingDistance_)/2;

    isChased_ = false;
}

void Prey::createGUIElement() {

}

void Prey::accept(Visitor &v) {
    v.visit(*this);
}
