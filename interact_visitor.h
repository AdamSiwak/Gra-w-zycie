#ifndef INTERACT_VISITOR_H
#define INTERACT_VISITOR_H

#include "visitor.h"
#include "map.h"

/**
 * @brief interact
 * @param a
 * @param b
 */
void interact(Object& a, Dinosaur& b) {
    InteractVisitor visitor(a);
    b.accept(visitor);
}

/**
 * @brief The InteractVisitor class
 */
class InteractVisitor : public Visitor { //rozstrzyga dwa typy
    InteractVisitor(Object& obj) : obj_(obj) {}
    virtual void visit(Predator& pred) {
        PredatorVisitor predVisitor(pred);
        obj_.accept(predVisitor);
    }
    virtual void visit(Prey& prey) {
        PreyVisitor preyVisitor(prey);
        obj_.accept(preyVisitor);
    }

    Object& obj_;
};

/**
 * @brief The PredatorVisitor class
 */
class PredatorVisitor : public Visitor {
    /**
     * @brief PredatorVisitor constructor
     * @param pred
     */
    PredatorVisitor(Predator& pred) : pred_(pred) {}
    virtual void visit(Predator& pred) { // predator x predator - new predator
        Map::getInstance().add_new_dinosaur(pred_.reproduce(pred));
    }
    virtual void visit(Prey& prey) { // predator x prey - attack
        pred_.attack(prey);
    }
    virtual void visit(Water& water) { // predator x water - drink
        pred_.drink(water);
    }
    virtual void visit(Tree&) {} // predator x tree - no action
    virtual void visit(Cave&) {} // predator x cave - no action

    Predator& pred_;
};

/**
 * @brief The PreyVisitor class
 */
class PreyVisitor : public Visitor {
    /**
     * @brief PreyVisitor constructor
     * @param prey
     */
    PreyVisitor(Prey& prey) : prey_(prey) {}
    virtual void visit(Predator& pred) { // prey x predator - attack
        pred.attack(prey_);
    }
    virtual void visit(Prey& prey) { // prey x prey - new prey
        Map::getInstance().add_new_dinosaur(prey_.reproduce(prey));
    }
    virtual void visit(Water& water) { // prey x water - drink
        prey_.drink(water);
    }
    virtual void visit(Tree& tree) { // prey x tree - eat
        prey_.eat();
    }
    virtual void visit(Cave& cave) { // prey x cave - remember | hide
        prey_.set_last_cave(cave);
        if (prey_.is_being_chased()) {
            prey_.hide(cave);
        }
    }

    Prey& prey_;
};

#endif // INTERACT_VISITOR_H
