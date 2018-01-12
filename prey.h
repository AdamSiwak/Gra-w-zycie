#ifndef PREY_H
#define PREY_H

#include "dinosaur.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Cave;
class Tree;

class Prey : public Dinosaur {
public:
    Prey();
    Prey(Prey& parent1, Prey& parent2);
    virtual ~Prey(){}
    virtual void accept(Visitor &v);
    virtual Dinosaur::behaviourStates eating();
    virtual void findTheNearestEating();
    virtual Dinosaur::behaviourStates go2eating();
    virtual Dinosaur::behaviourStates findPartner();
    virtual void reproducing();

    boost::shared_ptr<Prey> reproduce(Prey &prey);
    bool is_being_chased() { return isChased_; }
    void hide(Cave& cave);

    int defence() { return defence_; }

private:
    virtual void createGUIElement();

    int defence_;
    int hearingDistance_;

    bool isChased_;

    const QString picture_ = "dinosaur_green.png";
};

typedef boost::shared_ptr<Prey> Prey_sharedPtr;
typedef boost::weak_ptr<Prey> Prey_weakPtr;

#endif // PREY_H
