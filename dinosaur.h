//author: Andrzej Dzwinski, Adam Siwak

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
/**
 * @brief The Dinosaur class (abstract)
 */
class Dinosaur : public Object {
protected:

public:
    /**
     * @brief Dinosaur Constructor
     */
    Dinosaur();
    /**
     * @brief Dinosaur Constructor
     * @param parent1
     * @param parent2
     */
    Dinosaur(Dinosaur& parent1, Dinosaur& parent2);
    /**
     * @brief ~Dinosaur Destructor
     */
    virtual ~Dinosaur() {}
    /**
     * @brief accept Visitor
     * @param v
     */
    virtual void accept(Visitor& v){Q_UNUSED(v);}

    /**
     * @brief The behaviourStates enum
     */
    enum behaviourStates{SERCH4LAKE, GO2LAKE, DRUNK, DRINKING,
                         SERCH4EATING, GO2EATING, FULL, EATING,
                         SERCH4PARTNER, GO2PARTNER, REPRODUCING,
                         SERCH4CAVE, GO2CAVE, HIDING, IS_DEVOURED,
                         TO_DIE,
                         OTHER
                         };

    /**
     * @brief The dinosaurNeeds enum
     */
    enum dinosaurNeeds{
                        WANT2DRINK,
                        WANT2EAT,
                        WANT2REPRODUCE,
                        IS_DANGERED,
                        IS2OLD,
                        DONT_HAVE_ANY_NEEDS
                        };

    int getIAmHiddenByTime() const;
    void setIAmHiddenByTime(int iAmHiddenByTime);

    ///setters
    int age() const { return age_; }
    int speed() const { return speed_; }
    int hunger() const { return hunger_; }
    int maxHunger() const { return maxHunger_; }
    int thirst() const { return thirst_; }
    int maxAge() const { return maxAge_; }

    void setHunger(int hunger) { hunger_ = hunger; }

    ///functions for move one step in different directions
    void stepRight();
    void stepLeft();
    void stepUp();
    void stepDown();

    DinosaurGUI_sharedPtr gui_;

    /**
     * @brief makeADecision In this function the dinosaur decide what should now do. A result is saved in needs_:dinosaurNeeds variable.
     */
    void makeADecision();

    /**
     * @brief behaviour function is proper algorithm of dinosaur behaviour. It is based on state machine where main level is needs_:dinosaurNeeds variable and secondary is behaviourState_:behaviourStates variable;
     */
    void behaviour();

    /**
     * @brief toString
     * @return basic fields of the class are converted to QString
     */
    QString toString();

    bool chased() const;
    void setChased(bool chased);

    behaviourStates behaviourState() const;
    void setBehaviourState(const behaviourStates &behaviourState);

    static int getReproductiveAge();

    bool getIsDevoured() const;
    void setIsDevoured(bool value);

    /**
     * @brief findCave function look for nearest cave and sets it as target_:Object_sharedPtr
     */
    void findCave();
    /**
     * @brief isDevoured function rotete the picture at 180 degree when dhe dinosaur is devourted
     */
    void isDevoured();

    bool getIsHiden() const;
    void setIsHiden(bool isHiden);

protected:
    Coordinates_sharedPtr currentDestination_;
    behaviourStates behaviourState_, prevBehaviourState_;
    dinosaurNeeds needs_, prevNeeds_;

    /**
     * @brief drawLotsPosition
     */
    void drawLotsPosition();

    virtual behaviourStates findTheNearestEating() = 0;
    virtual behaviourStates go2eating() = 0;
    virtual behaviourStates findPartner() = 0;
    virtual behaviourStates reproducing() = 0;

    /**
     * @brief energyBurning decrements hunger_:int, and thirst_:int in every call(every timer tick)
     */
    void energyBurning();
    virtual behaviourStates eating() = 0;
    behaviourStates drinking();

    /**
     * @brief move2position moves the dinosaur one step in x axis and one step in y axis in x,y set direction.
     * @param x coordinate
     * @param y coordinate
     */
    void move2position(int x, int y);

    /**
     * @brief showMyStatistics when dinosaurs gui is selected (by mouse) this function displays dinosaur basic vistal parmeters in a cloud
     */
    void showMyStatistics();

    /**
     * @brief mutate mutates choosen parameter with 2% probability. If mutated, changes value of the parameter by -20% - 20%
     * @param parameter
     */
    void mutate(int* parameter);

    static const int maxSpeed = 8;
    static const int minSpeed = 3;

    int speed_;
    int age_;
    int thirst_;

    bool chased_;
    bool isDevoured_;
    bool isHiden_;

    int iAmHiddenByTime_;

    Object_sharedPtr target_;
    Dinosaur_sharedPtr target_dino_;

    static const int multiplier = 10000;
    static const int maxMaxEnergy = 1 * multiplier;
    static const int maxThirst = 1 * multiplier;
    static const int criticalThirst = 0.5 * maxThirst;

    static const int maxAge_ = 1 * multiplier;
    static const int reproductiveAge = 0.5 * maxAge_;

    static const int mutationPobabilityPercent_ = 2;

    int maxHunger_;
    int hunger_;
    int criticalHunger_;
};


#endif // DINOSAUR_H
