//author: Andrzej Dzwinski

#include "cloud.h"
#include <QPainter>


Cloud::Cloud(QString picture, const qreal scale):ObjectGUI(picture, scale)
{
    pixmap_ = QPixmap_sharedPtr(new QPixmap());
    setMySkale(scale);
    pixmap_->load(":/pictures/"+picture);
    QGraphicsItem::setScale(scale);

    setTransformOriginPoint(-300,-350);

}

void Cloud::writeText(QString s){

    int j=0;

    QString strings[5];

    for(QChar& c : s){
        if(c != ','){
            strings[j]+=c;
        }
        else{
            ++j;
        }
    }

    QPainter painter(&(*pixmap_));
    painter.setPen( Qt::black );
    painter.setFont(QFont("Times", 40, QFont::Bold));

    painter.eraseRect(120,100,460,250);

    painter.drawText( 100,150, strings[0]);
    painter.drawText( 100,200, strings[1]);
    painter.drawText( 100,250, strings[2]);
    painter.drawText( 100,300, strings[3]);
    painter.drawText( 100,350, strings[4]);
    this->setPixmap(*pixmap_);
}
