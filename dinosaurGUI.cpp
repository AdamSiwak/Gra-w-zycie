#include "dinosaurGUI.h"
#include <QDebug>
#include <QDir>
#include <QKeyEvent>

//<<<<<<< Updated upstream
DinosaurGUI::DinosaurGUI()
{

}

DinosaurGUI::DinosaurGUI(QString dinoName, const qreal scale){

//=======
//Dinosaur::Dinosaur(QString dinoName) : age_(0), energy_(100), speed_(rand()%maxSpeed), sightRange_(rand()%maxSightRange), sightAngle_(rand()%maxSightAngle), hunger_(0), thirst_(0) {
//>>>>>>> Stashed changes
    QPixmap *pixmap = new QPixmap();

    setMySkale(scale);
//    pixmap->load("../pictures/"+dinoName);
    pixmap->load(":/"+dinoName);
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

void DinosaurGUI :: keyPressEvent(QKeyEvent *event){
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

qreal DinosaurGUI::mySkale() const
{
    return scale_;
}

void DinosaurGUI::setMySkale(const qreal scale)
{
    scale_ = scale;
}
