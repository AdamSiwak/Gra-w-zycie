#include "objectgui.h"
#include "QGraphicsItem"

ObjectGUI::ObjectGUI(QString pictureName, const qreal scale)
{
    QPixmap *pixmap = new QPixmap();
    setMySkale(scale);
    pixmap->load(":/pictures/"+pictureName);
    this->setPixmap(*pixmap);
//    if(pixmap->isNull()){
//        qDebug() << "darn";
//    }
//    else{
//        qDebug() << "not null";
//    }
    QGraphicsItem::setScale(scale);

    position_ = new Coordinates();
    position_->setRandomCoordiantes();
    setPos(x()+position_->getXcoordinate(),y()+position_->getYcoordinate());
}

void ObjectGUI::setMySkale(const qreal scale)
{
    scale_=scale;
}
