#ifndef STATICTICS_VISITOR_H
#define STATICTICS_VISITOR_H

#include "visitor.h"
#include <QString>

class StatisticsVisitor : public Visitor {
public:
    QString& toString();
    void nextTimeMoment();
    virtual void visit(Predator& predator);
    virtual void visit(Prey& prey);
    virtual void visit(const Lake&) {}
    virtual void visit(const Tree&) {}
    virtual void visit(const Cave&) {}

private:
    std::vector<float> averageSpeed_;
    std::vector<float> averageAge_;
    std::vector<float> averageMaxHunger_;
    std::vector<float> averageHunger_;
    std::vector<float> averageThirst_;
    std::vector<float> alive_;

    std::vector<float> averageAttack_; // predators only
    std::vector<float> averageDefence_; // preys only

    QString parameters_;
};

#endif // STATICTICS_VISITOR_H
