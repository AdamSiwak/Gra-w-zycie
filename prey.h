#ifndef PREY_H
#define PREY_H

#include "dinosaur.h"

class Cave;
class Tree;

class Prey : public Dinosaur {
public:
    Prey() : Dinosaur(), defence_(rand()%100), hearingDistance_(rand()%10), isChased_(false) {}
    Prey(Prey& parent1, Prey& parent2);
    virtual ~Prey(){}
    virtual void accept(Visitor &v);

    Prey* reproduce(Prey& prey);
    void eat();
    void set_last_cave(Cave& cave) { last_cave = &cave; }
    bool is_being_chased() { return isChased_; }
    void hide(Cave& cave);

private:
    virtual void createGUIElement();

    int defence_;
    int hearingDistance_;

    bool isChased_;

    Cave* last_cave;

    const QString picture = ":/pictures/dinosaur-green.png";
};

#endif // PREY_H
