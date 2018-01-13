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
    Dinosaur(Dinosaur& parent1, Dinosaur& parent2);
    virtual ~Dinosaur() {}
    virtual void accept(Visitor& v){Q_UNUSED(v);}

    enum behaviourStates{SERCH4LAKE, GO2LAKE, DRUNK, DRINKING,
                         SERCH4EATING, GO2EATING, FULL, EATING,
                         SERCH4PARTNER, GO2PARTNER, REPRODUCING,
                         SERCH4CAVE, GO2CAVE, HIDING, IS_DEVOURED,
                         TO_DIE,
                         OTHER
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
    int maxAge() const { return maxAge_; }

    void setHunger(int hunger) { hunger_ = hunger; }

    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    DinosaurGUI_sharedPtr gui_;

    void makeADecision();
    void behaviour();

    QString toString();

    bool chased() const;
    void setChased(bool chased);

    behaviourStates behaviourState() const;
    void setBehaviourState(const behaviourStates &behaviourState);

    static int getReproductiveAge();

    bool getIsDevoured() const;
    void setIsDevoured(bool value);

    void findCave();
    void isDevoured();

    bool getIsHiden() const;
    void setIsHiden(bool isHiden);

protected:
    Coordinates_sharedPtr currentDestination_;
    behaviourStates behaviourState_, prevBehaviourState_;
    dinosaurNeeds needs_, prevNeeds_;
    virtual void createGUIElement() = 0;

    void drawLotsPosition();
    void toDie();
    void go2nearestLake();
    virtual behaviourStates findTheNearestEating() = 0;
    virtual behaviourStates go2eating() = 0;
    virtual behaviourStates findPartner() = 0;
    virtual behaviourStates reproducing() = 0;

    void makeAdecision();
    void energyBurning();
    virtual behaviourStates eating() = 0;
    behaviourStates drinking();

    void move2position(int x, int y);
    void move();

    void showMyStatistics();

    int speed_;
    int age_;
    int maxHunger_;
    int hunger_;
    int thirst_;

    bool chased_;
    bool isDevoured_;
    bool isHiden_;

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
    static const int maxAge_ = 1 * multiplier;
    static const int reproductiveAge = 0.5 * maxAge_;
};


#endif // DINOSAUR_H
