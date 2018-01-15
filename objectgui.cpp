//author: Andrzej Dzwinski, Adam Siwak

#include "objectgui.h"
#include "QGraphicsItem"
#include <QPainter>
#include <QPen>
#include <QFont>

ObjectGUI::ObjectGUI(QString pictureName, const qreal scale)
{
    pixmap_ = QPixmap_sharedPtr(new QPixmap());

    setMySkale(scale);
    pixmap_->load(":/pictures/"+pictureName);

    this->setPixmap(*pixmap_);

    QGraphicsItem::setScale(scale);

    position_ = Coordinates_sharedPtr(new Coordinates());
    position_->setRandomCoordiantes();
    setPos(x()+position_->getXcoordinate(),y()+position_->getYcoordinate());

}

void ObjectGUI::setMySkale(const qreal scale)
{
    scale_=scale;
}
