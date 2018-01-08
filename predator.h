#ifndef PREDATOR_H
#define PREDATOR_H

#include "dinosaur.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Prey;

class Predator : public Dinosaur {
public:
    Predator();
    virtual ~Predator(){}
    Predator(Predator& parent1, Predator& parent2);
    virtual void accept(Visitor &v);
    Predator* reproduce(Predator& pred);//TODO: zmienic na sprytny wskaznik
    void attack(Prey& prey);
    virtual hungerStates eating();
    virtual void go2nearestEating();
    virtual void go2Partner();

private:
    virtual void createGUIElement();

    int attack_;
    int loudness_;

    const QString picture_ = "dinosaur-brown.png";
};

typedef boost::shared_ptr<Predator> Predator_sharedPtr;
typedef boost::weak_ptr<Predator> Predator_weakPtr;

#endif // PREDATOR_H
