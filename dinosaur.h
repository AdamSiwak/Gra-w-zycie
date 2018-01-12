#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QDebug>

#include "object.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "dinosaurGUI.h"
#include <iostream>
#include "cloud.h"

class DinosaurGUI;
class Dinosaur;

typedef boost::shared_ptr<Dinosaur> Dinosaur_sharedPtr;
typedef boost::weak_ptr<Dinosaur> Dinosaur_weakPtr;

class Dinosaur : public Object {
protected:

public:
    Dinosaur();
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v){}

    enum behaviourStates{SERCH4LAKE, GO2LAKE, DRUNK, DRINKING,
                         SERCH4EATING, GO2EATING, FULL, EATING,
                         SERCH4PARTNER, GO2PARTNER, REPRODUCING,
                         ESCAPING, HIDING, IS_DEVOURED,
                         TO_DIE
                         };

    enum dinosaurNeeds{
                        WANT2DRINK,
                        WANT2EAT,
                        WANT2REPRODUCE,
                        IS_DANGERED,
                        IS2OLD,
                        DONT_HAVE_ANY_NEEDS
                        };


    
    int age() const { return age_; }
    int speed() const { return speed_; }
    int hunger() const { return hunger_; }
    int maxHunger() const { return maxHunger_; }
    int thirst() const { return thirst_; }

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    DinosaurGUI_sharedPtr gui_;

    void makeADecision();
    void behaviour();

    QString toString();

    bool cased() const;
    void setCased(bool cased);

    behaviourStates behaviourState() const;
    void setBehaviourState(const behaviourStates &behaviourState);

    static int getReproductiveAge();

protected:
    Coordinates* currentDestination_;
    behaviourStates behaviourState_;
    dinosaurNeeds needs_;
    virtual void createGUIElement() = 0;

    void move_to_destination(int x = 0, int y = 0);
    void drawLotsPosition();
    void toDie();
    void go2nearestLake();
    virtual void findTheNearestEating() = 0;
    virtual behaviourStates go2eating() = 0;
    virtual behaviourStates findPartner() = 0;
    virtual void reproducing() = 0;

    void makeAdecision();
    void energyBurning();
    virtual behaviourStates eating() = 0;
    behaviourStates drinking();

    void move2position(int x, int y);
    void move();

    void showMyStatistics();

    int speed_;
    int maxHunger_;
    int age_;
    int hunger_;
    int thirst_;

    bool cased_;

    Object_sharedPtr target_;
    Dinosaur_sharedPtr target_dino_;

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
    static const int reproductiveAge = 0.005 * maxAge;

};



#endif // DINOSAUR_H
