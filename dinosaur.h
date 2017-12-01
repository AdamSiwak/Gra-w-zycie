#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Dinosaur : public QGraphicsPixmapItem
{
public:
    Dinosaur();
    Dinosaur(QString);
    void keyPressEvent(QKeyEvent *event);
private:

};

#endif // DINOSAUR_H
