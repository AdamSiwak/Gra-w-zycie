#include "dinosaurGUI.h"
#include <QDebug>
#include <QDir>
#include <QKeyEvent>
#include "sound.h"

DinosaurGUI::DinosaurGUI(QString dinoName, const qreal scale){

//=======
//Dinosaur::Dinosaur(QString dinoName) : age_(0), energy_(100), speed_(rand()%maxSpeed), sightRange_(rand()%maxSightRange), sightAngle_(rand()%maxSightAngle), hunger_(0), thirst_(0) {
//>>>>>>> Stashed changes
    QPixmap *pixmap = new QPixmap();

    setMySkale(scale);
    pixmap->load(":/pictures/"+dinoName);
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

    if(dinoName == "dinosaur-brown.png"){
        dinoSound = new Sound(PRAY_SOUND);
    }
    else if(dinoName == "dinosaur_green.png"){
        dinoSound = new Sound(PREDATOR_SOUND);
    }



}

void DinosaurGUI :: keyPressEvent(QKeyEvent *event){
    if (event -> key() == Qt::Key_Left){
        setPos(x()-10,y());
        setTransform(QTransform::fromScale(1, 1));
        setRotation(0);
    }
    if (event -> key() == Qt::Key_Right){
        setPos(x()+10,y());
        setRotation(0);
        setTransform(QTransform::fromScale(-1, 1));
    }
    if (event -> key() == Qt::Key_Up){
        setPos(x(),y()-10);
        setTransform(QTransform::fromScale(1, 1));
        setRotation(90);

    }
    if (event -> key() == Qt::Key_Down){
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

void DinosaurGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    dinoSound->play();
}
