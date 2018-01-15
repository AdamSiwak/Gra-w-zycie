#ifndef PREY_H
#define PREY_H

//author: Andrzej Dzwinski, Adam Siwak

#include "dinosaur.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Cave;
class Tree;
/**
 * @brief The Prey class
 */
class Prey : public Dinosaur {
public:
    /**
     * @brief Prey constructor
     */
    Prey();

    /**
     * @brief Prey constructor (for reproduce)
     * @param parent1
     * @param parent2
     */
    Prey(Prey& parent1, Prey& parent2);

    /**
     * @brief ~Prey destructor
     */
    virtual ~Prey(){}

    /**
     * @brief accept visitor
     * @param v
     */
    virtual void accept(Visitor &v);

    /**
     * @brief eating increment this->hunger_
     * @return FULL when dinosaur is full, EATING during eating
     */
    virtual Dinosaur::behaviourStates eating();

    /**
     * @brief findTheNearestEating - dinosaur look for nearest tree
     * @return GO2EATING
     */
    virtual Dinosaur::behaviourStates  findTheNearestEating();

    /**
     * @brief go2eating
     * @return GO2EATING when still goes, EATING when is in target
     */
    virtual Dinosaur::behaviourStates go2eating();

    /**
     * @brief findPartner - dinosaur looks for partner for reproduce
     * @return SERCH4PARTNER when there isn't prey in reproductive age on the map, GO2PARTNER when has found partner
     */
    virtual Dinosaur::behaviourStates findPartner();

    /**
     * @brief reproducing of preys
     * @return REPRODUCING when the partner still exist, and SERCH4PARTNER othervise
     */
    virtual Dinosaur::behaviourStates reproducing();

    /**
    * @brief reproduce
    * @param pred - parent2
    * @return yung Pray
    */
    boost::shared_ptr<Prey> reproduce(Prey &prey);

    bool is_being_chased() { return isChased_; }
    void hide(Cave& cave);

private:

    bool isChased_;

    const QString picture_ = "dinosaur_green.png";
};

typedef boost::shared_ptr<Prey> Prey_sharedPtr;
typedef boost::weak_ptr<Prey> Prey_weakPtr;

#endif // PREY_H
