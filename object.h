#ifndef OBJECT_H
#define OBJECT_H

class Visitor;

class Object {
public:
    virtual ~Object() {}
    int x() { return x_; }
    int y() { return y_; }

    virtual void accept(Visitor& v) = 0; // implementacja wzorca wizytatora

protected:
    int x_;
    int y_;

};

#endif // OBJECT_H
