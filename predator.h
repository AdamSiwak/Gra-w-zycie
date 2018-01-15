#ifndef PREDATOR_H
#define PREDATOR_H

//author: Andrzej Dzwinski, Adam Siwak

#include "dinosaur.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Prey;
/**
 * @brief The Predator class
 */
class Predator : public Dinosaur {
public:
    /**
     * @brief Predator constructor
     */
    Predator();

    /**
     * @brief ~Predator destructor
     */
    virtual ~Predator(){}

    /**
     * @brief Predator constructor (for reproduce)
     * @param parent1
     * @param parent2
     */
    Predator(Predator& parent1, Predator& parent2);

    /**
     * @brief accept visitor
     * @param v
     */
    virtual void accept(Visitor &v);

    /**
     * @brief reproduce
     * @param pred - parent2
     * @return yung predator
     */
    boost::shared_ptr<Predator> reproduce(Predator &pred);

    /**
     * @brief eating increment this->hunger_, decrements victim hanger_
     * @return FULL when dinosaur is full, EATING during eating or SERCH4EATING when predator is nont full and prey hunger is equal zero.
     */
    virtual Dinosaur::behaviourStates eating();

    /**
     * @brief findTheNearestEating - dinosaur look for victim
     * @return SERCH4EATING, when there is no not hidden preys, GO2EATING when is some not hidden prey on the map.
     */
    virtual Dinosaur::behaviourStates findTheNearestEating();

    /**
     * @brief go2eating - dinosaur move to prey to devaur it.
     * @return return SERCH4EATING, when there is no not hidden preys, GO2EATING when is some not hidden prey on the map.
     */
    virtual Dinosaur::behaviourStates go2eating();

    /**
     * @brief findPartner - dinosaur looks for parthner for reproduce
     * @return SERCH4PARTNER when there isn't predator in reproductive age on the map, GO2PARTNER when has found partner
     */
    virtual Dinosaur::behaviourStates findPartner();

    /**
     * @brief reproducing of predators
     * @return REPRODUCING when the partner still exist, and SERCH4PARTNER othervise
     */
    virtual Dinosaur::behaviourStates reproducing();

private:

    const QString picture_ = "dinosaur-brown.png";
};

typedef boost::shared_ptr<Predator> Predator_sharedPtr;
typedef boost::weak_ptr<Predator> Predator_weakPtr;

#endif // PREDATOR_H
