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
    Dinosaur(QString dinoName, const qreal skale);
    void keyPressEvent(QKeyEvent *event);
    qreal mySkale() const;
    void setMySkale(const qreal scale);

private:
    qreal scale_;
};

#endif // DINOSAUR_H
