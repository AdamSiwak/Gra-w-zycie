#ifndef PREY_H
#define PREY_H

#include "dinosaur.h"

class Cave;
class Tree;

class Prey : public Dinosaur {
public:
    Prey();
    Prey(Prey& parent1, Prey& parent2);
    virtual ~Prey(){}
    virtual void accept(Visitor &v);
    virtual hungerStates eating();
    virtual void go2nearestEating();
    virtual void go2Partner();

    Prey* reproduce(Prey& prey);
    void set_last_cave(Cave& cave) { last_cave = &cave; }
    bool is_being_chased() { return isChased_; }
    void hide(Cave& cave);

private:
    virtual void createGUIElement();

    int defence_;
    int hearingDistance_;

    bool isChased_;

    Cave* last_cave;

    const QString picture_ = "dinosaur_green.png";
};

#endif // PREY_H
