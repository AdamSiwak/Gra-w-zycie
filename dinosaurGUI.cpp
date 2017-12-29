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
    switch(event -> key()){
        case Qt::Key_Left:
            stepLeft();
            break;
        case Qt::Key_Right:
            stepRight();
            break;
        case Qt::Key_Up:
            stepUp();
            break;
        case Qt::Key_Down:
            stepDown();
            break;
    }
    qDebug()<<"X="<<coordinates_->getXcoordinate()<<", Y="<<coordinates_->getYcoordinate();
}


void DinosaurGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    dinoSound->play();
    dinoSound->setVolume(30);
}

void DinosaurGUI::stepRight()
{
    if(coordinates_->getXcoordinate()<(coordinates_->MAX_X_/2)){
        setPos(x()+STEP_SIZE_,y());
        coordinates_->setXcoordinate(coordinates_->getXcoordinate()+1);
        setRotation(0);
        setTransform(QTransform::fromScale(-1, 1));
    }
}

void DinosaurGUI::stepLeft()
{
    if(coordinates_->getXcoordinate()>-(coordinates_->MAX_X_/2)){
        setPos(x()-STEP_SIZE_,y());
        coordinates_->setXcoordinate(coordinates_->getXcoordinate()-1);
        setTransform(QTransform::fromScale(1, 1));
        setRotation(0);
    }
}

void DinosaurGUI::stepUp()
{
    if(coordinates_->getYcoordinate()>-(coordinates_->MAX_Y_/2)){
        coordinates_->setYcoordinate(coordinates_->getYcoordinate()-1);
        setPos(x(),y()-STEP_SIZE_);
        setTransform(QTransform::fromScale(1, 1));
        setRotation(90);
    }
}

void DinosaurGUI::stepDown()
{
    if(coordinates_->getYcoordinate()<coordinates_->MAX_Y_/2){
        coordinates_->setYcoordinate(coordinates_->getYcoordinate()+1);
        setPos(x(),y()+STEP_SIZE_);
        setTransform(QTransform::fromScale(1, -1));
        setRotation(90);
    }
}
