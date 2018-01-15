#ifndef OBJECT_H
#define OBJECT_H

//author: Adam Siwak

#include "coordinates.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Visitor;

/**
 * @brief The Object class (abstract)
 */
class Object {
public:
    /**
     * @brief ~Object destrctor
     */
    virtual ~Object() {}
    int getX() { return position_->getXcoordinate(); }
    int getY() { return position_->getYcoordinate(); }

    virtual void accept(Visitor& v) = 0; // visitor pattern implementation

    Coordinates_sharedPtr position_;

};

typedef boost::shared_ptr<Object> Object_sharedPtr;
typedef boost::weak_ptr<Object> Object_weakPtr;

#endif // OBJECT_H
