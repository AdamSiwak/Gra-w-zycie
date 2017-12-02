#include "dinosaur.h"
#include <QDebug>
#include <QKeyEvent>

Dinosaur::Dinosaur()
{

}

Dinosaur::Dinosaur(QString dinoName){
    QPixmap *pixmap = new QPixmap();
    pixmap->load(":/"+dinoName);
    this->setPixmap(*pixmap);
    if(pixmap->isNull()){
        qDebug() << "darn";
    }
    else{
        qDebug() << "not null";
    }
}

void Dinosaur :: keyPressEvent(QKeyEvent *event){
qDebug() << "key";
    if (event -> key() == Qt::Key_Left){
        qDebug() << "Left";
        setPos(x()-10,y());
    }
    if (event -> key() == Qt::Key_Right){
        qDebug() << "Right";
        setPos(x()+10,y());
    }
    if (event -> key() == Qt::Key_Up){
        qDebug() << "Up";
        setPos(x(),y()-10);
    }
    if (event -> key() == Qt::Key_Down){
        qDebug() << "Down";
        setPos(x(),y()+10);
    }
}
