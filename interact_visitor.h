#ifndef INTERACT_VISITOR_H
#define INTERACT_VISITOR_H

#include "visitor.h"

void interact(Dinosaur& a, Object& b) {
    InteractVisitor visitor(a);
    b.accept(visitor);
}

class InteractVisitor : public Visitor { //rozstrzyga dwa typy
    InteractVisitor(Dinosaur& dino) : dino_(dino) {}
    virtual void visit(Predator& pred) {
        PredatorVisitor predVisitor(pred);
        dino_.accept(predVisitor);
    }
    virtual void visit(Prey& prey) {
        PreyVisitor preyVisitor(prey);
        dino_.accept(preyVisitor);
    }

    Dinosaur& dino_;
};

class PredatorVisitor : public Visitor {
    PredatorVisitor(Predator& pred) : pred_(pred) {}
    virtual void visit(Predator& pred) { // TODO: predator x predator - new predator

    }
    virtual void visit(Prey& prey) { // TODO: predator x prey - attack

    }
    virtual void visit(Water& water) { // TODO: predator x water - drink

    }

    Predator& pred_;
};

class PreyVisitor : public Visitor {
    PreyVisitor(Prey& prey) : prey_(prey) {}
    virtual void visit(Predator& pred) { // TODO: prey x predator - attack

    }
    virtual void visit(Prey& prey) { // TODO: prey x prey - new prey

    }
    virtual void visit(Water& water) { // TODO: prey x water - drink

    }
    virtual void visit(Tree& tree) { // TODO: prey x tree - eat

    }
    virtual void visit(Cave& cave) { // TODO: prey x cave - hide

    }

    Prey& prey_;
};

#endif // INTERACT_VISITOR_H
