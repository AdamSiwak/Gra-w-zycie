#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QDebug>

#include "object.h"
#include "dinosaurGUI.h"

class Visitor;

class Dinosaur : public Object {
public:
    Dinosaur() : age_(0), energy_(100), speed_(rand()%maxSpeed), sightRange_(rand()%maxSightRange), sightAngle_(rand()%maxSightAngle), hunger_(0), thirst_(0) {qDebug() << sightAngle_;}
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v) const = 0;

    int age() const { return age_; }
    int energy() const { return energy_; }
    int speed() const { return speed_; }
    int sightRange() const { return sightRange_; }
    int sightAngle() const { return sightAngle_; }
    int hunger() const { return hunger_; }
    int thirst() const { return thirst_; }

    void move();
    //void attack();
    void analyze_surroundings();
    void drink();
    //void reproduce();


private:
    virtual void createGUIElement() = 0;

    DinosaurGUI* gui_;
    int age_;
    int energy_;
    int speed_;
    int sightRange_;
    int sightAngle_;
    int hunger_;
    int thirst_;
    Dinosaur* target; //weakptr

    const int maxSpeed = 5;
    const int maxSightRange = 10;
    const int maxSightAngle = 270;
    const int maxHunger = 100;
    const int maxThirst = 100;
};

#endif // DINOSAUR_H
