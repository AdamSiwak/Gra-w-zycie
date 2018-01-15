//author: Adam Siwak

#ifndef STATICTICS_VISITOR_H
#define STATICTICS_VISITOR_H

#include "visitor.h"
#include <QString>
#include "chart.h"


/**
 * @brief The StatisticsVisitor class
 */
class StatisticsVisitor : public Visitor {
public:
    /**
     * @brief StatisticsVisitor constructor
     */
    StatisticsVisitor(Chart*);

    /**
     * @brief toString
     * @return parametes of population in text format
     */
    QString& toString();

    /**
     * @brief TimeMomentBegin resets averave parameters
     */
    void TimeMomentBegin();

    /**
     * @brief TimeMomentEnd calculates averave paremters of polulation
     */
    void TimeMomentEnd();

    /**
     * @brief visit - visitor for predator. Collect parametes from each Predator
     * @param predator
     */
    virtual void visit(Predator& predator);

    /**
     * @brief visit method which collect parameters prom each Preys
     * @param prey
     */
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

    Chart* chart_;
};

#endif // STATICTICS_VISITOR_H
