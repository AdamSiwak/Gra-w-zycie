#include <QTime>
#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QLabel>
#include <QDebug>
#include <QMediaPlayer>

#include "dinosaurGUI.h"
#include "sound.h"
#include "backgroundgui.h"
#include "map.h"
#include "dinosaur.h"
#include "prey.h"

Map* Map::instance_ = 0;

Map::Map(){
    qDebug()<<"siema";

    QGraphicsScene * scene = new QGraphicsScene();

    BackgroundGUI back;
    scene->setBackgroundBrush(back);

    DinosaurGUI* dino2 = new DinosaurGUI("dinosaur_green.png",0.15);
    scene->addItem(dino2);

    //Prey dinoo = new Prey();
  //  Map::getInstance();

    DinosaurGUI* dino = new DinosaurGUI("dinosaur-brown.png", 0.15);
    scene->addItem(dino);

    QGraphicsView * view = new QGraphicsView(scene);
    view->showMaximized();
    view->show();

    Sound* background = new Sound(BACKGROUND);
    background->play();
}

void Map::add_new_object(Object* object){
    //object->position_->setRandomCoordinates();
    objects_.push_back(object);
}

void Map::add_new_dinosaur(Dinosaur* dinosaur) {
   // dinosaur->position_->setRandomCoordinates();
    dinosaurs_.push_back(dinosaur);
}

void Map::createPopulation(int size) {
    for (int i = 0; i < size; ++i) {
        add_new_dinosaur(new Predator);
    }
//    for (int i = 0; i < size; ++i) {
//        add_new_dinosaur(new Prey);
//    }
}

