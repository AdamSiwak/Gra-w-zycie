#include "statictics_visitor.h"
#include "predator.h"
#include "prey.h"

StatisticsVisitor::StatisticsVisitor(Chart* chart) : chart_(chart) {}

QString& StatisticsVisitor::toString() {
    return parameters_;
}

void StatisticsVisitor::TimeMomentBegin() {
    averageSpeed_ = 0;
    averageAge_ = 0;
    averageMaxHunger_ = 0;
    averageHunger_ = 0;
    averageThirst_ = 0;
    alive_ = 0;
}

void StatisticsVisitor::TimeMomentEnd() {
    if (alive_ > 0) {
        averageSpeed_ /= alive_;
        averageAge_ /= alive_;
        averageMaxHunger_ /= alive_;
        averageHunger_ /= alive_;
        averageThirst_ /= alive_;
    }

    chart_->addData(averageAge_, averageSpeed_, averageMaxHunger_, averageHunger_, averageThirst_, alive_);

    parameters_ = "alive: " + QString::number(alive_) + "\n";
    parameters_ += "average speed: " + QString::number(averageSpeed_) + "\n";
    parameters_ += "average age: " + QString::number(averageAge_) + "\n";
    parameters_ += "average max hunger: " + QString::number(averageMaxHunger_) + "\n";
    parameters_ += "average hunger: " + QString::number(averageHunger_) + "\n";
    parameters_ += "average thirst: " + QString::number(averageThirst_) + "\n";
}

void StatisticsVisitor::visit(Predator& predator) {
    averageSpeed_ += predator.speed();
    averageAge_ += predator.age();
    averageMaxHunger_ += predator.maxHunger();
    averageHunger_ += predator.hunger();
    averageThirst_ += predator.thirst();
    alive_ += 1;
}

void StatisticsVisitor::visit(Prey& prey) {
    averageSpeed_ += prey.speed();
    averageAge_ += prey.age();
    averageMaxHunger_ += prey.maxHunger();
    averageHunger_ += prey.hunger();
    averageThirst_ += prey.thirst();
    alive_ += 1;
}
