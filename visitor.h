#ifndef VISITOR_H
#define VISITOR_H

class Object;
class Dinosaur;
class Predator;
class Prey;
class Lake;
class Tree;
class Cave;

/**
 * @brief The Visitor class (abstract)
 */
class Visitor { //wizytator bazowy
public:
    virtual void visit(Predator&) = 0;
    virtual void visit(Prey&) = 0;
    virtual void visit(const Lake&) = 0;
    virtual void visit(const Tree&) = 0;
    virtual void visit(const Cave&) = 0;
};

#endif // VISITOR_H
