#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QDebug>

#include "object.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "dinosaurGUI.h"

class DinosaurGUI;
class Water;

class Dinosaur : public Object {
public:
    Dinosaur();
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v){}
    
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
protected:
    virtual void createGUIElement() = 0;
    void analyze_surroundings();

    void move_to_destination(int x = 0, int y = 0);


    DinosaurGUI* gui_;

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

    static const int maxSpeed = 5;
    static const int maxSightRange = 10;
    static const int maxSightAngle = 270;
    static const int minMaxHunger = 100;
    static const int maxMaxHunger = 300;
    static const int maxThirst = 100;
    static const int criticalThirst = maxThirst - 20;
};

#endif // DINOSAUR_H
