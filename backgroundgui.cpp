#include "backgroundgui.h"

#include <QListView>
#include <QPalette>


BackgroundGUI::BackgroundGUI()
{
    QPixmap *pixmap = new QPixmap();
    pixmap->load(":/pictures/back.JPG");
    this->setPixmap(*pixmap);
    if(pixmap->isNull()){
        qDebug() << "null";
    }
    else{
        qDebug() << "not null";
    }
    setOffset(-300,-300);
    setScale(0.8);


}
