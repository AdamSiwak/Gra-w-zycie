#include "statictics_visitor.h"
#include "predator.h"
#include "prey.h"

QString& StatisticsVisitor::toString() {
    *(--averageSpeed_.end()) /= *(--alive_.end());
    *(--averageAge_.end()) /= *(--alive_.end());
    *(--averageMaxHunger_.end()) /= *(--alive_.end());
    *(--averageHunger_.end()) /= *(--alive_.end());
    *(--averageThirst_.end()) /= *(--alive_.end());
    *(--averageAttack_.end()) /= *(--alive_.end());

    parameters_ = "alive: " + QString::number(*(--alive_.end())) + "\n";
    parameters_ += "average speed: " + QString::number(*(--averageSpeed_.end())) + "\n";
    parameters_ += "average age: " + QString::number(*(--averageAge_.end())) + "\n";
    parameters_ += "average max hunger: " + QString::number(*(--averageMaxHunger_.end())) + "\n";
    parameters_ += "average hunger: " + QString::number(*(--averageHunger_.end())) + "\n";
    parameters_ += "average thirst: " + QString::number(*(--averageThirst_.end())) + "\n";
    parameters_ += "average attack: " + QString::number(*(--averageAttack_.end())) + "\n";

    return parameters_;
}

void StatisticsVisitor::nextTimeMoment() {
    averageSpeed_.push_back(0);
    averageAge_.push_back(0);
    averageMaxHunger_.push_back(0);
    averageHunger_.push_back(0);
    averageThirst_.push_back(0);
    alive_.push_back(0);
    averageAttack_.push_back(0);
    averageDefence_.push_back(0);
}

void StatisticsVisitor::visit(Predator& predator) {
    *(--averageSpeed_.end()) += predator.speed();
    *(--averageAge_.end()) += predator.age();
    *(--averageMaxHunger_.end()) += predator.maxHunger();
    *(--averageHunger_.end()) += predator.hunger();
    *(--averageThirst_.end()) += predator.thirst();
    *(--alive_.end()) += 1;
    *(--averageAttack_.end()) += predator.attack();
}

void StatisticsVisitor::visit(Prey& prey) {
    *(--averageSpeed_.end()) += prey.speed();
    *(--averageAge_.end()) += prey.age();
    *(--averageMaxHunger_.end()) += prey.maxHunger();
    *(--averageHunger_.end()) += prey.hunger();
    *(--averageThirst_.end()) += prey.thirst();
    *(--alive_.end()) += 1;
    *(--averageDefence_.end()) += prey.defence();
}
