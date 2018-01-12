#ifndef STATICTICS_VISITOR_H
#define STATICTICS_VISITOR_H

#include "visitor.h"
#include <QString>
#include "chart.h"

class StatisticsVisitor : public Visitor {
public:
    StatisticsVisitor(Chart*);
    QString& toString();
    void TimeMomentBegin();
    void TimeMomentEnd();
    virtual void visit(Predator& predator);
    virtual void visit(Prey& prey);
    virtual void visit(const Lake&) {}
    virtual void visit(const Tree&) {}
    virtual void visit(const Cave&) {}

private:
    float averageSpeed_;
    float averageAge_;
    float averageMaxHunger_;
    float averageHunger_;
    float averageThirst_;
    float alive_;

    float averageAttack_; // predators only
    float averageDefence_; // preys only

    QString parameters_;

    Chart* chart_;
};

#endif // STATICTICS_VISITOR_H
