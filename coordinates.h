#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdlib>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

class Coordinates
{
public:
    Coordinates();
    int getXcoordinate();
    void setXcoordinate(int xCoordinate);
    int getYcoordinate();
    void setYcoordinate(int yCoordinate);

    int getRealXcoordinate(){return xRealCoordinate_;}
    void setRealXcoordinate(int xCoordinate){xRealCoordinate_ = xCoordinate;}
    int getRealYcoordinate(){return yRealCoordinate_;}
    void setRealYcoordinate(int yCoordinate){yRealCoordinate_ = yCoordinate;}

    void setRandomCoordiantes();

    bool operator==(const Coordinates& right){
        if( x_ == right.x_ && y_ == right.y_) return true;
        else return false;}

    bool operator!=(const Coordinates&right){
        return !(*this==right);
    }

    static const int MAX_X_=1000;
    static const int MAX_Y_=1000;

private:
    int x_;
    int y_;
    int xRealCoordinate_;
    int yRealCoordinate_;
};

typedef boost::shared_ptr<Coordinates> Coordinates_sharedPtr;
typedef boost::weak_ptr<Coordinates> Coordinates_weakPtr;

#endif // COORDINATES_H
