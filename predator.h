#ifndef PREDATOR_H
#define PREDATOR_H

#include "dinosaur.h"

class Prey;

class Predator : public Dinosaur {
public:
    Predator();
    virtual ~Predator(){}
    Predator(Predator& parent1, Predator& parent2);
    virtual void accept(Visitor &v);
    Predator* reproduce(Predator& pred);
    void attack(Prey& prey);

private:
    virtual void createGUIElement();

    int attack_;
    int loudness_;

    const QString picture_ = "dinosaur-brown.png";
};

#endif // PREDATOR_H
