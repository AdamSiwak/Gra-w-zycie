#include "dinosaur.h"
#include <QDebug>

Dinosaur::Dinosaur()
{

}

Dinosaur::Dinosaur(QString dinoName){
    QPixmap *pixmap = new QPixmap();
    pixmap->load(dinoName);
    this->dino_ = new QGraphicsPixmapItem(*pixmap);
    qDebug() << "Dino Created";
}

QGraphicsPixmapItem* Dinosaur::getDino(){
    return this->dino_;
}
