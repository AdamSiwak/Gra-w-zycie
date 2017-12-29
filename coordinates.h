#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdlib>

class Coordinates
{
public:
    Coordinates();
    int getXcoordinate();
    void setXcoordinate(int xCoordinate);
    int getYcoordinate();
    void setYcoordinate(int yCoordinate);

    void setRandomCoordiantes();

    static const int MAX_X_=50;
    static const int MAX_Y_=50;

    int x_;
    int y_;
    int xRealCoordinate_;
    int yRealCoordinate_;
};

#endif // COORDINATES_H
