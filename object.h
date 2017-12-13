#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
    virtual ~Object() {}
    int x() { return x_; }
    int y() { return y_; }

protected:
    int x_;
    int y_;

};

#endif // OBJECT_H
