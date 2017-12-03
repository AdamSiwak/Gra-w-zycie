#ifndef VISITOR_H
#define VISITOR_H

class Predator;
class Prey;

class Visitor { //wizytator bazowy
public:
    virtual void visit(const Predator&) = 0;
    virtual void visit(const Prey&) = 0;
};

#endif // VISITOR_H
