#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QDebug>

#include "object.h"
#include "dinosaurGUI.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Visitor;


class Dinosaur : public Object {
public:
    Dinosaur();
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v) const = 0; // implementacja wzorca wizytatora

//    int age() const { return age_; }
//    int energy() const { return energy_; }
//    int speed() const { return speed_; }
//    int sightRange() const { return sightRange_; }
//    int sightAngle() const { return sightAngle_; }
//    int hunger() const { return hunger_; }
//    int maxHunger() const { return maxHunger_; }
//    int thirst() const { return thirst_; }

    void move();
    //void attack();
    void drink();
    //void reproduce();

protected:
    virtual void createGUIElement() = 0;
    virtual void analyze_surroundings() = 0;

    void move_to_destination(int x = 0, int y = 0);


    DinosaurGUI* gui_;
    int age_;
    int max_energy_;
    int energy_;
    int speed_;
    int sightRange_;
    int sightAngle_;
    int maxHunger_;
    int hunger_;
    int thirst_;
    boost::weak_ptr<Dinosaur> target; //weakptr

    static const int maxSpeed = 5;
    static const int maxSightRange = 10;
    static const int maxSightAngle = 270;
    static const int minMaxHunger = 100;
    static const int maxMaxHunger = 300;
    static const int maxThirst = 100;
    static const int criticalThirst = 20;
};

#endif // DINOSAUR_H
