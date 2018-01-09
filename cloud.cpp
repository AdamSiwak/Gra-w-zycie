#include "cloud.h"
#include <QPainter>


Cloud::Cloud(QString picture, const qreal scale):ObjectGUI(picture, scale)
{
    QPixmap *pixmap = new QPixmap();

    setMySkale(scale);
    pixmap->load(":/pictures/"+picture);


    QPainter painter( pixmap );
    painter.setPen( Qt::black );
    painter.setFont(QFont("Times", 40, QFont::Bold));
    QPoint point = QPoint( 100, 200);
    painter.drawText( point, "Age = 10000" );

    this->setPixmap(*pixmap);

    QGraphicsItem::setScale(scale);

    position_ = new Coordinates();
    position_->setRandomCoordiantes();
    setPos(x()+position_->getXcoordinate(),y()+position_->getYcoordinate());
}
