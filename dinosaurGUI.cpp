#include "dinosaurGUI.h"
#include <QDebug>
#include <QDir>
#include <QKeyEvent>
#include "sound.h"

DinosaurGUI::DinosaurGUI(QString dinoName, const qreal scale):ObjectGUI(dinoName, scale){


    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    setTransformOriginPoint(-50,-50);

    if(dinoName == "dinosaur-brown.png"){
        dinoSound = new Sound(PRAY_SOUND);
    }
    else if(dinoName == "dinosaur_green.png"){
        dinoSound = new Sound(PREDATOR_SOUND);
    }
    coordinates_ = new Coordinates();
}

void DinosaurGUI :: keyPressEvent(QKeyEvent *event){
    if (event -> key() == Qt::Key_Left){
        if(coordinates_->getXcoordinate()>-(coordinates_->MAX_X_/2)){
            setPos(x()-5,y());
            coordinates_->setXcoordinate(coordinates_->getXcoordinate()-1);
            setTransform(QTransform::fromScale(1, 1));
            setRotation(0);
        }
    }
    if (event -> key() == Qt::Key_Right){
        if(coordinates_->getXcoordinate()<(coordinates_->MAX_X_/2)){
            setPos(x()+5,y());
            coordinates_->setXcoordinate(coordinates_->getXcoordinate()+1);
            setRotation(0);
            setTransform(QTransform::fromScale(-1, 1));
        }
    }
    if (event -> key() == Qt::Key_Up){
        if(coordinates_->getYcoordinate()>-(coordinates_->MAX_Y_/2)){
            coordinates_->setYcoordinate(coordinates_->getYcoordinate()-1);
            setPos(x(),y()-5);
            setTransform(QTransform::fromScale(1, 1));
            setRotation(90);
        }

    }
    if (event -> key() == Qt::Key_Down){
        if(coordinates_->getYcoordinate()<coordinates_->MAX_Y_/2){
            coordinates_->setYcoordinate(coordinates_->getYcoordinate()+1);
            setPos(x(),y()+5);
            setTransform(QTransform::fromScale(1, -1));
            setRotation(90);
        }
    }
    qDebug()<<"X="<<coordinates_->getXcoordinate()<<", Y="<<coordinates_->getYcoordinate();
}


void DinosaurGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    dinoSound->play();
    dinoSound->setVolume(30);
}
