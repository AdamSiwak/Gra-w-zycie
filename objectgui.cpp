#include "objectgui.h"
#include "QGraphicsItem"
#include <QPainter>
#include <QPen>
#include <QFont>

ObjectGUI::ObjectGUI(QString pictureName, const qreal scale)
{
    QPixmap *pixmap = new QPixmap();



    setMySkale(scale);
    pixmap->load(":/pictures/"+pictureName);


//        QPainter painter( pixmap );
//      painter.setPen( Qt::black );
//      painter.setFont(QFont("Times", 20, QFont::Normal));
//      QPoint point = QPoint( 10, 20 );
//      painter.drawText( point, "Age = 10000" );

//    QImage tmpImage = pixmap->toImage();
//    QPainter p(&tmpImage);
//    p.setPen(QPen(Qt::red));
//    p.setFont(QFont("Times", 12, QFont::Bold));
//    p.drawText(100,100, "Text");
//    this->setPixmap(QPixmap::fromImage(tmpImage));


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
