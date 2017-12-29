#ifndef OBJECT_H
#define OBJECT_H

#include "coordinates.h"

class Visitor;

class Object {
public:
    virtual ~Object() {}
    int getX() { return position_->x_; }
    int getY() { return position_->y_; }

    virtual void accept(Visitor& v) = 0; // implementacja wzorca wizytatora

    Coordinates* position_;

};

#endif // OBJECT_H
