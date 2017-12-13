#ifndef PREDATOR_H
#define PREDATOR_H

#include "dinosaur.h"

class Predator : public Dinosaur {
public:
    Predator() : Dinosaur(), attack_(rand()%100), loudness_(rand()%100) {}
    virtual void accept(Visitor &v) const;

private:
    virtual void createGUIElement();
    virtual void analyze_surroundings();

    int attack_;
    int loudness_;

    const QString picture = ":/pictures/dinosaur-brown.png";
};

#endif // PREDATOR_H
