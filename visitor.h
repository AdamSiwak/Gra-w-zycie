#ifndef VISITOR_H
#define VISITOR_H

class Object;
class Dinosaur;
class Predator;
class Prey;
class Water;
class Tree;
class Cave;

class Visitor { //wizytator bazowy
public:
    virtual void visit(Predator&) = 0;
    virtual void visit(Prey&) = 0;
    virtual void visit(const Water& water) = 0;
    virtual void visit(Tree& tree) = 0;
    virtual void visit(const Cave& cave) = 0;
};

#endif // VISITOR_H
