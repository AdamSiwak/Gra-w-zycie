#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QDebug>

#include "object.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "dinosaurGUI.h"
#include <iostream>

class DinosaurGUI;

class Dinosaur : public Object {
protected:

public:
    Dinosaur();
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v){}

    enum hungerStates{HUNGRY, FULL, EATING};
    enum thirstStates{THIRSTY, DRUNK, DRINKING};
    
    int age() const { return age_; }
    int speed() const { return speed_; }
    int hunger() const { return hunger_; }
    int maxHunger() const { return maxHunger_; }
    int thirst() { return thirst_; }

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    DinosaurGUI_sharedPtr gui_;

    void behaviour();

    QString toString();

protected:
    virtual void createGUIElement() = 0;

    void move_to_destination(int x = 0, int y = 0);
    void drawLotsPosition();
    void toDie();
    void go2nearestLake();
    virtual void go2nearestEating() = 0;
    virtual void go2Partner() = 0;

    Coordinates* currentDestination_;
    void energyBurning();
    virtual hungerStates eating() = 0;
    thirstStates drinking();

    void move2position(int x, int y);
    thirstStates thirstState_;


    int speed_;
    int maxHunger_;
    int age_;
    int hunger_;
    int thirst_;

    Object_weakPtr target_;

    static const int multiplier = 10000;
    static const int maxMaxEnergy = 1 * multiplier;
    static const int maxSpeed = 8;
    static const int minSpeed = 3;
    static const int minMaxHunger = 1 * multiplier;
    static const int maxMaxHunger = 3 * multiplier;
    static const int maxThirst = 1 * multiplier;
    static const int criticalThirst = 0.5 * maxThirst;
    static const int criticalHunger = 0.5 * maxMaxHunger;
    static const int maxAge = 100 * multiplier;
    static const int reproductiveAge = 0.5 * maxAge;

};

typedef boost::shared_ptr<Dinosaur> Dinosaur_sharedPtr;
typedef boost::weak_ptr<Dinosaur> Dinosaur_weakPtr;

#endif // DINOSAUR_H
