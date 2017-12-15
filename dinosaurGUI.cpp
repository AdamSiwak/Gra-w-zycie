#include "dinosaurGUI.h"
#include <QDebug>
#include <QDir>
#include <QKeyEvent>
#include "sound.h"

DinosaurGUI::DinosaurGUI(QString dinoName, const qreal scale):ObjectGUI(dinoName, scale){


    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    if(dinoName == "dinosaur-brown.png"){
        dinoSound = new Sound(PRAY_SOUND);
    }
    else if(dinoName == "dinosaur_green.png"){
        dinoSound = new Sound(PREDATOR_SOUND);
    }
    //setTransformOriginPoint();

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


void DinosaurGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    dinoSound->play();
    dinoSound->setVolume(30);
}
