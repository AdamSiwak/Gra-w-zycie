#ifndef COORDINATES_H
#define COORDINATES_H


class Coordinates
{
public:
    Coordinates();
    int getXcoordinate();
    void setXcoordinate(int xCoordinate);
    int getYcoordinate();
    void setYcoordinate(int yCoordinate);

    static const int MAX_X_=20;
    static const int MAX_Y_=20;

private:
    int x_;
    int y_;
    int xRealCoordinate_;
    int yRealCoordinate_;
};

#endif // COORDINATES_H
