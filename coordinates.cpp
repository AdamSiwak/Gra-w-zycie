#include "coordinates.h"

Coordinates::Coordinates()
{
    setXcoordinate(0);
    setYcoordinate(0);
}

int Coordinates::getXcoordinate()
{
    x_=xRealCoordinate_-MAX_X_/2;
    return x_;
}

void Coordinates::setXcoordinate(int xCoordinate)
{
    xRealCoordinate_=xCoordinate+MAX_X_/2;
    x_=xCoordinate;
}

int Coordinates::getYcoordinate()
{
    y_=yRealCoordinate_-MAX_Y_/2;
    return y_;
}

void Coordinates::setYcoordinate(int yCoordinate)
{
    yRealCoordinate_=yCoordinate+MAX_Y_/2;
    y_=yCoordinate;
}

void Coordinates::setRandomCoordiantes()
{
    setXcoordinate((rand()%MAX_X_)-MAX_X_/2);
    setYcoordinate((rand()%MAX_Y_)-MAX_Y_/2);
}

