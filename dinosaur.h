#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Dinosaur
{
public:
    Dinosaur();
    Dinosaur(QString);
    QGraphicsPixmapItem* getDino();
private:

    QGraphicsPixmapItem *dino_;
};

#endif // DINOSAUR_H
