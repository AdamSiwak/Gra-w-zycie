#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QDebug>

#include "object.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "dinosaurGUI.h"

class DinosaurGUI;
class Water;

class Dinosaur {
protected:

public:
    Dinosaur();
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v){}

    enum hungerStates{HUNGRY, FULL, EATING};
    enum thirstStates{THIRSTY, DRUNK, DRINKING};
    
    int age() const { return age_; }
    int maxEnergy() const { return maxEnergy_; }
    int energy() const { return energy_; }
    int speed() const { return speed_; }
    int sightRange() const { return sightRange_; }
    int sightAngle() const { return sightAngle_; }
    int hunger() const { return hunger_; }
    int maxHunger() const { return maxHunger_; }
    int thirst() const { return thirst_; }

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    void move2position(int x, int y);


    void move();
    void drink() {
        thirst_ = 0;
    }

    DinosaurGUI* gui_;

    Coordinates* currentDestination_;
    void energyBurning();
    virtual hungerStates eating() = 0;
    thirstStates drinking();
    void behaviour();
    void toDie();
    void go2nearestLake();
    virtual void go2nearestEating() = 0;
    virtual void go2Partner() = 0;

protected:
    virtual void createGUIElement() = 0;
    void analyze_surroundings();

    void move_to_destination(int x = 0, int y = 0);

    int maxEnergy_;
    int speed_;
    int sightRange_;
    int sightAngle_;
    int maxHunger_;

    int energy_;
    int age_;
    int hunger_;
    int thirst_;

    int rotation;

    boost::weak_ptr<Dinosaur> target;

    Water* last_water;

    static const int maxMaxEnergy = 10000;
    static const int maxSpeed = 5;
    static const int maxSightRange = 10;
    static const int maxSightAngle = 270;
    static const int minMaxHunger = 10000;
    static const int maxMaxHunger = 30000;
    static const int maxThirst = 10000;
    static const int criticalThirst = 0.5 * maxThirst;
    static const int criticalHunger = 0.5 * maxMaxHunger;
    static const int maxAge = 100;
    static const int reproductiveAge = 50;

};

#endif // DINOSAUR_H
