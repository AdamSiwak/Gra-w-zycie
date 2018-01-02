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
}


void DinosaurGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    dinoSound->play();
    dinoSound->setVolume(30);
}

void DinosaurGUI::stepRight()
{
    if(position_->getXcoordinate()<(position_->MAX_X_/2)){
        setPos(x()+STEP_SIZE_,y());
        position_->setXcoordinate(position_->getXcoordinate()+1);
        setRotation(0);
        setTransform(QTransform::fromScale(-1, 1));
    }
}

void DinosaurGUI::stepLeft()
{    
    if(position_->getXcoordinate()>-(position_->MAX_X_/2)){
        setPos(x()-STEP_SIZE_,y());
        position_->setXcoordinate(position_->getXcoordinate()-1);
        setTransform(QTransform::fromScale(1, 1));
        setRotation(0);
    }
}

void DinosaurGUI::stepUp()
{
    if(position_->getYcoordinate()>-(position_->MAX_Y_/2)){
        position_->setYcoordinate(position_->getYcoordinate()-1);
        setPos(x(),y()-STEP_SIZE_);
        //setTransform(QTransform::fromScale(1, 1));
        //setRotation(90);
        qDebug()<<"X="<<position_->getXcoordinate()<<", Y="<<position_->getYcoordinate();
    }
}

void DinosaurGUI::stepDown()
{
    if(position_->getYcoordinate()<position_->MAX_Y_/2){
        position_->setYcoordinate(position_->getYcoordinate()+1);
        setPos(x(),y()+STEP_SIZE_);
        //setTransform(QTransform::fromScale(1, -1));
        //setRotation(90);
    }
}
