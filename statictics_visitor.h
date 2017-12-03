#ifndef STATICTICS_VISITOR_H
#define STATICTICS_VISITOR_H

#include "visitor.h"

class StatisticsVisitor : public Visitor {
    virtual void visit(const Predator&) {

    }
};

#endif // STATICTICS_VISITOR_H
