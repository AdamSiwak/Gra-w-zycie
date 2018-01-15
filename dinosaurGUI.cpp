//author: Andrzej Dzwinski, Adam Siwak

#include "dinosaurGUI.h"
#include <QDebug>
#include <QDir>
#include <QKeyEvent>
#include "cloud.h"
#include "sound.h"
#include <QMessageBox>
#include "dinosaur.h"

DinosaurGUI::DinosaurGUI(QString dinoName, const qreal scale, Dinosaur* parent):ObjectGUI(dinoName, scale), parent_(parent){

    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    parent_->position_ = position_;

    setTransformOriginPoint(-50,-50);

    if(dinoName == "dinosaur-brown.png"){
        dinoSound = Sound_sharedPtr(new Sound(PRAY_SOUND));
    }
    else if(dinoName == "dinosaur_green.png"){
        dinoSound = Sound_sharedPtr(new Sound(PREDATOR_SOUND));
    }

    cloud_ = Cloud_sharedPtr(new Cloud("cloud.png",0.3));
    cloud_->setVisible(false);
}

void DinosaurGUI :: keyPressEvent(QKeyEvent *event){
    for(int i=0; i<10; ++i){
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
}


void DinosaurGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
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
        setTransformOriginPoint(-50,-50);;
    }
}

void DinosaurGUI::stepLeft()
{    
    if(position_->getXcoordinate()>-(position_->MAX_X_/2)){
        setPos(x()-STEP_SIZE_,y());
        position_->setXcoordinate(position_->getXcoordinate()-1);
        setTransform(QTransform::fromScale(1, 1));
        setRotation(0);
        setTransformOriginPoint(-50,-50);
    }
}

void DinosaurGUI::stepUp()
{
    if(position_->getYcoordinate()>-(position_->MAX_Y_/2)){
        position_->setYcoordinate(position_->getYcoordinate()-1);
        setPos(x(),y()-STEP_SIZE_);
        setRotation(0);
        setTransformOriginPoint(-50,-50);
    }
}

void DinosaurGUI::stepDown()
{
    if(position_->getYcoordinate()<position_->MAX_Y_/2){
        position_->setYcoordinate(position_->getYcoordinate()+1);
        setPos(x(),y()+STEP_SIZE_);
        setRotation(0);
        setTransformOriginPoint(-50,-50);
    }
}

void DinosaurGUI::beginDrinking()
{
    setTransform(QTransform::fromScale(-1, 1));
    setRotation(-45);
}

void DinosaurGUI::endDrinking()
{
    setRotation(0);
}
