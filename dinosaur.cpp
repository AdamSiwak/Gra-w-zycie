#include "dinosaur.h"
#include <QDebug>
#include <QDir>
#include <QKeyEvent>

Dinosaur::Dinosaur()
{

}

Dinosaur::Dinosaur(QString dinoName, const qreal scale){

    QPixmap *pixmap = new QPixmap();

    setMySkale(scale);
    pixmap->load("../pictures/"+dinoName);
//    pixmap->load(":/pictures/dinosaur-brown.png");
    this->setPixmap(*pixmap);
    if(pixmap->isNull()){
        qDebug() << "darn";
    }
    else{
        qDebug() << "not null";
    }

    QGraphicsItem::setScale(scale);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

}

void Dinosaur :: keyPressEvent(QKeyEvent *event){
    if (event -> key() == Qt::Key_Left){
        qDebug() << "Left";
        setPos(x()-10,y());
        setTransform(QTransform::fromScale(1, 1));
        setRotation(0);
    }
    if (event -> key() == Qt::Key_Right){
        qDebug() << "Right";
        setPos(x()+10,y());
        setRotation(0);
        setTransform(QTransform::fromScale(-1, 1));
    }
    if (event -> key() == Qt::Key_Up){
        qDebug() << "Up";
        setPos(x(),y()-10);
        setTransform(QTransform::fromScale(1, 1));
        setRotation(90);

    }
    if (event -> key() == Qt::Key_Down){
        qDebug() << "Down";
        setPos(x(),y()+10);
        setTransform(QTransform::fromScale(1, -1));
        setRotation(90);
    }
}

qreal Dinosaur::mySkale() const
{
    return scale_;
}

void Dinosaur::setMySkale(const qreal scale)
{
    scale_ = scale;
}
