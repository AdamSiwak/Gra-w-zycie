#include "cloud.h"
#include <QPainter>


Cloud::Cloud(QString picture, const qreal scale):ObjectGUI(picture, scale)
{
    pixmap_ = new QPixmap();
    setMySkale(scale);
    pixmap_->load(":/pictures/"+picture);
    QGraphicsItem::setScale(scale);
}

void Cloud::writeText(QString s){

    QPainter painter( pixmap_ );
    painter.setPen( Qt::black );
    painter.setFont(QFont("Times", 40, QFont::Bold));
    QPoint point = QPoint( 100, 200);
    painter.drawText( point, "Age = 2000" );
    this->setPixmap(*pixmap_);
}
